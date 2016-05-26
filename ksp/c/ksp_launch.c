#include <stdio.h>
#include <math.h>

/* http://wiki.kerbalspaceprogram.com/wiki/Tutorial:Advanced_Rocket_Design */

/* Also, high school physics (thanks Mr. Brennen) */

#define PI 3.14159265358979323846264338327

static double sin_degrees(double degrees) {

	return sin(degrees*PI/180);
}

static double cos_degrees(double degrees) {
	return cos(degrees*PI/180);
}

static double vector_magnitude(double a,double b) {
	return sqrt(a*a+b*b);
}

static void home(void) {
	printf("%c[2J%c[1;1H",27,27);
}

static void htabvtab(int x,int y) {
	printf("%c[%d;%dH",27,y,x);
}

#define KERBIN_RADIUS	600000.0

int autopilot(double fuel_left, double altitude, double *angle) {

	if (fuel_left>25.0) {
		*angle=45.0;
		return 1;
	}

	if (altitude>KERBIN_RADIUS+40000) {
		*angle=100.0; /* actually want tanegent to surface */
		return 1;
	}

	return 0;

}

int main(int argc, char **argv) {

	FILE *logfile;

	double angle=0;

	double capsule_mass=1.0;

//	double engines=3;
	double engine_isp=270.0;	/* s */
//	double engine_mass=(1.5)*engines;		/* tons */
//	double engine_thrust=(168.0)*engines;	/* kN */
//	double fuel_flow_rate;

//	double tanks=6;
//	double tank_mass=(0.5)*tanks;		/* tons */
//	double fuel_mass=(4.0)*tanks;		/* tons */
//	double total_fuel=fuel_mass;
	double fuel_left=100.0;

	double gravity=-9.8;		/* m/s^2 */
	double gravity_x=0.0;
	double gravity_y=-9.8;
	double gravity_angle=0.0;
	/* Kerbin radius = 600km */


	double rocket_velocity=0.0;
	double rocket_velocity_x=0.0;	/* m/s */
	double rocket_velocity_y=0.0;	/* m/s */

	double rocket_acceleration_x=0.0;	/* m/s^2 */
	double rocket_acceleration_y=0.0;	/* m/s^2 */

	double rocket_x=0;
	double rocket_y=KERBIN_RADIUS+10;
	double rocket_altitude=KERBIN_RADIUS;	/* m */


	double v0_x,v0_y;

	double time=0.0;		/* s */

	int stage=2;

	int log_step=0;

	char input;

	int thrusting=1,i,j;

	int stages=3;
	int engines[3],stacks[3],tanks[3];
	double stage_empty_mass[3],stage_full_mass[3],total_mass[3],thrust[3];
	double fuel_mass[3],stage_fuel_total[3];
	double deltav[3],twr[3],fuel_flow[3];

	logfile=fopen("log.jgr","w");

	engines[0]=1; stacks[0]=1; tanks[0]=1;
	engines[1]=2; stacks[1]=2; tanks[1]=1;
	engines[2]=3; stacks[2]=3; tanks[2]=1;

	for(i=0;i<stages;i++) {
		stage_empty_mass[i]=(engines[i]*1.5)+(stacks[i]*tanks[i]*0.5)+capsule_mass;/* tons */
		fuel_mass[i]=(stacks[i]*tanks[i]*4.0);
		stage_fuel_total[i]=fuel_mass[i];
		stage_full_mass[i]=stage_empty_mass[i]+fuel_mass[i];

		total_mass[i]=0.0;
		for(j=i;j>=0;j--) {
			total_mass[i]+=stage_full_mass[j];
		}
		thrust[i]=engines[i]*168.0;	/* kN */
		deltav[i]=engine_isp*-gravity*log(total_mass[i]/(total_mass[i]-fuel_mass[i]));
		twr[i]=thrust[i]/(total_mass[i]*-gravity);
		fuel_flow[i]=(thrust[i])/(engine_isp*-gravity);
		printf("Stage %d\n",i+1);
		printf("\ttanks=%d engines=%d\n",stacks[i]*tanks[i],engines[i]);
		printf("\tstage mass=%lf total_mass=%lf\n",stage_full_mass[i],
			total_mass[i]);
		printf("\tdeltaV=%lf\n",deltav[i]);
		printf("\tTWR=%lf\n",twr[i]);

	}

//	printf("Fuel flow rate=%lf, time=%lfs\n",
//		fuel_flow_rate,fuel_mass/fuel_flow_rate);

	scanf("%c",&input);

	while(1) {

		/* 4010 */
		fuel_left=fuel_mass[stage]*100.0/stage_fuel_total[stage];

		thrusting=1;//autopilot(fuel_left, rocket_altitude,&angle);

		if (thrusting) {
			if (fuel_mass[stage]<0.1) {
				fuel_mass[stage]=0.0;
				rocket_acceleration_x=0;
				rocket_acceleration_y=0;

			}
			else {
				rocket_acceleration_x=(thrust[stage]/total_mass[stage])*sin_degrees(angle);
				rocket_acceleration_y=(thrust[stage]/total_mass[stage])*cos_degrees(angle);

				fuel_mass[stage]=fuel_mass[stage]-fuel_flow[stage];
				total_mass[stage]=total_mass[stage]-fuel_flow[stage];
			}
		}
		else {
			rocket_acceleration_x=0.0;
			rocket_acceleration_y=0.0;
		}

		/* 4060 */
		gravity_angle=atan(rocket_x/rocket_y);
		if (rocket_y<0) gravity_angle+=PI;

		/* 4070 */
		gravity_y=cos(gravity_angle)*gravity;
		gravity_x=sin(gravity_angle)*gravity;

		/* 4080 */
		rocket_acceleration_y+=gravity_y;
		rocket_acceleration_x+=gravity_x;

		/* v=v0+at */
		v0_x=rocket_velocity_x;
		v0_y=rocket_velocity_y;

		rocket_velocity_y=v0_y+rocket_acceleration_y*1.0;
		rocket_velocity_x=v0_x+rocket_acceleration_x*1.0;
		rocket_velocity=vector_magnitude(rocket_velocity_x,rocket_velocity_y),

		/* deltaX=1/2 (v+v0)t */
		/* could also use deltax=v0t+(1/2)*a*t*t */
		rocket_y=rocket_y+0.5*(v0_y+rocket_velocity_y)*1.0;
		rocket_x=rocket_x+0.5*(v0_x+rocket_velocity_x)*1.0;

		rocket_altitude=vector_magnitude(rocket_x,rocket_y);

		/* 5020 */

		if (rocket_altitude<KERBIN_RADIUS) {
			if (rocket_velocity<20.0) {
				printf("LANDED!\n");
			}
			else {
				printf("CRASHED!\n");
			}
			break;
		}

		/* 5030 */
		/* Adjust gravity */
		gravity=-9.8/(
			((rocket_altitude)/KERBIN_RADIUS)*
			((rocket_altitude)/KERBIN_RADIUS));

		home();

		htabvtab(1,21);

		printf("Time: %lf\n",time);
		printf("ALT: %lf km\tg=%lf\n",(rocket_altitude-KERBIN_RADIUS)/1000.0,
				gravity);
		printf("VEL: %lf m/s\tStage: %d\n",
			rocket_velocity,
			stage);
		printf("ACCEL: %lf g\tFuel: %lf%%",
			vector_magnitude(rocket_acceleration_x,rocket_acceleration_y)/9.8,
			fuel_left);

		htabvtab(30,21);
		printf("ZURGTROYD");

		htabvtab(30,20);
		if ((angle>90) && (angle<270)) printf("SCREAM");
		else if (rocket_velocity_y>100) printf("SMILE");
		else if (rocket_acceleration_y<0) printf("FROWN");
		else printf("NEUTRAL");

		htabvtab(20,13);
		printf("grav angle=%lf\n",gravity_angle*180.0/PI);

		htabvtab(20,12);
		printf("x=%lf y=%lf\n",rocket_x,rocket_y);

		htabvtab(20,11);
		printf("vx=%lf vy=%lf ax=%lf ay=%lf\n",
			rocket_velocity_x,rocket_velocity_y,
			rocket_acceleration_x,rocket_acceleration_y);
		htabvtab(20,10);
		printf("angle=%lf\n",angle);

		htabvtab(20,9);
		if (angle<22.5) printf("^");
		else if (angle<67.5) printf("/");
		else if (angle<112.5) printf(">");
		else if (angle<157.5) printf("\\");
		else if (angle<205.5) printf("V");
		else if (angle<250.5) printf("/");
		else if (angle<295.5) printf("<");
		else if (angle<340.5) printf("\\");
		else printf("^");

		scanf("%c",&input);
		if (input==' ') {
			if (stage>0) stage--;
		}
		if (input=='d') {
			angle+=45.0;
			if (angle>=360) angle=0.0;
		}
		if (input=='a') {
			angle-=45.0;
			if (angle<0.0) angle+=360.0;
		}

		time+=1.0;

		if (log_step==0) {
			if (logfile) {
				fprintf(logfile,"%lf %lf\n",rocket_x/1000.0,rocket_y/1000.0);
			}
		}
		log_step++;
		if (log_step>10) {
			log_step=0;
		}
	}

	if (logfile) fclose(logfile);

	return 0;
}

/* Notes */

/* Once altitude above 100m stop drawing ground */
/* Once above 20k no more drag? */
/* Once above 2100m/s sideways, orbit? */
/* Once above 40k draw stars? */
/* Kerbal neutral 0-1G, smiles 1-2G, frowns > 2G or -velocity? */

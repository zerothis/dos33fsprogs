' Entropy
' by Dave McKellar of Toronto
' Two-line BASIC program
' From Beagle Brother's Apple Mechanic Disk

1  ROT=0:FOR I=1 TO 15:READ A,B:POKE A,B:NEXT:DATA 232,252,233,29,7676,1,7678,4,7679,0,7680,18,7681,63,7682,36,7683,36,7684,45,7685,45,7686,54,7687,54,7688,63,7689,0
2  FOR I=1 TO 99:HGR2:FOR E=.08 TO .15 STEP .01:FOR Y=4 TO 189 STEP 6:FOR X=4 TO 278 STEP 6:SCALE=(RND(1)< E)*RND(1)*E*20+1:XDRAW 1 AT X,Y:NEXT:NEXT:NEXT:NEXT

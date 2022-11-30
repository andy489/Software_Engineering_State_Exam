#!/bin/bash

br=1
br=`expr $br \* $2`
a=$3
set ab bc cd de
shift
while true
do echo $*
	for j
	do if test $# -lt $br
		then br=` expr $br / 2`
			echo $br $j >> file
		else br=`expr $br + $a`
			echo $br $j >>file
		fi
	done
break
done
read a1 a2
while cat file | grep $a1
do echo $a $a2
	wc -l file
	tail -5c file
	exit
	echo FIN
done
echo $a $a1
wc -c file
tail -2l file

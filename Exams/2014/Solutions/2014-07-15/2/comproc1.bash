#!/bin/bash
count=1
for i in 5 1 4 2
do for j
	do if test $i -ge $#
		then count=` expr $count \* $i`
			echo $count $j >> f1
		else while true
			do echo $*
				break 3
			done
		fi
	done
done
read k1 k2
while cat f1 | grep $k2
do set $k1 $count
	echo $1 $2 $3
	shift
	echo $2
	echo $1 $i
	exit
done
echo FIN


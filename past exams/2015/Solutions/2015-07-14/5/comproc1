#!/bin/bash

br=0
br=`expr $br + $2`
set 3 5 7
shift
for j
do for var
	do if test $br -lt $2
		then br=`expr $br \* $2`
			echo $br $var $j >> file
		else br=`expr $br - $2`
			echo $var $br $j >> file
		fi
	done
	echo $*
	break
done
read a1 a2
until cat file | grep $a1
do echo $#
	grep $1 file
	exit
	echo END
done
echo $3
wc -l < file
echo FINAL

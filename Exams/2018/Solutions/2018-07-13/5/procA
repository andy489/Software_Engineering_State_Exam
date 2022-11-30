#!/bin/bash

var=3
for i
do for  j in  `cat f1`
	do if test $j  -lt  $#
		then echo $i  $j
			var=`expr $var  \*  $j`
				echo  $var  $i  >  f2
		else var=`expr  $var  +  $j`
				echo  $var  $j  >>  f2
		fi
	done
break
done
read  s1 s2
until  grep  $s1  f2
do  set  $s2  $var  $#
		wc -c  f2
		shift
		echo  $1 $2
		exit
		cat f2
done
set  `head  -2l  f2`
echo  $*
shift
echo $2

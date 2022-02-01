#!/bin/bash

for (( i=0; i<10; i++ ))
do
	ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
	LN=$(./push_swap $ARG | wc -l)
	if [ $LN -gt 700 ]
	then
		echo "KoooO"
	fi
	valgrind ./push_swap $ARG | ./checker_linux $ARG
done
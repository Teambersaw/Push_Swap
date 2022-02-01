#!/bin/bash

for (( i=0; i<100; i++ ))
do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	LN=$(./push_swap $ARG | wc -l)
	if [ $LN -gt 5500 ]
	then
		echo "KoooO"
		echo $ARG
	fi
	./push_swap $ARG | ./checker_linux $ARG
done
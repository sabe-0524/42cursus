#!/bin/bash
NBR_COUNT=500
##
NBR="1 2"
RES=OK
while [ "$(./push_swap $NBR | ./checker_linux $NBR)" = "OK" ]
do
	NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)
	./push_swap $NBR | wc -l
	./push_swap $NBR | ./checker_linux $NBR
done

CMD=$( ./push_swap $NBR)
echo "NBR [$NBR]"
#echo "Operations: $CMD"

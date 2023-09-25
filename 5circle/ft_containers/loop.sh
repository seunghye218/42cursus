#!/bin/bash

i=0;
while [ $i -le 1000 ]; do
	./$1 > /dev/null
	((i++))
done;


#!/bin/bash

make fclean

if [ $1 = "-a" ]
then
	./my_tester.sh
	./my_tester.sh -v
	./my_tester.sh -st
	./my_tester.sh -m
	./my_tester.sh -s
	exit
fi

if [ -z $1 ]
then
	FT_TEST=ft_main_test
	STD_TEST=std_main_test

	make $FT_TEST
	make $STD_TEST

	seed=42

	echo
	echo Main
	echo -n "====== ft ======"
	time ./$FT_TEST seed > log_ft
	echo
	echo -n "====== std ======"
	time ./$STD_TEST seed > log_std
	diff log_ft log_std
	exit
fi

if [ $1 = -v ]
then
	FT_TEST=ft_vector_test
	STD_TEST=std_vector_test
	CONTAINER=Vector
elif [ $1 = -st ]
then
	FT_TEST=ft_stack_test
	STD_TEST=std_stack_test
	CONTAINER=Stack
elif [ $1 = -m ]
then
	FT_TEST=ft_map_test
	STD_TEST=std_map_test
	CONTAINER=Map
elif [ $1 = -s ]
then
	FT_TEST=ft_set_test
	STD_TEST=std_set_test
	CONTAINER=Set
else
	echo "====== Usage ======"
	echo ./my_tester.sh   =\> Main
	echo ./my_tester.sh -v =\> Vector 
	echo ./my_tester.sh -st =\> Stack
	echo ./my_tester.sh -m =\> Map
	echo ./my_tester.sh -s =\> Set
	echo ./my_tester.sh -a =\> All

	exit
fi

make $FT_TEST
make $STD_TEST

echo
echo $CONTAINER
echo -n "====== ft ======"
time ./loop.sh $FT_TEST
echo
echo -n "====== std ======"
time ./loop.sh ./$STD_TEST

./$FT_TEST > log_ft
./$STD_TEST > log_std
diff log_ft log_std

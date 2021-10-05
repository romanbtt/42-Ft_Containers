#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessArithmetic()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintRandomAccessArithmeticMenu
}

function RandomAccessAllArithmetic()
{
	echo -e $BWhite "Test Increment" $Color_Off
	$ft "21311"
	$std "21311"
	CompareFiles
	echo -e $BWhite "Test Decrement" $Color_Off
	$ft "21321"
	$std "21321"
	CompareFiles
	echo -e $BWhite "Test Addition" $Color_Off
	$ft "21331"
	$std "21331"
	CompareFiles
	echo -e $BWhite "Test Substraction" $Color_Off
	$ft "21341"
	$std "21341"
	CompareFiles
	echo -e $BWhite "Test Compound operators" $Color_Off
	$ft "21351"
	$std "21351"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintRandomAccessArithmeticMenu
	fi
}

function PrintRandomAccessArithmeticMenu()
{
	echo -e $BPurple --- Random Access Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Incrementation $Color_Off
	echo -e $BCyan 2 $BWhite - Decremention $Color_Off
	echo -e $BCyan 3 $BWhite - Addition $Color_Off
	echo -e $BCyan 4 $BWhite - Substraction $Color_Off
	echo -e $BCyan 5 $BWhite - Compound operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function RandomAccessArithmeticMenu()
{
	clear
	PrintRandomAccessArithmeticMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessArithmetic "Test Incrementation" "21310"
		elif [[ $input == "2" ]]
		then
			RandomAccessArithmetic "Test Decremention" "21320"
		elif [[ $input == "3" ]]
		then
			RandomAccessArithmetic "Test Addition" "21330"
		elif [[ $input == "4" ]]
		then
			RandomAccessArithmetic "Test Substraction" "21340"
		elif [[ $input == "5" ]]
		then
			RandomAccessArithmetic "Test Compound operators" "21350"
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessAllArithmetic '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			RandomAccessMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintRandomAccessArithmeticMenu
		fi
	done
}

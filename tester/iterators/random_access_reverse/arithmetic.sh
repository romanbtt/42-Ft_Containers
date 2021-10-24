#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessReverseArithmetic()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintRandomAccessReverseArithmeticMenu
}

function RandomAccessReverseAllArithmetic()
{
	echo -e $BWhite "Test Increment" $Color_Off
	$ft "22311"
	$std "22311"
	CompareFiles
	echo -e $BWhite "Test Decrement" $Color_Off
	$ft "22321"
	$std "22321"
	CompareFiles
	echo -e $BWhite "Test Addition" $Color_Off
	$ft "22331"
	$std "22331"
	CompareFiles
	echo -e $BWhite "Test Substraction" $Color_Off
	$ft "22341"
	$std "22341"
	CompareFiles
	echo -e $BWhite "Test Compound operators" $Color_Off
	$ft "22351"
	$std "22351"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintRandomAccessReverseArithmeticMenu
	fi
}

function PrintRandomAccessReverseArithmeticMenu()
{
	echo -e $BPurple --- Random Access Reverse Arithmetic menu --- $Color_Off
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

function RandomAccessReverseArithmeticMenu()
{
	clear
	PrintRandomAccessReverseArithmeticMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessReverseArithmetic "Test Incrementation" "22310"
		elif [[ $input == "2" ]]
		then
			RandomAccessReverseArithmetic "Test Decremention" "22320"
		elif [[ $input == "3" ]]
		then
			RandomAccessReverseArithmetic "Test Addition" "22330"
		elif [[ $input == "4" ]]
		then
			RandomAccessReverseArithmetic "Test Substraction" "22340"
		elif [[ $input == "5" ]]
		then
			RandomAccessReverseArithmetic "Test Compound operators" "22350"
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessReverseAllArithmetic '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			RandomAccessReverseMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintRandomAccessReverseArithmeticMenu
		fi
	done
}

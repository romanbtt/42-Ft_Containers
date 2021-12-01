#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessReverseArithmetic()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std $2
	echo
	CompareFiles
	PrintRandomAccessReverseArithmeticMenu
}

function RandomAccessReverseAllArithmetic()
{
	echo -e $BWhite "Test Reverse Access Random Increment" $Color_Off
	Execute $ft "22311"
	Execute $std "22311"
	echo
	CompareFiles
	echo -e $BWhite "Test Reverse Access Random Decrement" $Color_Off
	Execute $ft "22321"
	Execute $std "22321"
	echo
	CompareFiles
	echo -e $BWhite "Test Reverse Access Random Addition" $Color_Off
	Execute $ft "22331"
	Execute $std "22331"
	echo
	CompareFiles
	echo -e $BWhite "Test Reverse Access Random Substraction" $Color_Off
	Execute $ft "22341"
	Execute $std "22341"
	echo
	CompareFiles
	echo -e $BWhite "Test Reverse Access Random Compound operators" $Color_Off
	Execute $ft "22351"
	Execute $std "22351"
	echo
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
			RandomAccessReverseArithmetic "Test Reverse Access Random Incrementation" "22310"
		elif [[ $input == "2" ]]
		then
			RandomAccessReverseArithmetic "Test Reverse Access Random Decremention" "22320"
		elif [[ $input == "3" ]]
		then
			RandomAccessReverseArithmetic "Test Reverse Access Random Addition" "22330"
		elif [[ $input == "4" ]]
		then
			RandomAccessReverseArithmetic "Test Reverse Access Random Substraction" "22340"
		elif [[ $input == "5" ]]
		then
			RandomAccessReverseArithmetic "Test Reverse Access Random Compound operators" "22350"
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

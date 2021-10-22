#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessReverseConstructors()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintRandomAccessReverseConstructorsMenu
}

function RandomAccessReverseAllConstructors()
{
	echo -e $BWhite "Test Default constructor" $Color_Off
	$ft "22111"
	$std "22111"
	CompareFiles
	echo -e $BWhite "Test Copy constructor" $Color_Off
	$ft "22121"
	$std "22121"
	CompareFiles
	echo -e $BWhite "Test Operator Equal" $Color_Off
	$ft "22131"
	$std "22131"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintRandomAccessReverseConstructorsMenu
	fi
}

function PrintRandomAccessReverseConstructorsMenu()
{
	echo -e $BPurple --- Random Access Reverse Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function RandomAccessReverseConstructorsMenu()
{
	clear
	PrintRandomAccessReverseConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessReverseConstructors "Test Default constructor" "22110"
		elif [[ $input == "2" ]]
		then
			RandomAccessReverseConstructors "Test Copy constructor" "22120"
		elif [[ $input == "3" ]]
		then
			RandomAccessReverseConstructors "Test Operator Equal" "22130"
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessReverseAllConstructors '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			RandomAccessReverseMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintRandomAccessReverseConstructorsMenu
		fi
	done
}
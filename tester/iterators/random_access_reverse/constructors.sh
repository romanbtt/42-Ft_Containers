#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessReverseConstructors()
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
	PrintRandomAccessReverseConstructorsMenu
}

function RandomAccessReverseAllConstructors()
{
	echo -e $BWhite "Test Reverse Access Random Default constructor" $Color_Off
	Execute $ft "22111"
	Execute $std "22111"
	echo
	CompareFiles
	echo -e $BWhite "Test Reverse Access Random Copy constructor" $Color_Off
	Execute $ft "22121"
	Execute $std "22121"
	echo
	CompareFiles
	echo -e $BWhite "Test Reverse Access Random Operator Equal" $Color_Off
	Execute $ft "22131"
	Execute $std "22131"
	echo
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
			RandomAccessReverseConstructors "Test Reverse Access Random Default constructor" "22110"
		elif [[ $input == "2" ]]
		then
			RandomAccessReverseConstructors "Test Reverse Access Random Copy constructor" "22120"
		elif [[ $input == "3" ]]
		then
			RandomAccessReverseConstructors "Test Reverse Access Random Operator Equal" "22130"
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
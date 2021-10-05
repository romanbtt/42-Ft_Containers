#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessConstructors()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintRandomAccessConstructorsMenu
}

function RandomAccessAllConstructors()
{
	echo -e $BWhite "Test Default constructor" $Color_Off
	$ft "21111"
	$std "21111"
	CompareFiles
	echo -e $BWhite "Test Copy constructor" $Color_Off
	$ft "21121"
	$std "21121"
	CompareFiles
	echo -e $BWhite "Test Operator Equal" $Color_Off
	$ft "21131"
	$std "21131"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintRandomAccessConstructorsMenu
	fi
}

function PrintRandomAccessConstructorsMenu()
{
	echo -e $BPurple --- Random Access Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function RandomAccessConstructorsMenu()
{
	clear
	PrintRandomAccessConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessConstructors "Test Default constructor" "21110"
		elif [[ $input == "2" ]]
		then
			RandomAccessConstructors "Test Copy constructor" "21120"
		elif [[ $input == "3" ]]
		then
			RandomAccessConstructors "Test Operator Equal" "21130"
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessAllConstructors '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			RandomAccessMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintRandomAccessConstructorsMenu
		fi
	done
}
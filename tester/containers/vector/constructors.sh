#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorConstructor()
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
	PrintVectorConstructorsMenu
}

function VectorAllConstructors()
{
	echo -e $BWhite "Test Vector Default constructor" $Color_Off
	Execute $ft "11111"
	Execute $std "11111"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Fill constructor" $Color_Off
	Execute $ft "11121"
	Execute $std "11121"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Range constructor" $Color_Off
	Execute $ft "11131"
	Execute $std "11131"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Copy constructor" $Color_Off
	Execute $ft "11141"
	Execute $std "11141"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Operator Equal" $Color_Off
	Execute $ft "11151"
	Execute $std "11151"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintVectorConstructorsMenu
	fi
}

function PrintVectorConstructorsMenu()
{
	echo -e $BPurple --- Vector Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Fill constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Range constructor $Color_Off
	echo -e $BCyan 4 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 5 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorConstructorsMenu()
{
	clear
	PrintVectorConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorConstructor "Test Vector Default constructor" "11110"
		elif [[ $input == "2" ]]
		then
			VectorConstructor "Test Vector Fill constructor" "11120"
		elif [[ $input == "3" ]]
		then
			VectorConstructor "Test Vector Range constructor" "11130"
		elif [[ $input == "4" ]]
		then
			VectorConstructor "Test Vector Copy constructor" "11140"
		elif [[ $input == "5" ]]
		then
			VectorConstructor "Test Vector Operator Equal" "11150"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllConstructors '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorConstructorsMenu
		fi
	done
}
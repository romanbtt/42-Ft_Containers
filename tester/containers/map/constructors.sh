#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapConstructor()
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
	PrintMapConstructorsMenu
}

function MapAllConstructors()
{
	echo -e $BWhite "Test Map Default constructor" $Color_Off
	Execute $ft "12111"
	Execute $std "12111"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Range constructor" $Color_Off
	Execute $ft "12121"
	Execute $std "12121"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Copy constructor" $Color_Off
	Execute $ft "12131"
	Execute $std "12131"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Operator Equal" $Color_Off
	Execute $ft "12141"
	Execute $std "12141"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintMapConstructorsMenu
	fi
}

function PrintMapConstructorsMenu()
{
	echo -e $BPurple --- Map Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Range constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 4 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapConstructorsMenu()
{
	clear
	PrintMapConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapConstructor "Test Map Default constructor" "12110"
		elif [[ $input == "2" ]]
		then
			MapConstructor "Test Map Range constructor" "12120"
		elif [[ $input == "3" ]]
		then
			MapConstructor "Test Map Copy constructor" "12130"
		elif [[ $input == "4" ]]
		then
			MapConstructor "Test Map Operator Equal" "12140"
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAllConstructors '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MapMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintMapConstructorsMenu
		fi
	done
}
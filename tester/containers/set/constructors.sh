#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetConstructor()
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
	PrintSetConstructorsMenu
}

function SetAllConstructors()
{
	echo -e $BWhite "Test Set Default constructor" $Color_Off
	Execute $ft "14111"
	Execute $std "14111"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Range constructor" $Color_Off
	Execute $ft "14121"
	Execute $std "14121"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Copy constructor" $Color_Off
	Execute $ft "14131"
	Execute $std "14131"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Operator Equal" $Color_Off
	Execute $ft "14141"
	Execute $std "14141"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintSetConstructorsMenu
	fi
}

function PrintSetConstructorsMenu()
{
	echo -e $BPurple --- Set Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Range constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 4 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function SetConstructorsMenu()
{
	clear
	PrintSetConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			SetConstructor "Test Set Default constructor" "14110"
		elif [[ $input == "2" ]]
		then
			SetConstructor "Test Set Range constructor" "14120"
		elif [[ $input == "3" ]]
		then
			SetConstructor "Test Set Copy constructor" "14130"
		elif [[ $input == "4" ]]
		then
			SetConstructor "Test Set Operator Equal" "14140"
		elif [[ $input == "A" || $input == "a" ]]
		then
			SetAllConstructors '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			SetMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintSetConstructorsMenu
		fi
	done
}
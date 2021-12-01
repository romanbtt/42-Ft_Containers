#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetModifiers()
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
	PrintSetModifiersMenu
}

function SetAllModifiers()
{
	echo -e $BWhite "Test Set Insert" $Color_Off
	Execute $ft "14411"
	Execute $std "14411"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Erase" $Color_Off
	Execute $ft "14421"
	Execute $std "14421"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Swap" $Color_Off
	Execute $ft "14431"
	Execute $std "14431"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Clear" $Color_Off
	Execute $ft "14441"
	Execute $std "14441"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintSetModifiersMenu
	fi
}

function PrintSetModifiersMenu()
{
	echo -e $BPurple --- Set Modifiers menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Insert $Color_Off
	echo -e $BCyan 2 $BWhite - Erase $Color_Off
	echo -e $BCyan 3 $BWhite - Swap $Color_Off
	echo -e $BCyan 4 $BWhite - Clear $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function SetModifiersMenu()
{
	clear
	PrintSetModifiersMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			SetModifiers "Test Set Insert" "14410"
		elif [[ $input == "2" ]]
		then
			SetModifiers "Test Set Erase" "14420"
		elif [[ $input == "3" ]]
		then
			SetModifiers "Test Set Swap" "14430"
		elif [[ $input == "4" ]]
		then
			SetModifiers "Test Set Clear" "14440"
		elif [[ $input == "A" || $input == "a" ]]
		then
			SetAllModifiers '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			SetMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintSetModifiersMenu
		fi
	done
}
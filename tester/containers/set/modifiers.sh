#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetModifiers()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintSetModifiersMenu
}

function SetAllModifiers()
{
	echo -e $BWhite "Test Insert" $Color_Off
	$ft "14411"
	$std "14411"
	CompareFiles
	echo -e $BWhite "Test Erase" $Color_Off
	$ft "14421"
	$std "14421"
	CompareFiles
	echo -e $BWhite "Test Swap" $Color_Off
	$ft "14431"
	$std "14431"
	CompareFiles
	echo -e $BWhite "Test Clear" $Color_Off
	$ft "14441"
	$std "14441"
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
			SetModifiers "Test Insert" "14410"
		elif [[ $input == "2" ]]
		then
			SetModifiers "Test Erase" "14420"
		elif [[ $input == "3" ]]
		then
			SetModifiers "Test Swap" "14430"
		elif [[ $input == "4" ]]
		then
			SetModifiers "Test Clear" "14440"
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
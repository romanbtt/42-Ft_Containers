#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapModifiers()
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
	PrintMapModifiersMenu
}

function MapAllModifiers()
{
	echo -e $BWhite "Test Map Insert" $Color_Off
	Execute $ft "12511"
	Execute $std "12511"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Erase" $Color_Off
	Execute $ft "12521"
	Execute $std "12521"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Swap" $Color_Off
	Execute $ft "12531"
	Execute $std "12531"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Clear" $Color_Off
	Execute $ft "12541"
	Execute $std "12541"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintMapModifiersMenu
	fi
}

function PrintMapModifiersMenu()
{
	echo -e $BPurple --- Map Modifiers menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Insert $Color_Off
	echo -e $BCyan 2 $BWhite - Erase $Color_Off
	echo -e $BCyan 3 $BWhite - Swap $Color_Off
	echo -e $BCyan 4 $BWhite - Clear $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapModifiersMenu()
{
	clear
	PrintMapModifiersMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapModifiers "Test Map Insert" "12510"
		elif [[ $input == "2" ]]
		then
			MapModifiers "Test Map Erase" "12520"
		elif [[ $input == "3" ]]
		then
			MapModifiers "Test Map Swap" "12530"
		elif [[ $input == "4" ]]
		then
			MapModifiers "Test Map Clear" "12540"
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAllModifiers '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MapMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintMapModifiersMenu
		fi
	done
}
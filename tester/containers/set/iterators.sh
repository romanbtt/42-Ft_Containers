#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetIterator()
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
	PrintSetIteratorsMenu
}

function SetAllIterators()
{
	echo -e $BWhite "Test Set Begin" $Color_Off
	Execute $ft "14211"
	Execute $std "14211"
	echo
	CompareFiles
	echo -e $BWhite "Test Set End" $Color_Off
	Execute $ft "14221"
	Execute $std "14221"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Rbegin" $Color_Off
	Execute $ft "14231"
	Execute $std "14231"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Rend" $Color_Off
	Execute $ft "14241"
	Execute $std "14241"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintSetIteratorsMenu
	fi
}

function PrintSetIteratorsMenu()
{
	echo -e $BPurple --- Set Iterators menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Begin $Color_Off
	echo -e $BCyan 2 $BWhite - End $Color_Off
	echo -e $BCyan 3 $BWhite - Rbegin $Color_Off
	echo -e $BCyan 4 $BWhite - Rend $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function SetIteratorsMenu()
{
	clear
	PrintSetIteratorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			SetIterator "Test Set Begin" "14210"
		elif [[ $input == "2" ]]
		then
			SetIterator "Test Set End" "14220"
		elif [[ $input == "3" ]]
		then
			SetIterator "Test Set Rbegin" "14230"
		elif [[ $input == "4" ]]
		then
			SetIterator "Test Set Rend" "14240"
		elif [[ $input == "A" || $input == "a" ]]
		then
			SetAllIterators '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			SetMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintSetIteratorsMenu
		fi
	done
}
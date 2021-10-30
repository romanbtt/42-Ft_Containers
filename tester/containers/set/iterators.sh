#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetIterator()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintSetIteratorsMenu
}

function SetAllIterators()
{
	echo -e $BWhite "Test Begin" $Color_Off
	$ft "14211"
	$std "14211"
	CompareFiles
	echo -e $BWhite "Test End" $Color_Off
	$ft "14221"
	$std "14221"
	CompareFiles
	echo -e $BWhite "Test Rbegin" $Color_Off
	$ft "14231"
	$std "14231"
	CompareFiles
	echo -e $BWhite "Test Rend" $Color_Off
	$ft "14241"
	$std "14241"
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
			SetIterator "Test Begin" "14210"
		elif [[ $input == "2" ]]
		then
			SetIterator "Test End" "14220"
		elif [[ $input == "3" ]]
		then
			SetIterator "Test Rbegin" "14230"
		elif [[ $input == "4" ]]
		then
			SetIterator "Test Rend" "14240"
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
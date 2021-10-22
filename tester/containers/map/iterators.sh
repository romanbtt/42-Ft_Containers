#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapIterator()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintMapIteratorsMenu
}

function MapAllIterators()
{
	echo -e $BWhite "Test Begin" $Color_Off
	$ft "12211"
	$std "12211"
	CompareFiles
	echo -e $BWhite "Test End" $Color_Off
	$ft "12221"
	$std "12221"
	CompareFiles
	echo -e $BWhite "Test Rbegin" $Color_Off
	$ft "12231"
	$std "12231"
	CompareFiles
	echo -e $BWhite "Test Rend" $Color_Off
	$ft "12241"
	$std "12241"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintMapIteratorsMenu
	fi
}

function PrintMapIteratorsMenu()
{
	echo -e $BPurple --- Map Iterators menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Begin $Color_Off
	echo -e $BCyan 2 $BWhite - End $Color_Off
	echo -e $BCyan 3 $BWhite - Rbegin $Color_Off
	echo -e $BCyan 4 $BWhite - Rend $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapIteratorsMenu()
{
	clear
	PrintMapIteratorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapIterator "Test Begin" "12210"
		elif [[ $input == "2" ]]
		then
			MapIterator "Test End" "12220"
		elif [[ $input == "3" ]]
		then
			MapIterator "Test Rbegin" "12230"
		elif [[ $input == "4" ]]
		then
			MapIterator "Test Rend" "12240"
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAllIterators '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MapMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintMapIteratorsMenu
		fi
	done
}
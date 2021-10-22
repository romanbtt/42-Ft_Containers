#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapAccess()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintMapAccessMenu
}

function MapAllAccess()
{
	echo -e $BWhite "Test Operator[]" $Color_Off
	$ft "12411"
	$std "12411"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintMapAccessMenu
	fi
}

function PrintMapAccessMenu()
{
	echo -e $BPurple --- Map Element Access menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Operator[] $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapAccessMenu()
{
	clear
	PrintMapAccessMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapAccess "Test Operator[]" "12410"
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAllAccess '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MapMenu 
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintMapAccessMenu
		fi
	done
}
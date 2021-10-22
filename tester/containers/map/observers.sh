#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapObservers()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintMapObserversMenu
}

function MapAllObservers()
{
	echo -e $BWhite "Test Key_comp" $Color_Off
	$ft "12611"
	$std "12611"
	CompareFiles
	echo -e $BWhite "Test Value_comp" $Color_Off
	$ft "12621"
	$std "12621"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintMapObserversMenu
	fi
}

function PrintMapObserversMenu()
{
	echo -e $BPurple --- Map Observers menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Key_comp $Color_Off
	echo -e $BCyan 2 $BWhite - Value_comp $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapObserversMenu()
{
	clear
	PrintMapObserversMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapObservers "Test Key_comp" "12610"
		elif [[ $input == "2" ]]
		then
			MapObservers "Test Value_comp" "12620"
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAllObservers '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MapMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintMapObserversMenu
		fi
	done
}
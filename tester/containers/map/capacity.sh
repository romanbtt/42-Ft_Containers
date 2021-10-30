#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapCapacity()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintMapCapacityMenu
}

function MapAllCapacity()
{
	echo -e $BWhite "Test Empty" $Color_Off
	$ft "12311"
	$std "12311"
	CompareFiles
	echo -e $BWhite "Test Size" $Color_Off
	$ft "12321"
	$std "12321"
	CompareFiles
	echo -e $BWhite "Test Max Size" $Color_Off
	$ft "12331"
	$std "12331"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintMapCapacityMenu
	fi
}

function PrintMapCapacityMenu()
{
	echo -e $BPurple --- Map Capacity menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Empty $Color_Off
	echo -e $BCyan 2 $BWhite - Size $Color_Off
	echo -e $BCyan 3 $BWhite - Max Size $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapCapacityMenu()
{
	clear
	PrintMapCapacityMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapCapacity "Test Empty" "12310"
		elif [[ $input == "2" ]]
		then
			MapCapacity "Test Size" "12320"
		elif [[ $input == "3" ]]
		then
			MapCapacity "Test Max Size" "12330"
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAllCapacity '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MapMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintMapCapacityMenu
		fi
	done
}

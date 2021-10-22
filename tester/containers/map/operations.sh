#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapOperations()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintMapOperationsMenu
}

function MapAllOperations()
{
	echo -e $BWhite "Test Find" $Color_Off
	$ft "12711"
	$std "12711"
	CompareFiles
	echo -e $BWhite "Test Count" $Color_Off
	$ft "12721"
	$std "12721"
	CompareFiles
	echo -e $BWhite "Test Lower_bound" $Color_Off
	$ft "12731"
	$std "12731"
	CompareFiles
	echo -e $BWhite "Test Upper_bound" $Color_Off
	$ft "12741"
	$std "12741"
	CompareFiles
	echo -e $BWhite "Test Equal_range" $Color_Off
	$ft "12751"
	$std "12751"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintMapOperationsMenu
	fi
}

function PrintMapOperationsMenu()
{
	echo -e $BPurple --- Map Operations menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Find $Color_Off
	echo -e $BCyan 2 $BWhite - Count $Color_Off
	echo -e $BCyan 3 $BWhite - Lower_bound $Color_Off
	echo -e $BCyan 4 $BWhite - Upper_bound $Color_Off
	echo -e $BCyan 5 $BWhite - Equal_range $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapOperationsMenu()
{
	clear
	PrintMapOperationsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapOperations "Test Find" "12710"
		elif [[ $input == "2" ]]
		then
			MapOperations "Test Count" "12720"
		elif [[ $input == "3" ]]
		then
			MapOperations "Test Lower_bound" "12730"
		elif [[ $input == "4" ]]
		then
			MapOperations "Test Upper_bound" "12740"
		elif [[ $input == "5" ]]
		then
			MapOperations "Test Equal_range" "12750"
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAllOperations '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MapMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintMapOperationsMenu
		fi
	done
}
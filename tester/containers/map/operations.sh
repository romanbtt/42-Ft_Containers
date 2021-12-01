#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapOperations()
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
	PrintMapOperationsMenu
}

function MapAllOperations()
{
	echo -e $BWhite "Test Map Find" $Color_Off
	Execute $ft "12711"
	Execute $std "12711"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Count" $Color_Off
	Execute $ft "12721"
	Execute $std "12721"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Lower_bound" $Color_Off
	Execute $ft "12731"
	Execute $std "12731"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Upper_bound" $Color_Off
	Execute $ft "12741"
	Execute $std "12741"
	echo
	CompareFiles
	echo -e $BWhite "Test Map Equal_range" $Color_Off
	Execute $ft "12751"
	Execute $std "12751"
	echo
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
			MapOperations "Test Map Find" "12710"
		elif [[ $input == "2" ]]
		then
			MapOperations "Test Map Count" "12720"
		elif [[ $input == "3" ]]
		then
			MapOperations "Test Map Lower_bound" "12730"
		elif [[ $input == "4" ]]
		then
			MapOperations "Test Map Upper_bound" "12740"
		elif [[ $input == "5" ]]
		then
			MapOperations "Test Map Equal_range" "12750"
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
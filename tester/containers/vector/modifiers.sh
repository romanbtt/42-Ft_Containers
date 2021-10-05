#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorModifiers()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintVectorModifiersMenu
}

function VectorAllModifiers()
{
	echo -e $BWhite "Test Assign" $Color_Off
	$ft "11511"
	$std "11511"
	CompareFiles
	echo -e $BWhite "Test Push_back" $Color_Off
	$ft "11521"
	$std "11521"
	CompareFiles
	echo -e $BWhite "Test Pop_back" $Color_Off
	$ft "11531"
	$std "11531"
	CompareFiles
	echo -e $BWhite "Test Insert" $Color_Off
	$ft "11541"
	$std "11541"
	CompareFiles
	echo -e $BWhite "Test Erase" $Color_Off
	$ft "11551"
	$std "11551"
	CompareFiles
	echo -e $BWhite "Test Swap" $Color_Off
	$ft "11561"
	$std "11561"
	CompareFiles
	echo -e $BWhite "Test Clear" $Color_Off
	$ft "11571"
	$std "11571"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintVectorModifiersMenu
	fi
}

function PrintVectorModifiersMenu()
{
	echo -e $BPurple --- Vector Modifiers menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Assign $Color_Off
	echo -e $BCyan 2 $BWhite - Push_back $Color_Off
	echo -e $BCyan 3 $BWhite - Pop_back $Color_Off
	echo -e $BCyan 4 $BWhite - Insert $Color_Off
	echo -e $BCyan 5 $BWhite - Erase $Color_Off
	echo -e $BCyan 6 $BWhite - Swap $Color_Off
	echo -e $BCyan 7 $BWhite - Clear $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorModifiersMenu()
{
	clear
	PrintVectorModifiersMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorModifiers "Test Assign" "11510"
		elif [[ $input == "2" ]]
		then
			VectorModifiers "Test Push_back" "11520"
		elif [[ $input == "3" ]]
		then
			VectorModifiers "Test Pop_back" "11530"
		elif [[ $input == "4" ]]
		then
			VectorModifiers "Test Insert" "11540"
		elif [[ $input == "5" ]]
		then
			VectorModifiers "Test Erase" "11550"
		elif [[ $input == "6" ]]
		then
			VectorModifiers "Test Swap" "11560"
		elif [[ $input == "7" ]]
		then
			VectorModifiers "Test Clear" "11570"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllModifiers '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorModifiersMenu
		fi
	done
}
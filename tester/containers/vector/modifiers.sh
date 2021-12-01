#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorModifiers()
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
	PrintVectorModifiersMenu
}

function VectorAllModifiers()
{
	echo -e $BWhite "Test Vector Assign" $Color_Off
	Execute $ft "11511"
	Execute $std "11511"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Push_back" $Color_Off
	Execute $ft "11521"
	Execute $std "11521"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Pop_back" $Color_Off
	Execute $ft "11531"
	Execute $std "11531"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Insert" $Color_Off
	Execute $ft "11541"
	Execute $std "11541"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Erase" $Color_Off
	Execute $ft "11551"
	Execute $std "11551"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Swap" $Color_Off
	Execute $ft "11561"
	Execute $std "11561"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Clear" $Color_Off
	Execute $ft "11571"
	Execute $std "11571"
	echo
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
			VectorModifiers "Test Vector Assign" "11510"
		elif [[ $input == "2" ]]
		then
			VectorModifiers "Test Vector Push_back" "11520"
		elif [[ $input == "3" ]]
		then
			VectorModifiers "Test Vector Pop_back" "11530"
		elif [[ $input == "4" ]]
		then
			VectorModifiers "Test Vector Insert" "11540"
		elif [[ $input == "5" ]]
		then
			VectorModifiers "Test Vector Erase" "11550"
		elif [[ $input == "6" ]]
		then
			VectorModifiers "Test Vector Swap" "11560"
		elif [[ $input == "7" ]]
		then
			VectorModifiers "Test Vector Clear" "11570"
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
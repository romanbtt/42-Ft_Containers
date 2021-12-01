#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorAccess()
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
	PrintVectorAccessMenu
}

function VectorAllAccess()
{
	echo -e $BWhite "Test Vector Operator[]" $Color_Off
	Execute $ft "11411"
	Execute $std "11411"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector At" $Color_Off
	Execute $ft "11421"
	Execute $std "11421"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Front" $Color_Off
	Execute $ft "11431"
	Execute $std "11431"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Back" $Color_Off
	Execute $ft "11441"
	Execute $std "11441"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintVectorAccessMenu
	fi
}

function PrintVectorAccessMenu()
{
	echo -e $BPurple --- Vector Element Access menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Operator[] $Color_Off
	echo -e $BCyan 2 $BWhite - At $Color_Off
	echo -e $BCyan 3 $BWhite - Front $Color_Off
	echo -e $BCyan 4 $BWhite - Back $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorAccessMenu()
{
	clear
	PrintVectorAccessMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorAccess "Test Vector Operator[]" "11410"
		elif [[ $input == "2" ]]
		then
			VectorAccess "Test Vector At" "11420"
		elif [[ $input == "3" ]]
		then
			VectorAccess "Test Vector Front" "11430"
		elif [[ $input == "4" ]]
		then
			VectorAccess "Test Vector Back" "11440"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllAccess '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu 
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorAccessMenu
		fi
	done
}
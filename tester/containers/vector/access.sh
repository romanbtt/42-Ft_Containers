#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorAccess()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintVectorAccessMenu
}

function VectorAllAccess()
{
	echo -e $BWhite "Test Operator[]" $Color_Off
	$ft "11411"
	$std "11411"
	CompareFiles
	echo -e $BWhite "Test At" $Color_Off
	$ft "11421"
	$std "11421"
	CompareFiles
	echo -e $BWhite "Test Front" $Color_Off
	$ft "11431"
	$std "11431"
	CompareFiles
	echo -e $BWhite "Test Back" $Color_Off
	$ft "11441"
	$std "11441"
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
			VectorAccess "Test Operator[]" "11410"
		elif [[ $input == "2" ]]
		then
			VectorAccess "Test At" "11420"
		elif [[ $input == "3" ]]
		then
			VectorAccess "Test Front" "11430"
		elif [[ $input == "4" ]]
		then
			VectorAccess "Test Back" "11440"
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
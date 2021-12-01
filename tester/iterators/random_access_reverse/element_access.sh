#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessReverseElementAccess()
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
	PrintRandomAccessReverseElementAccessMenu
}

function RandomAccessReverseAllElementAccess()
{
	echo -e $BWhite "Test Reverse Access Random Operator []" $Color_Off
	Execute $ft "22211"
	Execute $std "22211"
	echo
	CompareFiles
	echo -e $BWhite "Test Reverse Access Random Operator *" $Color_Off
	Execute $ft "22221"
	Execute $std "22221"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintRandomAccessReverseElementAccessMenu
	fi
}

function PrintRandomAccessReverseElementAccessMenu()
{
	echo -e $BPurple --- Random Access Reverse Element Access menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Operator [] $Color_Off
	echo -e $BCyan 2 $BWhite - Operator '*' $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function RandomAccessReverseElementAccessMenu()
{
	clear
	PrintRandomAccessReverseElementAccessMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessReverseElementAccess "Test Reverse Access Random Operator []" "22210"
		elif [[ $input == "2" ]]
		then
			RandomAccessReverseElementAccess "Test Reverse Access Random Operator '*'" "22220"
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessReverseAllElementAccess '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			RandomAccessReverseMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintRandomAccessReverseElementAccessMenu
		fi
	done
}
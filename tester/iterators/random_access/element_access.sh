#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessElementAccess()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintRandomAccessElementAccessMenu
}

function RandomAccessAllElementAccess()
{
	echo -e $BWhite "Test Operator []" $Color_Off
	$ft "21211"
	$std "21211"
	CompareFiles
	echo -e $BWhite "Test Operator *" $Color_Off
	$ft "21221"
	$std "21221"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintRandomAccessElementAccessMenu
	fi
}

function PrintRandomAccessElementAccessMenu()
{
	echo -e $BPurple --- Random Access Element Access menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Operator [] $Color_Off
	echo -e $BCyan 2 $BWhite - Operator '*' $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function RandomAccessElementAccessMenu()
{
	clear
	PrintRandomAccessElementAccessMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessElementAccess "Test Operator []" "21210"
		elif [[ $input == "2" ]]
		then
			RandomAccessElementAccess "Test Operator '*'" "21220"
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessAllElementAccess '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			RandomAccessMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintRandomAccessElementAccessMenu
		fi
	done
}
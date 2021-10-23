#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalConstructors()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintBidirectionalConstructorsMenu
}

function BidirectionalAllConstructors()
{
	echo -e $BWhite "Test Default constructor" $Color_Off
	$ft "23111"
	$std "23111"
	CompareFiles
	echo -e $BWhite "Test Copy constructor" $Color_Off
	$ft "23121"
	$std "23121"
	CompareFiles
	echo -e $BWhite "Test Operator Equal" $Color_Off
	$ft "23131"
	$std "23131"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintBidirectionalConstructorsMenu
	fi
}

function PrintBidirectionalConstructorsMenu()
{
	echo -e $BPurple --- Bidirectional Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function BidirectionalConstructorsMenu()
{
	clear
	PrintBidirectionalConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			BidirectionalConstructors "Test Default constructor" "23110"
		elif [[ $input == "2" ]]
		then
			BidirectionalConstructors "Test Copy constructor" "23120"
		elif [[ $input == "3" ]]
		then
			BidirectionalConstructors "Test Operator Equal" "23130"
		elif [[ $input == "A" || $input == "a" ]]
		then
			BidirectionalAllConstructors '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			BidirectionalMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintBidirectionalConstructorsMenu
		fi
	done
}
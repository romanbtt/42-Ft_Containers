#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalReverseConstructors()
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
	PrintBidirectionalReverseConstructorsMenu
}

function BidirectionalReverseAllConstructors()
{
	echo -e $BWhite "Test Bidirectional Reverse Default constructor" $Color_Off
	Execute $ft "24111"
	Execute $std "24111"
	echo
	CompareFiles
	echo -e $BWhite "Test Bidirectional Reverse Copy constructor" $Color_Off
	Execute $ft "24121"
	Execute $std "24121"
	echo
	CompareFiles
	echo -e $BWhite "Test Bidirectional Reverse Operator Equal" $Color_Off
	Execute $ft "24131"
	Execute $std "24131"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintBidirectionalReverseConstructorsMenu
	fi
}

function PrintBidirectionalReverseConstructorsMenu()
{
	echo -e $BPurple --- Bidirectional Reverse Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function BidirectionalReverseConstructorsMenu()
{
	clear
	PrintBidirectionalReverseConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			BidirectionalReverseConstructors "Test Bidirectional Reverse Default constructor" "24110"
		elif [[ $input == "2" ]]
		then
			BidirectionalReverseConstructors "Test Bidirectional Reverse Copy constructor" "24120"
		elif [[ $input == "3" ]]
		then
			BidirectionalReverseConstructors "Test Bidirectional Reverse Operator Equal" "24130"
		elif [[ $input == "A" || $input == "a" ]]
		then
			BidirectionalReverseAllConstructors '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			BidirectionalReverseMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintBidirectionalReverseConstructorsMenu
		fi
	done
}
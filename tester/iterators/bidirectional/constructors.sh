#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalConstructors()
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
	PrintBidirectionalConstructorsMenu
}

function BidirectionalAllConstructors()
{
	echo -e $BWhite "Test Bidirectional Default constructor" $Color_Off
	Execute $ft "23111"
	Execute $std "23111"
	echo
	CompareFiles
	echo -e $BWhite "Test Bidirectional Copy constructor" $Color_Off
	Execute $ft "23121"
	Execute $std "23121"
	echo
	CompareFiles
	echo -e $BWhite "Test Bidirectional Operator Equal" $Color_Off
	Execute $ft "23131"
	Execute $std "23131"
	echo
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
			BidirectionalConstructors "Test Bidirectional Default constructor" "23110"
		elif [[ $input == "2" ]]
		then
			BidirectionalConstructors "Test Bidirectional Copy constructor" "23120"
		elif [[ $input == "3" ]]
		then
			BidirectionalConstructors "Test Bidirectional Operator Equal" "23130"
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
#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/constructors.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/element_access.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/arithmetic.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/relational_operators.sh

function BidirectionalReverseAll()
{
	echo -e $BBlue "Tests Bidirectional Reverse Constructors" $Color_Off
	echo
	BidirectionalReverseAllConstructors '0'

	echo -e $BBlue "Tests Bidirectional Reverse Element Access" $Color_Off
	echo
	
	echo -e $BWhite "Test Bidirectional Reverse Element Access" $Color_Off
	Execute $ft "24211"
	Execute $std "24211"
	echo
	CompareFiles
	
	echo -e $BBlue "Tests Bidirectional Reverse Arithmetic" $Color_Off
	echo
	BidirectionalReverseAllArithmetic '0'

	echo -e $BBlue "Tests Bidirectional Reverse Relational Operators" $Color_Off
	echo

	echo -e $BWhite "Test Bidirectional Reverse Relational Operators" $Color_Off
	Execute $ft "24411"
	Execute $std "24411"
	echo
	CompareFiles

	if [[ $1 == '1' ]]
	then
		PrintBidirectionalReverseMenu
	fi
}

function PrintBidirectionalReverseMenu()
{
	echo -e $BPurple --- Bidirectional Reverse Menu--- $Color_Off
	echo -e $BCyan 1 $BWhite - Constructors $Color_Off
	echo -e $BCyan 2 $BWhite - Element access $Color_Off
	echo -e $BCyan 3 $BWhite - Arithmetic $Color_Off
	echo -e $BCyan 4 $BWhite - Relational operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function BidirectionalReverseMenu()
{
	clear
	PrintBidirectionalReverseMenu
	input=""
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			BidirectionalReverseConstructorsMenu
		elif [[ $input == "2" ]]
		then
			BidirectionalReverseElementAccess "Test Element access"
		elif [[ $input == "3" ]]
		then
			BidirectionalReverseArithmeticMenu
		elif [[ $input == "4" ]]
		then
			BidirectionalReverseRelationalOperators "Test Relational operators"
		elif [[ $input == "A" || $input == "a" ]]
		then
			BidirectionalReverseAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			IteratorsMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintBidirectionalReverseMenu
		fi
	done
}
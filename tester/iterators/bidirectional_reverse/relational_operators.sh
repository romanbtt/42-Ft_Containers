#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalReverseRelationalOperators()
{
	echo -e $BWhite "Tests Bidirectional Reverse Relational Operators" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "24410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "24410"
	echo
	CompareFiles
	PrintBidirectionalReverseMenu
}
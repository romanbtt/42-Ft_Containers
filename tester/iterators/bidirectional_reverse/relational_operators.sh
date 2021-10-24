#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalReverseRelationalOperators()
{
	echo -e $BWhite "Tests Relational Operators" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft "24410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std "24410"
	CompareFiles
	PrintBidirectionalReverseMenu
}
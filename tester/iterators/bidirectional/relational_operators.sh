#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalRelationalOperators()
{
	echo -e $BWhite "Tests Bidirectional Relational Operators" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "23410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "23410"
	echo
	CompareFiles
	PrintBidirectionalMenu
}
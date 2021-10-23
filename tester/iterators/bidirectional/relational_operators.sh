#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalRelationalOperators()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft "23410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std "23410"
	CompareFiles
	PrintBidirectionalMenu
}
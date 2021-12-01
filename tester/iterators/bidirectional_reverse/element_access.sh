#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalReverseElementAccess()
{
	echo -e $BWhite "Tests Bidirectional Reverse Element Access" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "24210"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "24210"
	echo
	CompareFiles
	PrintBidirectionalReverseMenu
}
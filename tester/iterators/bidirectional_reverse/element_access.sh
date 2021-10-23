#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalReverseElementAccess()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft "24210"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std "24210"
	CompareFiles
	PrintBidirectionalReverseMenu
}
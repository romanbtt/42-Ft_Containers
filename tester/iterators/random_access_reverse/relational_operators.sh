#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessReverseRelationalOperators()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "22410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "22410"
	echo
	CompareFiles
	PrintRandomAccessReverseMenu
}
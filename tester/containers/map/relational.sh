#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapRelationalOperators()
{
	echo -e $BWhite "Test Map Relational Operators" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "12910"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "12910"
	echo
	CompareFiles
	PrintMapMenu
}
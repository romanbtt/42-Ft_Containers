#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapAccess()
{
	echo -e $BWhite "Test Map Element Access" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "12410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "12410"
	echo
	CompareFiles
	PrintMapMenu
}
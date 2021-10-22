#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapRelationalOperators()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft "12910"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std "12910"
	CompareFiles
	PrintVectorMenu
}
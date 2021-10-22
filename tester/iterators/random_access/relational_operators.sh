#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessRelationalOperators()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft "21410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std "21410"
	CompareFiles
	PrintRandomAccessMenu
}
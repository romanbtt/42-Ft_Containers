#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function RandomAccessRelationalOperators()
{
	echo -e $BWhite "Tests Random Access Relational Operators" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "21410"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "21410"
	echo
	CompareFiles
	PrintRandomAccessMenu
}
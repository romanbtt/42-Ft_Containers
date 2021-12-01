#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorRelationalOperators()
{
	echo -e $BWhite "Test Relational Operators" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "11710"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "11710"
	echo
	CompareFiles
	PrintVectorMenu
}
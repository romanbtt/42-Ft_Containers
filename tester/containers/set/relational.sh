#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetRelationalOperators()
{
	echo -e $BWhite "Test Set Relational Operators" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "14810"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "14810"
	echo
	CompareFiles
	PrintSetMenu
}
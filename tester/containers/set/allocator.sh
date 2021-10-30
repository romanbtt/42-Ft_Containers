#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetGetAllocator()
{
	echo -e $BWhite "Test Get allocator" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft "14710"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std "14710"
	CompareFiles
	PrintSetMenu
}
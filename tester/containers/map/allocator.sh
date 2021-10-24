#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapGetAllocator()
{
	echo -e $BWhite "Test Get allocator" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft "12810"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std "12810"
	CompareFiles
	PrintMapMenu
}
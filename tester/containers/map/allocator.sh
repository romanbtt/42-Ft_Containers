#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function MapGetAllocator()
{
	echo -e $BWhite "Test Map Get allocator" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft "12810"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std "12810"
	echo
	CompareFiles
	PrintMapMenu
}
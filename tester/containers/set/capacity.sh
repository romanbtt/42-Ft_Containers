#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetCapacity()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std $2
	echo
	CompareFiles
	PrintSetCapacityMenu
}

function SetAllCapacity()
{
	echo -e $BWhite "Test Set Empty" $Color_Off
	Execute $ft "14311"
	Execute $std "14311"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Size" $Color_Off
	Execute $ft "14321"
	Execute $std "14321"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Max Size" $Color_Off
	Execute $ft "14331"
	Execute $std "14331"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintSetCapacityMenu
	fi
}

function PrintSetCapacityMenu()
{
	echo -e $BPurple --- Set Capacity menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Empty $Color_Off
	echo -e $BCyan 2 $BWhite - Size $Color_Off
	echo -e $BCyan 3 $BWhite - Max Size $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function SetCapacityMenu()
{
	clear
	PrintSetCapacityMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			SetCapacity "Test Set Empty" "14310"
		elif [[ $input == "2" ]]
		then
			SetCapacity "Test Set Size" "14320"
		elif [[ $input == "3" ]]
		then
			SetCapacity "Test Set Max Size" "14330"
		elif [[ $input == "A" || $input == "a" ]]
		then
			SetAllCapacity '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			SetMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintSetCapacityMenu
		fi
	done
}

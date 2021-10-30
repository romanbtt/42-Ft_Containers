#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetObservers()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintSetObserversMenu
}

function SetAllObservers()
{
	echo -e $BWhite "Test Key_comp" $Color_Off
	$ft "14511"
	$std "14511"
	CompareFiles
	echo -e $BWhite "Test Value_comp" $Color_Off
	$ft "14521"
	$std "14521"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintSetObserversMenu
	fi
}

function PrintSetObserversMenu()
{
	echo -e $BPurple --- Set Observers menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Key_comp $Color_Off
	echo -e $BCyan 2 $BWhite - Value_comp $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function SetObserversMenu()
{
	clear
	PrintSetObserversMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			SetObservers "Test Key_comp" "14510"
		elif [[ $input == "2" ]]
		then
			SetObservers "Test Value_comp" "14520"
		elif [[ $input == "A" || $input == "a" ]]
		then
			SetAllObservers '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			SetMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintSetObserversMenu
		fi
	done
}
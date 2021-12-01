#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetOperations()
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
	PrintSetOperationsMenu
}

function SetAllOperations()
{
	echo -e $BWhite "Test Set Find" $Color_Off
	Execute $ft "14611"
	Execute $std "14611"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Count" $Color_Off
	Execute $ft "14621"
	Execute $std "14621"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Lower_bound" $Color_Off
	Execute $ft "14631"
	Execute $std "14631"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Upper_bound" $Color_Off
	Execute $ft "14641"
	Execute $std "14641"
	echo
	CompareFiles
	echo -e $BWhite "Test Set Equal_range" $Color_Off
	Execute $ft "14651"
	Execute $std "14651"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintSetOperationsMenu
	fi
}

function PrintSetOperationsMenu()
{
	echo -e $BPurple --- Set Operations menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Find $Color_Off
	echo -e $BCyan 2 $BWhite - Count $Color_Off
	echo -e $BCyan 3 $BWhite - Lower_bound $Color_Off
	echo -e $BCyan 4 $BWhite - Upper_bound $Color_Off
	echo -e $BCyan 5 $BWhite - Equal_range $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function SetOperationsMenu()
{
	clear
	PrintSetOperationsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			SetOperations "Test Set Find" "14610"
		elif [[ $input == "2" ]]
		then
			SetOperations "Test Set Count" "14620"
		elif [[ $input == "3" ]]
		then
			SetOperations "Test Set Lower_bound" "14630"
		elif [[ $input == "4" ]]
		then
			SetOperations "Test Set Upper_bound" "14640"
		elif [[ $input == "5" ]]
		then
			SetOperations "Test Set Equal_range" "14650"
		elif [[ $input == "A" || $input == "a" ]]
		then
			SetAllOperations '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			SetMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintSetOperationsMenu
		fi
	done
}
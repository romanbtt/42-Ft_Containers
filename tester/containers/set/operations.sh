#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function SetOperations()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintSetOperationsMenu
}

function SetAllOperations()
{
	echo -e $BWhite "Test Find" $Color_Off
	$ft "14611"
	$std "14611"
	CompareFiles
	echo -e $BWhite "Test Count" $Color_Off
	$ft "14621"
	$std "14621"
	CompareFiles
	echo -e $BWhite "Test Lower_bound" $Color_Off
	$ft "14631"
	$std "14631"
	CompareFiles
	echo -e $BWhite "Test Upper_bound" $Color_Off
	$ft "14641"
	$std "14641"
	CompareFiles
	echo -e $BWhite "Test Equal_range" $Color_Off
	$ft "14651"
	$std "14651"
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
			SetOperations "Test Find" "14610"
		elif [[ $input == "2" ]]
		then
			SetOperations "Test Count" "14620"
		elif [[ $input == "3" ]]
		then
			SetOperations "Test Lower_bound" "14630"
		elif [[ $input == "4" ]]
		then
			SetOperations "Test Upper_bound" "14640"
		elif [[ $input == "5" ]]
		then
			SetOperations "Test Equal_range" "14650"
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
#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function BidirectionalReverseArithmetic()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintBidirectionalReverseArithmeticMenu
}

function BidirectionalReverseAllArithmetic()
{
	echo -e $BWhite "Test Increment" $Color_Off
	$ft "24311"
	$std "24311"
	CompareFiles
	echo -e $BWhite "Test Decrement" $Color_Off
	$ft "24321"
	$std "24321"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintBidirectionalReverseArithmeticMenu
	fi
}

function PrintBidirectionalReverseArithmeticMenu()
{
	echo -e $BPurple --- Bidirectional Reverse Arithmetic menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Incrementation $Color_Off
	echo -e $BCyan 2 $BWhite - Decremention $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function BidirectionalReverseArithmeticMenu()
{
	clear
	PrintBidirectionalReverseArithmeticMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
		 BidirectionalReverseArithmetic "Test Incrementation" "24310"
		elif [[ $input == "2" ]]
		then
		 BidirectionalReverseArithmetic "Test Decremention" "24320"
		elif [[ $input == "A" || $input == "a" ]]
		then
		 BidirectionalReverseAllArithmetic '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
		 BidirectionalReverseMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintBidirectionalReverseArithmeticMenu
		fi
	done
}

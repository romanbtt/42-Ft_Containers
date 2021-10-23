#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/random_access/random_access.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/random_access_reverse/random_access_reverse.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/bidirectional/bidirectional.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/bidirectional_reverse/bidirectional_reverse.sh

function PrintIteratorsMenu()
{
	echo -e $BPurple --- Iterators menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Random access $Color_Off
	echo -e $BCyan 2 $BWhite - Random access reverse $Color_Off
	echo -e $BCyan 3 $BWhite - Bidirectional $Color_Off
	echo -e $BCyan 4 $BWhite - Bidirectional reverse$Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function IteratorsAll()
{
	RandomAccessAll '0'
	RandomAccessReverseAll '0'
	BidirectionalReverseAll '0'

	if [[ $1 == '1' ]]
	then
		PrintIteratorsMenu
	fi
}

function IteratorsMenu()
{
	clear
	PrintIteratorsMenu

	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessMenu
		elif [[ $input == "2" ]]
		then
			RandomAccessReverseMenu
		elif [[ $input == "3" ]]
		then
			BidirectionalMenu
		elif [[ $input == "4" ]]
		then
			BidirectionalReverseMenu
		elif [[ $input == "A" || $input == "a" ]]
		then
			IteratorsAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			MainMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintIteratorsMenu
		fi
	done
}
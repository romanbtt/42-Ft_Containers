#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/constructors.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/element_access.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/arithmetic.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/relational_operators.sh

function RandomAccessReverseAll()
{
	echo -e $BBlue "Tests Random Access Reverse Constructors" $Color_Off
	echo
	RandomAccessReverseAllConstructors '0'

	echo -e $BBlue "Tests Random Access Reverse Element Access" $Color_Off
	echo
	RandomAccessReverseAllElementAccess '0'
	
	echo -e $BBlue "Tests Random Access Reverse Arithmetic" $Color_Off
	echo
	RandomAccessReverseAllArithmetic '0'

	echo -e $BBlue "Tests Random Access Reverse Relational Operators" $Color_Off
	echo

	echo -e $BWhite "Test Random Access Reverse Relational Operators" $Color_Off
	$ft "22411"
	$std "22411"
	CompareFiles


	if [[ $1 == '1' ]]
	then
		PrintRandomAccessReverseMenu
	fi
}

function PrintRandomAccessReverseMenu()
{
	echo -e $BPurple --- Random Access Reverse menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Constructors $Color_Off
	echo -e $BCyan 2 $BWhite - Element access $Color_Off
	echo -e $BCyan 3 $BWhite - Arithmetic $Color_Off
	echo -e $BCyan 4 $BWhite - Relational operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function RandomAccessReverseMenu()
{
	clear
	PrintRandomAccessReverseMenu
	input=""
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessReverseConstructorsMenu
		elif [[ $input == "2" ]]
		then
			RandomAccessReverseElementAccessMenu
		elif [[ $input == "3" ]]
		then
			RandomAccessReverseArithmeticMenu
		elif [[ $input == "4" ]]
		then
			RandomAccessReverseRelationalOperators
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessReverseAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			IteratorsMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintRandomAccessReverseMenu
		fi
	done
}
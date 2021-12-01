#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/constructors.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/element_access.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/arithmetic.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/relational_operators.sh

function RandomAccessAll()
{
	echo -e $BBlue "Tests Random Access Constructors" $Color_Off
	echo
	RandomAccessAllConstructors '0'

	echo -e $BBlue "Tests Random Access Element Access" $Color_Off
	echo
	RandomAccessAllElementAccess '0'
	
	echo -e $BBlue "Tests Random Access Arithmetic" $Color_Off
	echo
	RandomAccessAllArithmetic '0'

	echo -e $BBlue "Tests Random Access Relational Operators" $Color_Off
	echo

	echo -e $BWhite "Tests Random Access Relational Operators" $Color_Off
	Execute $ft "21411"
	Execute $std "21411"
	echo
	CompareFiles


	if [[ $1 == '1' ]]
	then
		PrintRandomAccessMenu
	fi
}

function PrintRandomAccessMenu()
{
	echo -e $BPurple --- Random Access menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Constructors $Color_Off
	echo -e $BCyan 2 $BWhite - Element access $Color_Off
	echo -e $BCyan 3 $BWhite - Arithmetic $Color_Off
	echo -e $BCyan 4 $BWhite - Relational operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function RandomAccessMenu()
{
	clear
	PrintRandomAccessMenu
	input=""
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			RandomAccessConstructorsMenu
		elif [[ $input == "2" ]]
		then
			RandomAccessElementAccessMenu
		elif [[ $input == "3" ]]
		then
			RandomAccessArithmeticMenu
		elif [[ $input == "4" ]]
		then
			RandomAccessRelationalOperators
		elif [[ $input == "A" || $input == "a" ]]
		then
			RandomAccessAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			IteratorsMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintRandomAccessMenu
		fi
	done
}
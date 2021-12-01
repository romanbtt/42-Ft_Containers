#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/access.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/allocator.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/capacity.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/constructors.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/iterators.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/modifiers.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/relational.sh


function VectorAll()
{
	echo -e $BBlue "Tests Vector Constructors" $Color_Off
	echo
	VectorAllConstructors '0'

	echo -e $BBlue "Tests Vector Iterators" $Color_Off
	echo
	VectorAllIterators '0'
	
	echo -e $BBlue "Tests Vector Capacity" $Color_Off
	echo
	VectorAllCapacity '0'

	echo -e $BBlue "Tests Vector Element Access" $Color_Off
	echo
	VectorAllAccess '0'

	echo -e $BBlue "Tests Vector Modifiers" $Color_Off
	echo
	VectorAllModifiers '0'

	echo -e $BBlue "Tests Vector Allocator" $Color_Off
	echo

	echo -e $BWhite "Test Get_allocator" $Color_Off
	Execute $ft "11611"
	Execute $std "11611"
	echo
	CompareFiles

	echo -e $BBlue "Tests Vector Relational Operators" $Color_Off
	echo

	echo -e $BWhite "Test Relational Operators" $Color_Off
	Execute $ft "11711"
	Execute $std "11711"
	echo
	CompareFiles

	if [[ $1 == '1' ]]
	then
		PrintVectorMenu
	fi
}

function PrintVectorMenu()
{
	echo -e $BPurple --- Vector menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Constructors $Color_Off
	echo -e $BCyan 2 $BWhite - Iterators $Color_Off
	echo -e $BCyan 3 $BWhite - Capacity $Color_Off
	echo -e $BCyan 4 $BWhite - Element access $Color_Off
	echo -e $BCyan 5 $BWhite - Modifiers $Color_Off
	echo -e $BCyan 6 $BWhite - Allocator $Color_Off
	echo -e $BCyan 7 $BWhite - Relational operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorMenu()
{
	clear
	PrintVectorMenu
	input=""
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorConstructorsMenu
		elif [[ $input == "2" ]]
		then
			VectorIteratorsMenu
		elif [[ $input == "3" ]]
		then
			VectorCapacityMenu
		elif [[ $input == "4" ]]
		then
			VectorAccessMenu
		elif [[ $input == "5" ]]
		then
			VectorModifiersMenu
		elif [[ $input == "6" ]]
		then
			VectorGetAllocator
		elif [[ $input == "7" ]]
		then
			VectorRelationalOperators
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			ContainersMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintVectorMenu
		fi
	done
}
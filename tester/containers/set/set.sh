#! /bin/bash
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
source $DIR/observers.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/operations.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/relational.sh


function SetAll()
{
	echo -e $BBlue "Tests Set Constructors" $Color_Off
	echo
	SetAllConstructors '0'

	echo -e $BBlue "Tests Set Iterators" $Color_Off
	echo
	SetAllIterators '0'
	
	echo -e $BBlue "Tests Set Capacity" $Color_Off
	echo
	SetAllCapacity '0'

	echo -e $BBlue "Tests Set Modifiers" $Color_Off
	echo
	SetAllModifiers '0'

	echo -e $BBlue "Tests Set Observers" $Color_Off
	echo
	SetAllObservers '0'

	echo -e $BBlue "Tests Set Operations" $Color_Off
	echo
	SetAllOperations '0'

	echo -e $BBlue "Tests Set Allocator" $Color_Off
	echo

	echo -e $BWhite "Test Get_allocator" $Color_Off
	Execute $ft "14711"
	Execute $std "14711"
	echo
	CompareFiles

	echo -e $BBlue "Tests Set Relational Operators" $Color_Off
	echo

	echo -e $BWhite "Test Relational Operators" $Color_Off
	Execute $ft "14811"
	Execute $std "14811"
	echo
	CompareFiles

	if [[ $1 == '1' ]]
	then
		PrintSetMenu
	fi
}

function PrintSetMenu()
{
	echo -e $BPurple --- Set menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Constructors $Color_Off
	echo -e $BCyan 2 $BWhite - Iterators $Color_Off
	echo -e $BCyan 3 $BWhite - Capacity $Color_Off
	echo -e $BCyan 4 $BWhite - Modifiers $Color_Off
	echo -e $BCyan 5 $BWhite - Observers $Color_Off
	echo -e $BCyan 6 $BWhite - Operations $Color_Off
	echo -e $BCyan 7 $BWhite - Allocator $Color_Off
	echo -e $BCyan 8 $BWhite - Relational operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function SetMenu()
{
	clear
	PrintSetMenu
	input=""
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			SetConstructorsMenu
		elif [[ $input == "2" ]]
		then
			SetIteratorsMenu
		elif [[ $input == "3" ]]
		then
			SetCapacityMenu
		elif [[ $input == "4" ]]
		then
			SetModifiersMenu
		elif [[ $input == "5" ]]
		then
			SetObserversMenu
		elif [[ $input == "6" ]]
		then
			SetOperationsMenu
		elif [[ $input == "7" ]]
		then
			SetGetAllocator
		elif [[ $input == "8" ]]
		then
			SetRelationalOperators
		elif [[ $input == "A" || $input == "a" ]]
		then
			SetAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			ContainersMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintSetMenu
		fi
	done
}
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
source $DIR/observers.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/operations.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/relational.sh


function MapAll()
{
	echo -e $BBlue "Tests Map Constructors" $Color_Off
	echo
	MapAllConstructors '0'

	echo -e $BBlue "Tests Map Iterators" $Color_Off
	echo
	MapAllIterators '0'
	
	echo -e $BBlue "Tests Map Capacity" $Color_Off
	echo
	MapAllCapacity '0'

	echo -e $BBlue "Tests Map Element Access" $Color_Off
	echo

	echo -e $BWhite "Tests Map Element Access" $Color_Off
	Execute $ft "12411"
	Execute $std "12411"
	echo
	CompareFiles

	echo -e $BBlue "Tests Map Modifiers" $Color_Off
	echo
	MapAllModifiers '0'

	echo -e $BBlue "Tests Map Observers" $Color_Off
	echo
	MapAllObservers '0'

	echo -e $BBlue "Tests Map Operations" $Color_Off
	echo
	MapAllOperations '0'

	echo -e $BBlue "Tests Map Allocator" $Color_Off
	echo

	echo -e $BWhite "Test Get_allocator" $Color_Off
	Execute $ft "12811"
	Execute $std "12811"
	echo
	CompareFiles

	echo -e $BBlue "Tests Map Relational Operators" $Color_Off
	echo

	echo -e $BWhite "Test Map Relational Operators" $Color_Off
	Execute $ft "12911"
	Execute $std "12911"
	echo
	CompareFiles

	if [[ $1 == '1' ]]
	then
		PrintMapMenu
	fi
}

function PrintMapMenu()
{
	echo -e $BPurple --- Map menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Constructors $Color_Off
	echo -e $BCyan 2 $BWhite - Iterators $Color_Off
	echo -e $BCyan 3 $BWhite - Capacity $Color_Off
	echo -e $BCyan 4 $BWhite - Element access $Color_Off
	echo -e $BCyan 5 $BWhite - Modifiers $Color_Off
	echo -e $BCyan 6 $BWhite - Observers $Color_Off
	echo -e $BCyan 7 $BWhite - Operations $Color_Off
	echo -e $BCyan 8 $BWhite - Allocator $Color_Off
	echo -e $BCyan 9 $BWhite - Relational operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MapMenu()
{
	clear
	PrintMapMenu
	input=""
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			MapConstructorsMenu
		elif [[ $input == "2" ]]
		then
			MapIteratorsMenu
		elif [[ $input == "3" ]]
		then
			MapCapacityMenu
		elif [[ $input == "4" ]]
		then
			MapAccess
		elif [[ $input == "5" ]]
		then
			MapModifiersMenu
		elif [[ $input == "6" ]]
		then
			MapObserversMenu
		elif [[ $input == "7" ]]
		then
			MapOperationsMenu
		elif [[ $input == "8" ]]
		then
			MapGetAllocator
		elif [[ $input == "9" ]]
		then
			MapRelationalOperators
		elif [[ $input == "A" || $input == "a" ]]
		then
			MapAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			ContainersMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintMapMenu
		fi
	done
}
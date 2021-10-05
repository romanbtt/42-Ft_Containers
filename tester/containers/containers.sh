#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/vector/vector.sh

function PrintContainersMenu()
{
	echo -e $BPurple --- Containers menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Vector $Color_Off
	echo -e $BCyan 2 $BWhite - Map $Color_Off
	echo -e $BCyan 3 $BWhite - Stack $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function ContainersMenu()
{
	clear
	PrintContainersMenu

	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorMenu
		elif [[ $input == "2" ]]
		then
			VectorMenu
		elif [[ $input == "3" ]]
		then
			VectorMenu
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorMenu
		elif [[ $input == "B" || $input == "b" ]]
		then
			MainMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintContainersMenu
		fi
	done
}
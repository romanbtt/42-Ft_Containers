#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/tester/definition.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/tester/containers/containers.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/tester/iterators/iterators.sh

function CompareFiles()
{
	echo
	diff ft std > /dev/null
	if [ $? == 0 ]
	then
		echo -e $BGreen "OK" $Color_Off
	else
		echo -e $BRed "KO" $Color_Off
	fi
	echo
}

function PrintMainMenu()
{
	echo -e $BPurple --- Main menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Containers $Color_Off
	echo -e $BCyan 2 $BWhite - Iterators $Color_Off
	echo -e $BCyan 3 $BWhite - Others $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function MainMenu()
{
	PrintMainMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			ContainersMenu
		elif [[ $input == "2" ]]
		then
			IteratorsMenu
		elif [[ $input == "3" ]]
		then
			ContainersMenu
		elif [[ $input == "A" || $input == "a" ]]
		then
			ContainersMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintMainMenu
		fi
	done
}

clear

make

clear
echo -e $BBlue Ft_Containers tester by rbitett. $Color_Off
echo

MainMenu

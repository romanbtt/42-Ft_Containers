#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/tester/definition.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/tester/containers/containers.sh
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/tester/iterators/iterators.sh

function TestSubject()
{
	echo -e $BWhite $1 $Color_Off
	echo

	echo -n "Please, enter a seed value : "
	read input
	echo

	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft $2 $input
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std $2 $input
	echo
	CompareFiles
	PrintMainMenu
}

function Execute()
{
	start_time=$(date +%s.%3N)

	$1 $2 $3

	end_time=$(date +%s.%3N)
	elapsed=$(echo "scale=3; $end_time - $start_time" | bc)

	echo
	echo "$1 took $elapsed to execute."
}

function CompareFiles()
{
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
	echo -e $BCyan 3 $BWhite - Tests Subject $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function All()
{
	ContainersAll '0'
	IteratorsAll '0'
	TestSubject "Test Subject" "3"
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
			TestSubject "Test Subject" "3"
		elif [[ $input == "A" || $input == "a" ]]
		then
			All
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

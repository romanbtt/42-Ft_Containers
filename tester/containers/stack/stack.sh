#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function StackTests()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintStackMenu
}

function StackAll()
{
	echo -e $BBlue "Tests Stack Constructors" $Color_Off
	$ft "13101"
	$std "13101"
	CompareFiles

	echo -e $BBlue "Tests Map Empty" $Color_Off
	$ft "13201"
	$std "13201"
	CompareFiles
	
	echo -e $BBlue "Tests Map Size" $Color_Off
	$ft "13301"
	$std "13301"
	CompareFiles

	echo -e $BBlue "Tests Map Top" $Color_Off
	$ft "13401"
	$std "13401"
	CompareFiles

	echo -e $BBlue "Tests Map Push" $Color_Off
	$ft "13501"
	$std "13501"
	CompareFiles

	echo -e $BBlue "Tests Map Pop" $Color_Off
	$ft "13601"
	$std "13601"
	CompareFiles

	echo -e $BBlue "Tests Map Relational operators" $Color_Off
	$ft "13701"
	$std "13701"
	CompareFiles

	if [[ $1 == '1' ]]
	then
		PrintStackMenu
	fi
}

function PrintStackMenu()
{
	echo -e $BPurple --- Stack menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Constructors $Color_Off
	echo -e $BCyan 2 $BWhite - Empty $Color_Off
	echo -e $BCyan 3 $BWhite - Size $Color_Off
	echo -e $BCyan 4 $BWhite - Top $Color_Off
	echo -e $BCyan 5 $BWhite - Push $Color_Off
	echo -e $BCyan 6 $BWhite - Pop $Color_Off
	echo -e $BCyan 7 $BWhite - Relational operators $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function StackMenu()
{
	clear
	PrintStackMenu
	input=""
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			StackTests "Test Constructors" "13100"
		elif [[ $input == "2" ]]
		then
			StackTests "Test Empty" "13200"
		elif [[ $input == "3" ]]
		then
			StackTests "Test Size" "13300"
		elif [[ $input == "4" ]]
		then
			StackTests "Test Top" "13400"
		elif [[ $input == "5" ]]
		then
			StackTests "Test Push" "13500"
		elif [[ $input == "6" ]]
		then
			StackTests "Test Pop" "13600"
		elif [[ $input == "7" ]]
		then
			StackTests "Test Relational operators" "13700"
		elif [[ $input == "A" || $input == "a" ]]
		then
			StackAll '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			ContainersMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
			PrintStackMenu
		fi
	done
}
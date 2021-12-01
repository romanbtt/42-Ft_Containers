#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorCapacity()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	echo
	Execute $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	echo
	Execute $std $2
	echo
	CompareFiles
	PrintVectorCapacityMenu
}

function VectorAllCapacity()
{
	echo -e $BWhite "Test Vector Size" $Color_Off
	Execute $ft "11311"
	Execute $std "11311"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Max Size" $Color_Off
	Execute $ft "11321"
	Execute $std "11321"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Resize" $Color_Off
	Execute $ft "11331"
	Execute $std "11331"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Capacity" $Color_Off
	Execute $ft "11341"
	Execute $std "11341"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Empty" $Color_Off
	Execute $ft "11351"
	Execute $std "11351"
	echo
	CompareFiles
	echo -e $BWhite "Test Vector Reserve" $Color_Off
	Execute $ft "11361"
	Execute $std "11361"
	echo
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintVectorCapacityMenu
	fi
}

function PrintVectorCapacityMenu()
{
	echo -e $BPurple --- Vector Capacity menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Size $Color_Off
	echo -e $BCyan 2 $BWhite - Max Size $Color_Off
	echo -e $BCyan 3 $BWhite - Resize $Color_Off
	echo -e $BCyan 4 $BWhite - Capacity $Color_Off
	echo -e $BCyan 5 $BWhite - Empty $Color_Off
	echo -e $BCyan 6 $BWhite - Reserve $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorCapacityMenu()
{
	clear
	PrintVectorCapacityMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorCapacity "Test Vector Size" "11310"
		elif [[ $input == "2" ]]
		then
			VectorCapacity "Test Vector Max Size" "11320"
		elif [[ $input == "3" ]]
		then
			VectorCapacity "Test Vector Resize" "11330"
		elif [[ $input == "4" ]]
		then
			VectorCapacity "Test Vector Capacity" "11340"
		elif [[ $input == "5" ]]
		then
			VectorCapacity "Test Vector Empty" "11350"
		elif [[ $input == "6" ]]
		then
			VectorCapacity "Test Vector Reserve" "11360"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllCapacity '1'
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorCapacityMenu
		fi
	done
}

#! /bin/bash
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
source $DIR/../../definition.sh

function VectorCapacity()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time $ft $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time $std $2
	CompareFiles
	PrintVectorCapacityMenu
}

function VectorAllCapacity()
{
	echo -e $BWhite "Test Size" $Color_Off
	$ft "11311"
	$std "11311"
	CompareFiles
	echo -e $BWhite "Test Max Size" $Color_Off
	$ft "11321"
	$std "11321"
	CompareFiles
	echo -e $BWhite "Test Resize" $Color_Off
	$ft "11331"
	$std "11331"
	CompareFiles
	echo -e $BWhite "Test Capacity" $Color_Off
	$ft "11341"
	$std "11341"
	CompareFiles
	echo -e $BWhite "Test Empty" $Color_Off
	$ft "11351"
	$std "11351"
	CompareFiles
	echo -e $BWhite "Test Reserve" $Color_Off
	$ft "11361"
	$std "11361"
	CompareFiles
	if [[ $1 == '1' ]]
	then
		PrintVectorCapacityMenu
	fi
}

function PrintVectorCapacityMenu()
{
	echo -e $BPurple --- Vector Iterators menu --- $Color_Off
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
			VectorCapacity "Test Size" "11310"
		elif [[ $input == "2" ]]
		then
			VectorCapacity "Test Max Size" "11320"
		elif [[ $input == "3" ]]
		then
			VectorCapacity "Test Resize" "11330"
		elif [[ $input == "4" ]]
		then
			VectorCapacity "Test Capacity" "11340"
		elif [[ $input == "5" ]]
		then
			VectorCapacity "Test Empty" "11350"
		elif [[ $input == "6" ]]
		then
			VectorCapacity "Test Reserve" "11360"
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

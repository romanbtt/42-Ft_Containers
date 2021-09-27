#! /bin/bash

Color_Off='\033[0m'
BRed='\033[1;31m'
BGreen='\033[1;32m'
BYellow='\033[1;33m'
BBlue='\033[1;34m'
BCyan='\033[1;36m'
BWhite='\033[1;37m'

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

function VectorAll()
{
	echo -e $BBlue "Tests Vector Constructors" $Color_Off
	echo

	echo -e $BWhite "Test Default constructor" $Color_Off
	./ft-containers "11111"
	./std-containers "11111"
	CompareFiles
	echo -e $BWhite "Test Fill constructor" $Color_Off
	./ft-containers "11121"
	./std-containers "11121"
	CompareFiles
	echo -e $BWhite "Test Range constructor" $Color_Off
	./ft-containers "11131"
	./std-containers "11131"
	CompareFiles
	echo -e $BWhite "Test Copy constructor" $Color_Off
	./ft-containers "11141"
	./std-containers "11141"
	CompareFiles
	echo -e $BWhite "Test Operator Equal" $Color_Off
	./ft-containers "11151"
	./std-containers "11151"
	CompareFiles
	
	echo -e $BBlue "Tests Vector Iterators" $Color_Off
	echo

	echo -e $BWhite "Test Begin" $Color_Off
	./ft-containers "11211"
	./std-containers "11211"
	CompareFiles
	echo -e $BWhite "Test End" $Color_Off
	./ft-containers "11221"
	./std-containers "11221"
	CompareFiles
	echo -e $BWhite "Test Rbegin" $Color_Off
	./ft-containers "11231"
	./std-containers "11231"
	CompareFiles
	echo -e $BWhite "Test Rend" $Color_Off
	./ft-containers "11241"
	./std-containers "11241"
	CompareFiles
	
	echo -e $BBlue "Tests Vector Capacity" $Color_Off
	echo

	echo -e $BWhite "Test Size" $Color_Off
	./ft-containers "11311"
	./std-containers "11311"
	CompareFiles
	echo -e $BWhite "Test Max Size" $Color_Off
	./ft-containers "11321"
	./std-containers "11321"
	CompareFiles
	echo -e $BWhite "Test Resize" $Color_Off
	./ft-containers "11331"
	./std-containers "11331"
	CompareFiles
	echo -e $BWhite "Test Capacity" $Color_Off
	./ft-containers "11341"
	./std-containers "11341"
	CompareFiles
	echo -e $BWhite "Test Empty" $Color_Off
	./ft-containers "11351"
	./std-containers "11351"
	CompareFiles
	echo -e $BWhite "Test Reserve" $Color_Off
	./ft-containers "11361"
	./std-containers "11361"
	CompareFiles

	echo -e $BBlue "Tests Vector Element Access" $Color_Off
	echo

	echo -e $BWhite "Test Operator[]" $Color_Off
	./ft-containers "11411"
	./std-containers "11411"
	CompareFiles
	echo -e $BWhite "Test At" $Color_Off
	./ft-containers "11421"
	./std-containers "11421"
	CompareFiles
	echo -e $BWhite "Test Front" $Color_Off
	./ft-containers "11431"
	./std-containers "11431"
	CompareFiles
	echo -e $BWhite "Test Back" $Color_Off
	./ft-containers "11441"
	./std-containers "11441"
	CompareFiles

	echo -e $BBlue "Tests Vector Modifiers" $Color_Off
	echo

	echo -e $BWhite "Test Assign" $Color_Off
	./ft-containers "11511"
	./std-containers "11511"
	CompareFiles
	echo -e $BWhite "Test Push_back" $Color_Off
	./ft-containers "11521"
	./std-containers "11521"
	CompareFiles
	echo -e $BWhite "Test Pop_back" $Color_Off
	./ft-containers "11531"
	./std-containers "11531"
	CompareFiles
	echo -e $BWhite "Test Insert" $Color_Off
	./ft-containers "11541"
	./std-containers "11541"
	CompareFiles
	echo -e $BWhite "Test Erase" $Color_Off
	./ft-containers "11551"
	./std-containers "11551"
	CompareFiles
	echo -e $BWhite "Test Swap" $Color_Off
	./ft-containers "11561"
	./std-containers "11561"
	CompareFiles
	echo -e $BWhite "Test Clear" $Color_Off
	./ft-containers "11571"
	./std-containers "11571"
	CompareFiles

	echo -e $BBlue "Tests Vector Allocator" $Color_Off
	echo

	echo -e $BWhite "Test Get_allocator" $Color_Off
	./ft-containers "11611"
	./std-containers "11611"
	CompareFiles

	PrintVectorMenu
}

function VectorConstructor()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time ./ft-containers $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time ./std-containers $2
	CompareFiles
	PrintVectorConstructorsMenu
}

function VectorAllConstructors()
{
	echo -e $BWhite "Test Default constructor" $Color_Off
	./ft-containers "11111"
	./std-containers "11111"
	CompareFiles
	echo -e $BWhite "Test Fill constructor" $Color_Off
	./ft-containers "11121"
	./std-containers "11121"
	CompareFiles
	echo -e $BWhite "Test Range constructor" $Color_Off
	./ft-containers "11131"
	./std-containers "11131"
	CompareFiles
	echo -e $BWhite "Test Copy constructor" $Color_Off
	./ft-containers "11141"
	./std-containers "11141"
	CompareFiles
	echo -e $BWhite "Test Operator Equal" $Color_Off
	./ft-containers "11151"
	./std-containers "11151"
	CompareFiles
	PrintVectorConstructorsMenu
}

function PrintVectorConstructorsMenu()
{
	echo -e $BPurple --- Vector Constructor menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Default constructor $Color_Off
	echo -e $BCyan 2 $BWhite - Fill constructor $Color_Off
	echo -e $BCyan 3 $BWhite - Range constructor $Color_Off
	echo -e $BCyan 4 $BWhite - Copy constructor $Color_Off
	echo -e $BCyan 5 $BWhite - Operator = $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorConstructorsMenu()
{
	clear
	PrintVectorConstructorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorConstructor "Test Default constructor" "11110"
		elif [[ $input == "2" ]]
		then
			VectorConstructor "Test Fill constructor" "11120"
		elif [[ $input == "3" ]]
		then
			VectorConstructor "Test Range constructor" "11130"
		elif [[ $input == "4" ]]
		then
			VectorConstructor "Test Copy constructor" "11140"
		elif [[ $input == "5" ]]
		then
			VectorConstructor "Test Operator Equal" "11150"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllConstructors
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorConstructorsMenu
		fi
	done
}

function VectorIterator()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time ./ft-containers $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time ./std-containers $2
	CompareFiles
	PrintVectorIteratorsMenu
}

function VectorAllIterators()
{
	echo -e $BWhite "Test Begin" $Color_Off
	./ft-containers "11211"
	./std-containers "11211"
	CompareFiles
	echo -e $BWhite "Test End" $Color_Off
	./ft-containers "11221"
	./std-containers "11221"
	CompareFiles
	echo -e $BWhite "Test Rbegin" $Color_Off
	./ft-containers "11231"
	./std-containers "11231"
	CompareFiles
	echo -e $BWhite "Test Rend" $Color_Off
	./ft-containers "11241"
	./std-containers "11241"
	CompareFiles
	PrintVectorIteratorsMenu
}

function PrintVectorIteratorsMenu()
{
	echo -e $BPurple --- Vector Iterators menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Begin $Color_Off
	echo -e $BCyan 2 $BWhite - End $Color_Off
	echo -e $BCyan 3 $BWhite - Rbegin $Color_Off
	echo -e $BCyan 4 $BWhite - Rend $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorIteratorsMenu()
{
	clear
	PrintVectorIteratorsMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorIterator "Test Begin" "11210"
		elif [[ $input == "2" ]]
		then
			VectorIterator "Test End" "11220"
		elif [[ $input == "3" ]]
		then
			VectorIterator "Test Rbegin" "11230"
		elif [[ $input == "4" ]]
		then
			VectorIterator "Test Rend" "11240"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllIterators
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorIteratorsMenu
		fi
	done
}

function VectorCapacity()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time ./ft-containers $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time ./std-containers $2
	CompareFiles
	PrintVectorCapacityMenu
}

function VectorAllCapacity()
{
	echo -e $BWhite "Test Size" $Color_Off
	./ft-containers "11311"
	./std-containers "11311"
	CompareFiles
	echo -e $BWhite "Test Max Size" $Color_Off
	./ft-containers "11321"
	./std-containers "11321"
	CompareFiles
	echo -e $BWhite "Test Resize" $Color_Off
	./ft-containers "11331"
	./std-containers "11331"
	CompareFiles
	echo -e $BWhite "Test Capacity" $Color_Off
	./ft-containers "11341"
	./std-containers "11341"
	CompareFiles
	echo -e $BWhite "Test Empty" $Color_Off
	./ft-containers "11351"
	./std-containers "11351"
	CompareFiles
	echo -e $BWhite "Test Reserve" $Color_Off
	./ft-containers "11361"
	./std-containers "11361"
	CompareFiles
	PrintVectorCapacityMenu
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
			VectorAllCapacity
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

function VectorAccess()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time ./ft-containers $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time ./std-containers $2
	CompareFiles
	PrintVectorAccessMenu
}

function VectorAllAccess()
{
	echo -e $BWhite "Test Operator[]" $Color_Off
	./ft-containers "11411"
	./std-containers "11411"
	CompareFiles
	echo -e $BWhite "Test At" $Color_Off
	./ft-containers "11421"
	./std-containers "11421"
	CompareFiles
	echo -e $BWhite "Test Front" $Color_Off
	./ft-containers "11431"
	./std-containers "11431"
	CompareFiles
	echo -e $BWhite "Test Back" $Color_Off
	./ft-containers "11441"
	./std-containers "11441"
	CompareFiles
	PrintVectorAccessMenu
}

function PrintVectorAccessMenu()
{
	echo -e $BPurple --- Vector Element Access menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Operator[] $Color_Off
	echo -e $BCyan 2 $BWhite - At $Color_Off
	echo -e $BCyan 3 $BWhite - Front $Color_Off
	echo -e $BCyan 4 $BWhite - Back $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorAccessMenu()
{
	clear
	PrintVectorAccessMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorAccess "Test Operator[]" "11410"
		elif [[ $input == "2" ]]
		then
			VectorAccess "Test At" "11420"
		elif [[ $input == "3" ]]
		then
			VectorAccess "Test Front" "11430"
		elif [[ $input == "4" ]]
		then
			VectorAccess "Test Back" "11440"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllAccess
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorAccessMenu
		fi
	done
}

function VectorModifiers()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time ./ft-containers $2
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time ./std-containers $2
	CompareFiles
	PrintVectorModifiersMenu
}

function VectorAllModifiers()
{
	echo -e $BWhite "Test Assign" $Color_Off
	./ft-containers "11511"
	./std-containers "11511"
	CompareFiles
	echo -e $BWhite "Test Push_back" $Color_Off
	./ft-containers "11521"
	./std-containers "11521"
	CompareFiles
	echo -e $BWhite "Test Pop_back" $Color_Off
	./ft-containers "11531"
	./std-containers "11531"
	CompareFiles
	echo -e $BWhite "Test Insert" $Color_Off
	./ft-containers "11541"
	./std-containers "11541"
	CompareFiles
	echo -e $BWhite "Test Erase" $Color_Off
	./ft-containers "11551"
	./std-containers "11551"
	CompareFiles
	echo -e $BWhite "Test Swap" $Color_Off
	./ft-containers "11561"
	./std-containers "11561"
	CompareFiles
	echo -e $BWhite "Test Clear" $Color_Off
	./ft-containers "11571"
	./std-containers "11571"
	CompareFiles
	PrintVectorModifiersMenu
}

function PrintVectorModifiersMenu()
{
	echo -e $BPurple --- Vector Modifiers menu --- $Color_Off
	echo -e $BCyan 1 $BWhite - Assign $Color_Off
	echo -e $BCyan 2 $BWhite - Push_back $Color_Off
	echo -e $BCyan 3 $BWhite - Pop_back $Color_Off
	echo -e $BCyan 4 $BWhite - Insert $Color_Off
	echo -e $BCyan 5 $BWhite - Erase $Color_Off
	echo -e $BCyan 6 $BWhite - Swap $Color_Off
	echo -e $BCyan 7 $BWhite - Clear $Color_Off
	echo -e $BGreen A $BWhite - All $Color_Off
	echo -e $BYellow B $BWhite - Back $Color_Off
	echo -e $BRed E $BWhite - Exit $Color_Off
	echo -ne $BBlue Enter your choice : $Color_Off
}

function VectorModifiersMenu()
{
	clear
	PrintVectorModifiersMenu
	while read input
	do
		clear
		if [[ $input == "1" ]]
		then
			VectorModifiers "Test Assign" "11510"
		elif [[ $input == "2" ]]
		then
			VectorModifiers "Test Push_back" "11520"
		elif [[ $input == "3" ]]
		then
			VectorModifiers "Test Pop_back" "11530"
		elif [[ $input == "4" ]]
		then
			VectorModifiers "Test Insert" "11540"
		elif [[ $input == "5" ]]
		then
			VectorModifiers "Test Erase" "11550"
		elif [[ $input == "6" ]]
		then
			VectorModifiers "Test Swap" "11560"
		elif [[ $input == "7" ]]
		then
			VectorModifiers "Test Clear" "11570"
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAllModifiers
		elif [[ $input == "B" || $input == "b" ]]
		then
			VectorMenu
		elif [[ $input == "E" || $input == "e" ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorModifiersMenu
		fi
	done
}

function VectorGetAllocator()
{
	echo -e $BWhite $1 $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	time ./ft-containers "11610"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	time ./std-containers "11610"
	CompareFiles
	PrintVectorMenu
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
		elif [[ $input == "A" || $input == "a" ]]
		then
			VectorAll
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
			ContainersMenu
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

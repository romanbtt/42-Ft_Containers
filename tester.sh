#! /bin/bash

Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White

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

function VectorDefaultConstructor()
{
	echo -e $BWhite "Test Default constructor" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	./ft-containers "11110"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	./std-containers "11110"
	CompareFiles
	PrintVectorConstructorsMenu
}

function VectorFillConstructor()
{
	echo -e $BWhite "Test Fill constructor" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	./ft-containers "11120"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	./std-containers "11120"
	CompareFiles
	PrintVectorConstructorsMenu
}

function VectorRangeConstructor()
{
	echo -e $BWhite "Test Range constructor" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	./ft-containers "11130"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	./std-containers "11130"
	CompareFiles
	PrintVectorConstructorsMenu
}

function VectorCopyConstructor()
{
	echo -e $BWhite "Test Copy constructor" $Color_Off
	echo
	echo -e $BBlue "Namespace FT" $Color_Off
	./ft-containers "11140"
	echo
	echo -e $BBlue "Namespace STD" $Color_Off
	./std-containers "11140"
	CompareFiles
	PrintVectorConstructorsMenu
}

function VectorConstructorsMenu()
{
	clear
	PrintVectorConstructorsMenu
	while read input
	do
		clear
		if [[ $input == '1' ]]
		then
			VectorDefaultConstructor
		elif [[ $input == '2' ]]
		then
			VectorFillConstructor
		elif [[ $input == '3' ]]
		then
			VectorRangeConstructor
		elif [[ $input == '4' ]]
		then
			VectorCopyConstructor
		elif [[ $input == '5' ]]
		then
			VectorConstructorsMenu
		elif [[ $input == '6' ]]
		then
			VectorConstructorsMenu
		elif [[ $input == 'A' || $input == 'a' ]]
		then
			VectorConstructorsMenu
		elif [[ $input == 'B' || $input == 'b' ]]
		then
			VectorMenu
		elif [[ $input == 'E' || $input == 'e' ]]
		then
			exit
		else
			echo -e $BRed Command not found! $Color_Off
			echo
		PrintVectorConstructorsMenu
		fi
	done
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
	while read input
	do
		clear
		if [ $input == '1' ]
		then
			VectorConstructorsMenu
		elif [ $input == '2' ]
		then
			VectorConstructorsMenu
		elif [ $input == '3' ]
		then
			VectorConstructorsMenu
		elif [ $input == '4' ]
		then
			VectorConstructorsMenu
		elif [ $input == '5' ]
		then
			VectorConstructorsMenu
		elif [ $input == '6' ]
		then
			VectorConstructorsMenu
		elif [[ $input == 'A' || $input == 'a' ]]
		then
			VectorConstructorsMenu
		elif [[ $input == 'B' || $input == 'b' ]]
		then
			ContainersMenu
		elif [[ $input == 'E' || $input == 'e' ]]
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
		if [ $input == '1' ]
		then
			VectorMenu
		elif [ $input == '2' ]
		then
			VectorMenu
		elif [ $input == '3' ]
		then
			VectorMenu
		elif [[ $input == 'A' || $input == 'a' ]]
		then
			VectorMenu
		elif [[ $input == 'B' || $input == 'b' ]]
		then
			MainMenu
		elif [[ $input == 'E' || $input == 'e' ]]
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
		if [ $input == '1' ]
		then
			ContainersMenu
		elif [ $input == '2' ]
		then
			ContainersMenu
		elif [ $input == '3' ]
		then
			ContainersMenu
		elif [[ $input == 'A' || $input == 'a' ]]
		then
			ContainersMenu
		elif [[ $input == 'E' || $input == 'e' ]]
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

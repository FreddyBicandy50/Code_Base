#!/bin/bash
cat start.txt
rm -f pwdtemp.txt && rm -f keytemp.txt; 
declare -i choice=1;
read -p ">" choice

while [ true ]
do
	if [ $choice -eq "1" ]; then
 		touch pwdtemp.txt;
 		touch keytemp.txt;
		read -p "username:" username;
		read -p "password:" password; 
		./Wallet $username $password; 

		break;
	elif [ $choice -eq "2" ]; then
 		read -p "username:" username;
		read -p "password:" password;
		./Wallet --register $username $password;
		break;
	elif [ $choice -eq "3" ]; then
  		echo "exiting..."; 
		break;
	else  
  		echo "Invalid input!"; 
		break;
	fi 
done
rm -f pwdtemp.txt && rm -f keytemp.txt;

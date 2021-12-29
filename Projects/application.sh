#!/bin/bash
cat start.txt
rm pwdtemp.txt && rm keytemp.txt; 
make Wallet
declare -i choice=1;
#read choice

while [ true ]
do
	if [ $choice -eq "1" ]; then
 		touch pwdtemp.txt;
 		touch keytemp.txt;
		#read -p "username:" username;
		#read -p "password:" password;
		username="tommy"
		password="deta"
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
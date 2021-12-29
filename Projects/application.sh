#!/bin/bash
cat start.txt
declare i choice;
read choice
while [ true ]
do
	if [ $choice -eq "1" ]; then
 		touch pwdtemp.txt;
 		touch keytemp.txt;
		read -p "username:" username;
		read -p "password:" password;
		./Wallet $username $password;
		rm pwdtemp.txt && rm keytemp.txt; 
		break
	elif [ $choice -eq "2" ]; then
 		read -p "username:" username;
		read -p "password:" password;
		./Wallet --register $username $password;
		break;
	else  
  		echo "exiting..."; 
		break;
	fi 
done
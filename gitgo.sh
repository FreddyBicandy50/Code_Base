#!/bin/bash
#git config --global credential.helper.cache
export filename
echo "<filename>" && read filename
cp -f  $filename gitgo.sh /home/null/Code
cd /home/null/Code
sudo bash push.sh

#!/bin/bash
#git config --global credential.helper.cache
cp -f project.cpp gitgo.sh /home/null/Code
cd nordlight-syntax/styles
cp -f base.less colors.less /home/null/Code
cd /home/null/Code
sudo bash push.sh

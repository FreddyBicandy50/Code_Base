#!/bin/bash
#git config --global credential.helper.cache
git status
git add push.sh
git commit -m "Directory"
git branch -M main 
git push -f origin main

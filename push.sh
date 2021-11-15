#!/bin/bash
#git config --global credential.helper.cache
git status
git add project.cpp
git add gitgo.sh
git add settings.json
git commit -m "new"
git branch -M main
git remote add origin https://github.com/FreddyBicandy50/Code.git
git push -f origin main

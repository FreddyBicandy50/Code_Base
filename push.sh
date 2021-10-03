#!/bin/bash
#git config --global credential.helper.cache
git status
git add file.c
git commit -m "new"
git branch -M main
git remote add origin https://github.com/FreddyBicandy50/source_code.git
git push -f origin main

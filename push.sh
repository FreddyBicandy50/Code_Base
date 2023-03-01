#!/bin/bash
#git config --global credential.helper.cache
cd git
git status
git add --all /home/null/git
git commit -m "Projects"
git branch -M main
git push -f origin main

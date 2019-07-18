#!/bin/bash
clear
echo ----------------------------
echo KIPR Wallaby Backup Utility 
echo By: Zachary Sasser          
echo ----------------------------

read -p "What is the Wallaby Serial Number?: " wallaby
echo

clear

echo ----------------------------
echo KIPR Wallaby Backup Utility 
echo By: Zachary Sasser          
echo ----------------------------

echo CREATING FOLDERS...
mkdir Wallaby-Backups
cd Wallaby-Backups
mkdir Wallaby-$wallaby

echo GATHERING PROGRAMS FROM WALLABY...
scp -r root@192.168.124.1:~/Documents/KISS/* Wallaby-$wallaby

echo PROGRAM BACKUP COMPLETE.

echo REMOVING UNWANTED FILES...
cd Wallaby-$wallaby

rm -r bin 
rm -r data
rm -r lib
rm -r src
rm -r include

rm *.json
rm tester.c
echo FINISHED.

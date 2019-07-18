@echo off
cls
echo -----------------------------
echo ^|KIPR Wallaby Backup Utility^|
echo ^|Created by: Zachary Sasser ^|
echo -----------------------------

set /p wallaby="What is the Wallaby Serial Number?: "

cls

echo -----------------------------
echo ^|KIPR Wallaby Backup Utility^|
echo ^|Created by: Zachary Sasser ^|
echo -----------------------------
echo CREATING FOLDERS...
mkdir Wallaby-Backups
cd Wallaby-Backups
mkdir Wallaby-%wallaby%


echo GRABBING PROGRAMS FROM WALLABY...
scp -r root@192.168.124.1:~/Documents/KISS/* Wallaby-%wallaby%

echo PROGRAM BACKUP COMPLETE.

echo REMOVING UNWANTED FILES...
cd Wallaby-%wallaby%

rmdir bin /S /Q
rmdir data /S /Q
rmdir lib /S /Q
rmdir src /S /Q
rmdir include /S /Q


del *.json
del tester.c
echo FINISHED.
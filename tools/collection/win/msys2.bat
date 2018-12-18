@echo off

set SCRIPT_PATH=%~dp0
set SCRIPT_DISK=%SCRIPT_PATH:~0,2%

set CHERE_INVOKING=1
set OLD_PATH=%PATH%
set PATH=%HOMEDRIVE%\Program Files\Python36;%SCRIPT_DISK%\tools\vim\vim81;%PATH%
set SCRIPT_PATH=
set SCRIPT_DISK=
bash.exe
set PATH=%OLD_PATH%

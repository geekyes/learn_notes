@echo off

set SCRIPT_PATH=%~dp0
set SCRIPT_DISK=%SCRIPT_PATH:~0,2%

start %SCRIPT_DISK%\tools\rt_thread_env\tools\ConEmu\ConEmu64.exe


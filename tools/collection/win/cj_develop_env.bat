@echo off

set SCRIPT_PATH=%~dp0
set SCRIPT_DISK=%SCRIPT_PATH:~0,2%

set PATH=%SCRIPT_DISK%\tools\arm_none_tool_chain\bin;%PATH%
set PATH=%SCRIPT_DISK%\tools\msys2\mingw64\bin;%SCRIPT_DISK%\tools\msys2\usr\bin;%PATH%
set PATH=C:\ProgramData\Anaconda3;C:\ProgramData\Anaconda3\Scripts;%PATH%
set PATH=%SCRIPT_DISK%\tools\bin;%PATH%
set HOME=%SCRIPT_DISK%\home

start %SCRIPT_DISK%\tools\conemu\ConEmu64.exe -title cj_develop_env -dir "%SCRIPT_DISK%\projects"


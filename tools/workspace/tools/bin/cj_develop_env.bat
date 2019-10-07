@echo off

set MSYS2_PATH=d:\msys2

if NOT EXIST %MSYS2_PATH%\usr\bin goto install_msys2

set SCRIPT_PATH=%~dp0
set SCRIPT_DISK=%SCRIPT_PATH:~0,2%
set WORKSPACE_PATH=%SCRIPT_PATH%..\..

set HOME=%WORKSPACE_PATH%\home
set XDG_CONFIG_HOME=%HOME%
set PYTHONHOME=%WORKSPACE_PATH%\tools\python3

set PATH=%WORKSPACE_PATH%\tools\bin;%PATH%
set PATH=%MSYS2_PATH%\usr\bin;%MSYS2_PATH%\mingw64\bin;%MSYS2_PATH%\mingw32\bin;%PATH%
set PATH=%PYTHONHOME%;%PATH%
set PATH=%WORKSPACE_PATH%\tools\vim;%WORKSPACE_PATH%\tools\neovim\bin;%PATH%

start %WORKSPACE_PATH%\tools\conemu\ConEmu64.exe -title chenjiang_develop_env -dir "%WORKSPACE_PATH%\projects"
goto this_script_end

:install_msys2
set msys2="www.msys2.org"
echo Please visit %msys2% and install msys2 as %MSYS2_PATH% 
echo OR modify "MSYS2_PATH ENV" of this script.
pause
exit -1

:this_script_end


@echo off

set SCRIPT_PATH=%~dp0
set SCRIPT_DISK=%SCRIPT_PATH:~0,2%
set WORKSPACE_PATH=%SCRIPT_PATH%..\..

set HOME=%WORKSPACE_PATH%\home
set XDG_CONFIG_HOME=%HOME%
set PYTHONHOME=%WORKSPACE_PATH%\tools\python3
set PATH=%WORKSPACE_PATH%\tools\clang\LLVM\bin;%WORKSPACE_PATH%\tools\cmake\bin;%WORKSPACE_PATH%\tools\rt_thread_env\tools\bin;%PATH%
set PATH=%WORKSPACE_PATH%\tools\bin;%PATH%
set PATH=%WORKSPACE_PATH%\tools\git\mingw64\bin;%WORKSPACE_PATH%\tools\git\usr\bin;%PATH%
set PATH=%WORKSPACE_PATH%\tools\python3;%PATH%
set PATH=%WORKSPACE_PATH%\tools\ctags;%WORKSPACE_PATH%\tools\gnu_global\bin;%WORKSPACE_PATH%\tools\vim;%WORKSPACE_PATH%\tools\neovim\bin;%PATH%

start %WORKSPACE_PATH%\tools\conemu\ConEmu64.exe -title cj_develop_env -dir "%WORKSPACE_PATH%\projects"


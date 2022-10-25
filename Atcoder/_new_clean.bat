@echo off
setlocal enabledelayedexpansion 
set /p filename=
set "filename=%filename%.cpp"
if exist %filename% (
    set /p "ch=%filename% exists- Continue anyway?(y/n)"
    if not "!ch!"=="y" (
        exit
    ) else (
        del %filename%
    )
)
copy _tpl.cpp %filename%
rem start !filename!.cpp
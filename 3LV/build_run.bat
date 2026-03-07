@echo off
chcp 1251 > nul

set EXE=example.exe
set CHARSET=-finput-charset=UTF-8 -fexec-charset=CP1251

del %EXE% > nul

g++ %CHARSET% menu_items.cpp menu_items.hpp menu_functions.cpp menu_functions.hpp menu.hpp main.cpp -o %EXE%

%EXE%
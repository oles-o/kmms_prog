@echo off
chcp 1251 > nul

set EXE=example.exe
set CHARSET=-finput-charset=UTF-8 -fexec-charset=CP1251

del %EXE% > nul

g++ %CHARSET% travel_items.cpp travel_items.hpp travel_functions.cpp travel_functions.hpp travel.hpp main.cpp -o %EXE%

%EXE%

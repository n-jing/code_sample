rem read file to variable without newline(\n)
@echo off
setlocal enabledelayedexpansion

set outstring=
for /f "delims=" %%A in (config.json) do set outstring=!outstring!%%A

echo outstring=%outstring%

rem get file context to variable
@echo off
set JSON=^&Type config.json


rem get year, month, day
@echo off

for /F "skip=1 delims=" %%F in ('
    wmic PATH Win32_LocalTime GET Day^,Month^,Year /FORMAT:TABLE
') do (
    for /F "tokens=1-3" %%L in ("%%F") do (
        set CurrDay=0%%L
        set CurrMonth=0%%M
        set CurrYear=%%N
    )
)
set CurrDay=%CurrDay:~-2%
set CurrMonth=%CurrMonth:~-2%


:: timestamp YYYY-MM-DD_HH-MM-SS
@echo off
for /f "delims=" %%a in ('wmic OS Get localdatetime  ^| find "."') do set dt=%%a
set dt=%dt:~0,4%-%dt:~4,2%-%dt:~6,2%_%dt:~8,2%-%dt:~10,2%-%dt:~12,2%
echo %dt%

:: timestamp YYYYMMDD_HHMMSS
@echo off
for /f "delims=" %%a in ('wmic OS Get localdatetime  ^| find "."') do set dt=%%a
set dt=%dt:~0,8%_%dt:~8,6%
echo %dt%
pause

:date_time_func
:: timestamp YYYY-MM-DD_HH-MM-SS
@echo off
for /f "delims=" %%a in ('wmic OS Get localdatetime  ^| find "."') do set dt=%%a
set date_time=%dt:~0,4%-%dt:~4,2%-%dt:~6,2%_%dt:~8,2%-%dt:~10,2%-%dt:~12,2%
goto :eof


rem get file name and file extension
 @echo off

call :setfile ..\Desktop\fs.cfg
echo %file% = %filepath% + %filename% + %fileextension%
goto :eof

:setfile
set file=%~f1
set filepath=%~dp1
set filename=%~n1
set fileextension=%~x1
goto :eof

rem read file to variable without newline(\n)
@echo off
setlocal enabledelayedexpansion

set outstring=
for /f "delims=" %%A in (config.json) do set outstring=!outstring!%%A

echo outstring=%outstring%

rem get file context to variable
@echo off
set JSON=^&Type config.json

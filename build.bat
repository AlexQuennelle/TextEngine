@echo off
setlocal ENABLEDELAYEDEXPANSION
set buildType=%1
if "%~1" == "" set /p "buildType=Build type: "
for %%a in ("%~dp0") do set "parent=%%~nxa"
if not exist "bin" mkdir bin
set "CMAKE_BUILD_TYPE_VAL="
if /i "%buildType%" == "release" (
	set buildType="Release"
) else (
	set buildType="Debug"
)
if not exist "build" mkdir "build"
cd build
cmake -DCMAKE_BUILD_TYPE="!buildType!" .. -G "Unix Makefiles"
echo Building Executable
make
if /i "!buildType!" == "Debug" (
	cd ../bin
	start %parent%
)
endlocal
pause
exit

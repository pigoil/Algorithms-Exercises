@echo off
set /p name=Please input the file name.
md .\%date:~0,4%%date:~5,2%%date:~8,2%_%name%
cd .\%date:~0,4%%date:~5,2%%date:~8,2%_%name%
echo /*%name%*/ >.\%name%.cpp
echo #include ^<iostream^> >>.\%name%.cpp
echo.>>.\%name%.cpp
echo using namespace std;>>.\%name%.cpp
echo.>>.\%name%.cpp
echo int main()>>.\%name%.cpp
echo {>>.\%name%.cpp
echo.>>.\%name%.cpp
echo }>>.\%name%.cpp
start .\%name%.cpp


set SOURCE_PATH=%cd%\src
set BUILD_PATH=%cd%\build

if "%1"=="clean" (
    rmdir /S /Q %BUILD_PATH%
)

cmake -S %SOURCE_PATH% -B %BUILD_PATH% -G Ninja
cmake --build %BUILD_PATH%

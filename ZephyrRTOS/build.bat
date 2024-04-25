
set SOURCE_PATH=%cd%\src
set BUILD_PATH=%cd%\build
set ZEPHYR_PRJ_PATH=%HOMEPATH%\zephyrproject
set VENV_PATH=%ZEPHYR_PRJ_PATH%\.venv

call %VENV_PATH%\Scripts\activate

if "%1"=="clean" (
    rmdir /S /Q %BUILD_PATH%
)

pushd %ZEPHYR_PRJ_PATH%
west build -b rpi_pico -s %SOURCE_PATH% -d %BUILD_PATH%
popd
deactivate
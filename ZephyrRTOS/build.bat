

set SOURCE_PATH=%cd%\src
set BUILD_PATH=%cd%\build
set CUSTOM_BOARD=boards\raspberrypi\rpi_pico_custom
set ZEPHYR_PRJ_PATH=%ZEPHYR_SDK_PATH%\..
set VENV_PATH=%ZEPHYR_PRJ_PATH%\.venv

call %VENV_PATH%\Scripts\activate

if "%1"=="clean" (
    rmdir /S /Q %BUILD_PATH%
)

rmdir /S /Q %ZEPHYR_PRJ_PATH%\zephyr\%CUSTOM_BOARD%
xcopy /E /I %SOURCE_PATH%\%CUSTOM_BOARD% %ZEPHYR_PRJ_PATH%\zephyr\%CUSTOM_BOARD%
pushd %ZEPHYR_PRJ_PATH%
west build -b rpi_pico_custom -s %SOURCE_PATH% -d %BUILD_PATH%
popd
deactivate
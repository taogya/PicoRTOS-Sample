# FreeRTOS
FreeRTOSを使用したプログラム。<br>

## ビルド手順
- Windows<br>
    ```sh
    $ rd /s /q "src/build"
    $ cmake -S src -B src/build -G Ninja
    $ cmake --build src/build
    ```
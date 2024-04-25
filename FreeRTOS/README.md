# FreeRTOS
FreeRTOSを使用したプログラム。<br>
https://github.com/FreeRTOS/FreeRTOS <br>

## ビルド手順
```sh
$ rm -rf src/build
$ cmake -S src -B src/build -G Ninja
$ cmake --build src/build
```
# BareMetal
OSを乗せないタイマー割り込みを使用したプログラム。<br>

## ビルド手順
```sh
$ rm -rf src/build
$ cmake -S src -B src/build -G Ninja
$ cmake --build src/build
```
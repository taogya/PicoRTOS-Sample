# ZephyrRTOS
ZephyrRTOSを使用したプログラム。<br>
https://docs.zephyrproject.org/latest/develop/getting_started/index.html <br>

## ビルド手順

> [!WARNING]
> bat および sh でbuildする場合は，以下を実行してから行うこと。
> ```sh
> $ ZEPHYR_VENV_PATH=~/zephyrproject/.venv
> $ $ZEPHYR_VENV_PATH/bin/activate
> ```

```sh
$ SOURCE_PATH=&(pwd)/src
$ BUILD_PATH=&(pwd)/build
$ pushd $ZEPHYR_SDK_PATH/../zephyr
$ . .venv/bin/activate
$ west build -b ./myboard -s $SOURCE_PATH -d $BUILD_PATH
$ popd
```

## 参考
https://github.com/Bucknalla/pico-zephyr-serial
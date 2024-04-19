# PicoRTOS-Sample
**リポジトリクローン**<br>
```sh
$ git clone --recurse-submodules https://github.com/taogya/PicoRTOS-Sample.git
```

**各サンプルについて**<br>
- [BareMetal](./BareMetal/)<br>
    OSを乗せないタイマー割り込みを使用したプログラム。<br>
- [FreeRTOS](./FreeRTOS/)<br>
    FreeRTOSを使用したプログラム。<br>

## 環境構築
- Windows<br>
    以下のインストーラーを使用して，SDKをインストール。<br>
    https://www.raspberrypi.com/news/raspberry-pi-pico-windows-installer/ <br>

    ユーザー環境変数を編集する。([Windows_環境変数編集画面.bat](./Windows_環境変数編集画面.bat) を実行すると開けます。)<br>
        - `PICO_SDK_PATH` を新規追加。<br>
            値: `C:\Program Files\Raspberry Pi\Pico SDK v1.5.1\pico-sdk` <br>
        - `PICO_TOOLCHAIN_PATH` を新規追加。<br>
            値: `C:\Program Files\Raspberry Pi\Pico SDK v1.5.1\gcc-arm-none-eabi\bin` <br>
        - `PATH` に追加。<br>
            値: `C:\Program Files\Raspberry Pi\Pico SDK v1.5.1\gcc-arm-none-eabi\bin` <br>

## プロジェクト作成方法
以下のコマンドで，プロジェクトジェネレータを開いて作成する。<br>
```sh
$ python lib/pico-project-generator/pico_project.py --gui
```

## ビルド手順
各サンプルの`README`を参照のこと。
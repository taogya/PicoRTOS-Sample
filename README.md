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
- [ZephyrRTOS](./ZephyrRTOS/)<br>
    ZephyrRTOSを使用したプログラム。<br>

## プロジェクト作成方法
以下のコマンドで，プロジェクトジェネレータを開いて作成する。<br>
```sh
$ python lib/pico-project-generator/pico_project.py --gui
```

> [!WARNING]
> ZephyrRTOSはこのコマンドは使用しません。

## ビルド手順
各サンプルの`README`を参照のこと。
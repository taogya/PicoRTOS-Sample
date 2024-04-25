# BareMetal
OSを乗せないタイマー割り込みを使用したプログラム。<br>

## 環境構築
https://github.com/raspberrypi/pico-sdk <br>
`PICO_SDK_PATH`, `PICO_TOOLCHAIN_PATH`の環境変数を設定する必要があります。
### Windows 例
- `PICO_SDK_PATH` を新規追加。<br>
    値: `C:\Program Files\Raspberry Pi\Pico SDK v1.5.1\pico-sdk` <br>
- `PICO_TOOLCHAIN_PATH` を新規追加。<br>
    値: `C:\Program Files\Raspberry Pi\Pico SDK v1.5.1\gcc-arm-none-eabi\bin` <br>
- `PATH` に追加。<br>
    値: `C:\Program Files\Raspberry Pi\Pico SDK v1.5.1\gcc-arm-none-eabi\bin` <br>

> [!NOTE]
> Windowsは以下のインストーラが使用できます。<br>
> https://www.raspberrypi.com/news/raspberry-pi-pico-windows-installer/ <br>
> <br>
> ユーザー環境変数を編集する。([環境変数編集画面を開くバッチ](/Windows_ShowEnvSettings.bat) を実行すると開けます。)<br>


## ビルド手順
`build.sh` または，`build.bat`の内容を確認して，実行してください。

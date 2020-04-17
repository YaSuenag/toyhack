ToyHack
===================

ToyHackは、子供向け玩具の基盤に含まれる各種アクション（音声、発光等）をRaspberry Piからコントロールするためのライブラリ・アプリケーションスイートです。

# 依存ライブラリ

* [Wiring Pi](http://wiringpi.com/)

# 動作確認ハードウェア

* Raspberry Pi Type B
* Raspberry Pi 2
    * 必要なパーツ、配線図等については [Wiki](https://github.com/YaSuenag/toyhack/wiki) をご覧ください。

# 対応する玩具

* 獣電戦隊キョウリュウジャー
    * [変身銃 ガブリボルバー](http://www.bandai.co.jp/catalog/item/4543112783615000.html)
    * [変形銃 ガブティラ・デ・カーニバル](http://www.bandai.co.jp/catalog/item/4543112815101000.html)
* 妖怪ウォッチ
    * [DX妖怪ウォッチ](http://yw.b-boys.jp/member/products/watch/)
    * [DX妖怪ウォッチ タイプ零式](http://yw.b-boys.jp/member/products/watch2/)

# ビルド・インストール方法

```
$ ./configure --with-wiring-pi=/path/to/wiringpi/headers
$ make
$ su -
# make install
```

Raspbian JessieではWiring Piが `apt` でインストール可能です。 `apt` でインストールしている場合は `--with-wiring-pi` を付与する必要はありません。

# 実行時の注意

本ソースでビルドされるライブラリはデフォルトで `/usr/local/lib` にインストールされます。
一部のLinuxディストリビューションはライブラリパスに `/usr/local/lib` が含まれていないため、実行時に動的リンカエラーが発生することがあります。その場合は `ld.so.conf` または `LD_LIBRARY_PATH` を設定し、依存ライブラリが解決可能な状態になるようにしてください。

# BLEによるコントロール

## ペリフェラル（BLEプロキシ）

`src/ble/peripheral` 配下の `index.js` を `node.js` で動作させると、ToyHackによるおもちゃのコントロールをBLE通信で行えるようになります。

```
$ cd src/ble/peripheral
$ npm install
# node index.js path/to/toyhack-library.so
```

BLEプロキシでは [bleno](https://github.com/sandeepmistry/bleno) を使ってBLE通信を行っています。  
blenoを使う関係上、 `bluetoothd` は停止させ、Bluetoothデバイスは動作させておく必要があります。

```
# systemctl stop bluetooth.service
# hciconfig hci0 up
```

# License

GNU General Public License v2


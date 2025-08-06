# m5stickc-plus2-with-esp-idf
VSCodeのESP-IDF環境で、M5StickC Plus2を使ったhello worldのサンプルです。
M5GFX内でM5の基盤を自動認識してくれるはずなので、M5StickC Plus2でなくても動くはずですが未検証です。

# 前提
* Windows 11
* Visual Source Code v1.102.3
* ESP-IDF v5.5.0
* [arduiono-esp32](https://github.com/espressif/arduino-esp32) v3.3.0
* [M5GFX](https://github.com/m5stack/M5GFX) v0.2.9
* [M5Unified](https://github.com/m5stack/M5Unified) v0.2.7

# [WIP]How to use
1. このリポジトリをgit cloneして、VSCodeで開きます
2. 特定のフォルダにgit cloneでarduiono-esp32、M5GFX、M5Unifiedを配置します
3. CMakeLists.txtのEXTRA_COMPONENT_DIRSに1のフォルダを設定します
4. ctr + shift + pを押してESP-IDF: Open ESP-IDF Terminalを選択します
5. idf.py menuconfigの実行。おそらく失敗しますが、sdkconfigが生成されるので、CONFIG_FREERTOS_HZを100から1000に直接ファイルを開いて修正します
6. idf.py menuconfigの実行。今度はうまくいくので、Arduiono Configuration -> Autostart Arduino setup and loop on boot をチェックします
7. idf.py build
8. idf.py flash monitor

# 注意
main/CMakeList.txtを見てもらうとわかりますが、PRIV_REQUIRESにarduiono-esp32を含めていません。
arduiono-esp32を含めると、実行時にpanicedで落ちる可能性や、正常にディスプレイにhello worldが表示されなくなります。
これはM5GFXがarduino-esp32をサブモジュールして使うことを前提としていないためです。
[参考](https://github.com/m5stack/M5Unified/issues/36)

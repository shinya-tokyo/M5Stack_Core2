# M5Stack_Core2 Motor Control Program

Motor Control Program of TIANKONGRC Digital Servo (TD-8120MG)

1. Start VS Code and PlatformIO
2. Add M5Core2 and LovyanGFX library
3. Enter these each code to "./src/main.cpp"
4.1. (For one motor) Connect 3 cables to M5Stack Core2 (+/- and signal G32 pin)
4.2. (For 3 motors) Connect 5+ cables to M5Stack Core2 (+/- and signal G32, G33, G27 pin). External batterry is needed.
5. The motor rotates CW & CCW changing it's velocity.

=

This is the same Japanese sentence of above.

TIANKONGRCデジタルサーボ (TD-8120MG)のモーター制御プログラムです

1. ビジュアルスタジオ・コードとPlatformIOを起動
2. 「M5Core2」と「LovyanGFX」を追加
3. このコードを「./src/main.cpp」に追加
4.1. (1個のモーターの場合) 3本のケーブルをM5Stack Core2に接続 (+と-、G 32、G 33、G 27ピンへの信号線)
4.2. (3個のモーターの場合) 5本以上のケーブルをM5Stack Core2に接続 (+と-、G 32、G 33、G 27ピンへの信号線) 外部電池が必要です
6. モーターが速度を変えながら、時計回りと反時計回りに回る



cf(1). https://dev.classmethod.jp/articles/m5stack-core2-for-aws-arduino-pwm-sg90/

cf(2). https://logikara.blog/m5stack-lcd-setting/

# M5Stack Core2 Motor Control Program

Motor Control Program of TIANKONGRC Digital Servo (TD-8120MG)

one_motor_control.cpp is for controling 1 motor.

three_motor_control.cpp is for controling 3 motors.

1. Start VS Code and PlatformIO

2. Add M5Core2 and LovyanGFX library

3. Enter these each code to "./src/main.cpp"
   * one_motor_control.cpp or three_motor_control.cpp

4.1. (For one_motor_control.cpp) Connect 3 cables to M5Stack Core2 (+/- and signal G32 pin)

4.2. (For three_motor_control.cpp) Connect 5+ cables to M5Stack Core2 (+/- and signal G32, G33, G27 pin). External power is needed.

5. Write the program to the M5Stack and the motor rotates CW & CCW changing it's velocity.

=

This is the same Japanese sentence of above.

TIANKONGRCデジタルサーボ (TD-8120MG)のモーター制御プログラム

one_motor_control.cpp は1個のモーター制御用です。

three_motor_control.cpp は3個のモーター制御用です。

1. ビジュアルスタジオ・コードとPlatformIOを起動

2. 「M5Core2」と「LovyanGFX」を追加

3. 下記コード、それぞれのプログラムを「./src/main.cpp」に追加
   * one_motor_control.cpp か three_motor_control.cpp
     
4.1. (one_motor_control.cpp の場合) 3本のケーブルをM5Stack Core2に接続 (+と-、G 32、G 33、G 27ピンへの信号線)

4.2. (three_motor_control.cpp の場合) 5本以上のケーブルをM5Stack Core2に接続 (+と-、G 32、G 33、G 27ピンへの信号線) 外部電源が必要です

5. M5Stack にプログラムを書き込むと、モーターが速度を変えながら、時計回りと反時計回りに回転します



cf(1). https://dev.classmethod.jp/articles/m5stack-core2-for-aws-arduino-pwm-sg90/

cf(2). https://logikara.blog/m5stack-lcd-setting/

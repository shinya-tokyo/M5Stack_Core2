#include <M5Core2.h>
#include <stdio.h>
// #include <string.h>
#include <string>

#define SERVO_PIN  32
#define SERVO_CH   0
#define PWM_HZ 50
#define PWM_BIT 16 // 16bit(0～65535)

#define MAX 7800 // 65535 / 20 * 2.4 ≒ 7864 
#define MIN 1700 // 65535 / 20 * 0.5 ≒ 1638

void setup() {

    M5.begin(true, true, true, false); // I2C無効(PORTA をGPIOで使用するため)

    ledcSetup(SERVO_CH, PWM_HZ, PWM_BIT);
    ledcAttachPin(SERVO_PIN, SERVO_CH);

    M5.Lcd.setBrightness(200);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextFont(2);

    M5.Lcd.setTextColor(GREEN);
}

void motor(int angle) {
    std::string str;
    int duty_cycle  = map(angle, 0, 180, MIN, MAX); 
    ledcWrite(SERVO_CH, duty_cycle);

    M5.Lcd.fillScreen(BLACK);
    // M5.Lcd.setCursor(80, 80);
    M5.Lcd.setCursor(10, 10);
    // sprintf(str,"%3d", angle);
    M5.Lcd.setTextColor(GREEN);

    if((angle >= 0) && (angle <= 45)){
        str = "HI: " + std::to_string(angle) + "\nCW";     
    }
    else if((angle > 45) && (angle < 90)){
        str = "LO: " + std::to_string(angle) + "\nCW";
        // str = "LO\n CW";       
    }
    else if(angle == 90){
        M5.Lcd.fillScreen(YELLOW);
        M5.Lcd.setTextColor(RED);
        str = "STOP";       
    }
    else if((angle > 90) && (angle <= 135)){
        str = "LO: " + std::to_string(angle) + "\nCCW";
        // str = "LO\nCCW";       
    }
    else if((angle > 135) && (angle <= 180)){
        str = "HI: " + std::to_string(angle) + "\nCCW";
        // str = "HI\nCCW";       
    }

    // M5.Lcd.drawCentreString(str.c_str(), 150, 70, 7);
    M5.Lcd.print(str.c_str());
}


void loop() {

    motor(0); // Highest CW
    delay(3000);

    // motor(46); // Medium CW
    // delay(300);

    motor(60); // Lowest CW
    delay(3000);

    motor(90); // Stop
    delay(1500);

    motor(120); // Lowest CCW
    delay(3000);

    // motor(136); // Medium CCW
    // delay(300);

    motor(180); // Highest CCW
    delay(3000);

    motor(90); // Stop
    delay(1500);
 

    // delay(1000);    

    /*
    for (int angle = 0; angle <= 180; angle += 1) {
        int duty_cycle  = map(angle, 0, 180, MIN, MAX); 
        ledcWrite(SERVO_CH, duty_cycle);

        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(80, 80);
        sprintf(str,"%3d", angle);
        M5.Lcd.drawCentreString(str, 150, 70, 7);
        delay(1000);
    }
    */
}

#include <M5Core2.h>
#include <stdio.h>
#include <string>

#define SERVO_PIN_1  32
#define SERVO_PIN_2  33
#define SERVO_PIN_3  27
#define SERVO_CH_1   1
#define SERVO_CH_2   2
#define SERVO_CH_3   3
#define PWM_HZ 50
#define PWM_BIT 16

#define MAX 7800 
#define MIN 1700

void setup() {

    M5.begin(true, true, true, false);

    ledcSetup(SERVO_CH_1, PWM_HZ, PWM_BIT);
    ledcAttachPin(SERVO_PIN_1, SERVO_CH_1);
    ledcSetup(SERVO_CH_2, PWM_HZ, PWM_BIT);
    ledcAttachPin(SERVO_PIN_2, SERVO_CH_2);
    ledcSetup(SERVO_CH_3, PWM_HZ, PWM_BIT);
    ledcAttachPin(SERVO_PIN_3, SERVO_CH_3);

    M5.Lcd.setBrightness(200);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setTextFont(2);

    M5.Lcd.setTextColor(GREEN);
}

void motor(int angle, int motor_no) {
    std::string str;
    int duty_cycle  = map(angle, 0, 180, MIN, MAX);

    switch(motor_no){
      case 1:
      ledcWrite(SERVO_CH_1, duty_cycle);
      break;

      case 2:
      ledcWrite(SERVO_CH_2, duty_cycle);
      break;
      
      case 3:
      ledcWrite(SERVO_CH_3, duty_cycle);
      break;
    }
    
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.setTextColor(GREEN);

    if((angle >= 0) && (angle <= 45)){
        str = "HI: " + std::to_string(angle) + "\nCW";     
    }
    else if((angle > 45) && (angle < 90)){
        str = "LO: " + std::to_string(angle) + "\nCW";       
    }
    else if(angle == 90){
        M5.Lcd.fillScreen(YELLOW);
        M5.Lcd.setTextColor(RED);
        str = "STOP";       
    }
    else if((angle > 90) && (angle <= 135)){
        str = "LO: " + std::to_string(angle) + "\nCCW";
    }
    else if((angle > 135) && (angle <= 180)){
        str = "HI: " + std::to_string(angle) + "\nCCW";
    }
    M5.Lcd.print(str.c_str());
}


void loop() {

    motor(0, 1); // Highest CW
    motor(0, 2); // Highest CW
    motor(0, 3); // Highest CW
    delay(3000);

    // motor(46); // Medium CW
    // delay(300);

    motor(60, 1); // Lowest CW
    motor(60, 2); // Lowest CW
    motor(60, 3); // Lowest CW
    delay(3000);

    motor(90, 1); // Stop
    motor(90, 2); // Lowest CW
    motor(90, 3); // Lowest CW
    delay(1500);

    motor(120, 1); // Lowest CCW
    motor(120, 2); // Lowest CCW
    motor(120, 3); // Lowest CCW
    delay(3000);

    // motor(136); // Medium CCW
    // delay(300);

    motor(180, 1); // Highest CCW
    motor(180, 2); // Highest CCW
    motor(180, 3); // Highest CCW
    delay(3000);

    motor(90, 1); // Stop
    motor(90, 2); // Stop
    motor(90, 3); // Stop
    delay(1500);

}

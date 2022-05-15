#include <ESP8266WiFi.h>

//GPIO Definition
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 1
#define RX 3
#define TX 1
#define S3 10
#define S2 9
#define CMD 11
#define CLK 6

void pwmTest(int pin);

void setup() {
    Serial.begin(115200);
  //pinMode(0,OUTPUT); //D3
  //pinMode(1,OUTPUT); //TX
    pinMode(2,OUTPUT); //D4
  //pinMode(3,OUTPUT); //RX
    pinMode(4,OUTPUT); //D2
    pinMode(5,OUTPUT); //D1
  //pinMode(6,OUTPUT); //CLK
  //pinMode(7,OUTPUT); //?
  //pinMode(8,OUTPUT); //?
  //pinMode(9,OUTPUT); //S2
  //pinMode(10,OUTPUT); //S3
  //pinMode(11,OUTPUT); //CMD
    pinMode(12,OUTPUT); //D9
}

void loop() {
    Serial.println("\n-----------------------------------");

    //Serial.println(" pwm fest for TX");
    //pwmTest (1);
    ///
    Serial.println(" pwm fest for D4");
    pwmTest (2);
    ///
    //Serial.println(" pwm fest for RX");
    //pwmTest (3);
    ///
    Serial.println(" pwm fest for D2");
    pwmTest (4);
    ///
    Serial.println(" pwm fest for D1");
    pwmTest (5);
    ///
    //Serial.println(" pwm fest for CLK");
    //pwmTest (6);
    ///
    //Serial.println(" pwm fest for 7?);
    //pwmTest (7);
    ///
    //Serial.println(" pwm fest for 8?");
    //pwmTest (8);
    ///
    //Serial.println(" pwm fest for S2");
    //pwmTest (9);
    ///
    //Serial.println(" pwm fest for S3");
    //pwmTest (10);
    ///
    //Serial.println(" pwm fest for CMD");
    //pwmTest (11);
    ///
    Serial.println(" pwm fest for D6");
    pwmTest (12);
}

////////GPIO testing Function////////
void pwmTest(int pin)
{
    Serial.print("PIN");
    Serial.print(pin);
    Serial.println("PWM testing");
    delay (5000);

    for(int i = 0; i < 255; i++)
    {
        analogWrite(pin, i);
        delay (50);
    }

    Serial.println("-----------------------");
}

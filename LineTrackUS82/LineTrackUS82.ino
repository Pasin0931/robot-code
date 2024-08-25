#include <uS82.h>
#include <us82_motor.h>
#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;

bool ledState = 1;
uint8_t Unit_sensor = 8;
uint16_t sensor_pin[8];
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t White_sensor_values[] = {920, 900, 900, 950, 950, 900, 900, 810 };
uint16_t Black_sensor_values[] = {110, 100, 80, 90, 90, 90, 80, 80};
uint32_t Last_Position;
int power, base, error, last_error, L_motor, R_motor, r, RL_moter, sumerror, p1, p2, d;
void setup() {
  Serial.begin(9600);
  uSetup();
  adc.begin(13 , 11, 12, A0);
  SW_press();

  delay(500);
  
//  LR(50, 0.025, 0.19);
//  pid_Time(40, 0.02, 0.15 , 1400);
//  an_R(35, 0.02, 0.15, 100, 30, 30, 30);
//  R_TURN(25, 0.02, 0.12 , 30, 150, 30, 30, 4);
////  R(28, 0.018, 0.15);
//  R_TURN(25, 0.02, 0.12 , 30, 150, 30, 30, 4);
////  R_TURN(40, 0.02, 0.15, 30, 150, 30, 30, 6);
//  pid_Time(36, 0.02, 0.15 , 2000);
//  LR_DEL(36, 0.02, 0.2, 36, 100);
//////  LR(36, 0.02, 0.15);
//  turnR(30, 30);
//  R_TURN(25, 0.02, 0.12 , 30, 150, 30, 30, 4);
//  an_R(35, 0.02, 0.15, 100, 30, 30, 30);

//  pid_Time(37, 0.034, 0.34 , 16500);
//   pid_Time(42, 0.073, 0.58 , 500000);

//------------------------------------------

  pid_Time(40, 0.0050, 0.01, 3000); //SKY
  
//  pid_Time(36, 0.048, 0.35 , 13800);
//  obja(36, 0.048, 0.35, 30, 0, 280, 30, 50, 600);
//  movef(40,0);
//  delay(250);
//  ao();
//  pid_Time(31, 0.048, 0.35, 2000);
//  pid_Time(20 , 0.025, 0.30 , 13100);
//  LR_DEL(22, 0.025, 0.12, 22, 100);
//  LR_DEL(22, 0.025, 0.12, 22, 150);
//
//  turnL(30, 30);
//  delay(100);
//  LR_DEL(27, 0.025, 0.12, 27, 100);
//
//  pid_Time(29, 0.056, 0.30 , 2200);
////  obja(29, 0.056, 0.30, 30, 30, 90, 40, 30, 500);
//  pid_Time(29, 0.056, 0.30 , 300);
//  pid_Time(75, 0.0885, 0.75, 1000);
//  pid_Time(22, 0.025, 0.12 , 3000);

//---------------------------------------------
  
  
  //LR_TR(50, 0.045, 0.35, 30, 50, 0, 40);

//  movef(50,50);
//  delay(500);
//  ao();
//  movef(0,50);
//  delay(500);
//  ao();
//  movef(50,0);
//  delay(500);
//  ao();
//  movef(-50,-50);
//  delay(500);
//  ao();
    
}

void loop() {

  //position1();
  Serial.println(position1());
//  view();
  //Serial.println(analog(7));
}

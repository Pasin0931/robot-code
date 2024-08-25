void movef(float m1 , float m2)
{
    int motorR = m2; //mR
    int motorL = m1; //mL
    
    if(motorL >= 100){
      motorL = 100;
    }
    if(motorR >= 100)
    {
      motorR = 100;
    }
    if(motorL <= -100)
    {
      motorL = -100;
    }
    if(motorR <= -100)
    {
      motorR = -100;
    }
    
    motor(1,motorL);
    motor(2,motorR);
}
void moveBack(float speeding4 , float speeding3 , float timing)
{
  movef(speeding4 * -1 , speeding3 * -1);
  delay(timing);
  ao();
}
void moveFoward(float speeding4 , float speeding3 , float timing)
{
  movef(speeding4 , speeding3);
  delay(timing);
  ao();
}
void turnRight(float speeding4 , float speeding3)
{
  readsensor();
  while (sensor_pin[3] < 1500)
  {
    readsensor();
    movef(speeding4 * -1 , speeding3);
  }
  ao();
}
void turnLeft(float speeding4 , float speeding3)
{
  readsensor();
  while (sensor_pin[0] < 1500)
  {
    readsensor();
    movef(speeding4 , speeding3 * -1);
  }
  ao();
}

void mbc(float speeding4 , float speeding3)
{
  readsensor();
  while ((sensor_pin[0] < 2500) || (sensor_pin[3] < 2500))
  {
    readsensor();
    movef(speeding4 * -1 , speeding3 * -1);
  }
  ao();
  while ((sensor_pin[0] > 2500) || (sensor_pin[3] > 2500))
  {
    readsensor();
    movef(speeding4 - 7 , speeding3 - 7);
  }
  ao();
}
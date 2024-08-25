void PID_cutLine(float kp , float ki , float kd , float speeding , float count , int analogS)
{
  int count_b = 0;
  while (count_b < count)
  {
    readsensor();
    while ((sensor_pin[0] < analogS) || (sensor_pin[3] < analogS))
    {
      PD_move(kp , ki , kd , speeding);
    }
    count_b++;
    readsensor();
    while ((sensor_pin[0] > analogS) || (sensor_pin[3] > analogS))
    {
      PD_move(kp , ki , kd , speeding);
    }
    ao();
  }
}
void PID_cutLine2(float kp , float ki , float kd , float speeding , float count , int analogS)
{
  int count_b = 0;
  while (count_b < count)
  {
    readsensor();
    while ((sensor_pin[0] > analogS) && (sensor_pin[3] > analogS))
    {
      PD_move(kp , ki , kd , speeding);
    }
    count_b++;
    while ((sensor_pin[0] < analogS) && (sensor_pin[3] < analogS))
    {
      PD_move(kp , ki , kd , speeding);
    }
    ao();
  }
}
void PID_cutLineTurnR(float kp , float ki , float kd , float speeding , float sL , float sR , float spf , float tf , int analogS)
{
  PID_cutLine(kp , ki , kd , speeding , 1 , analogS);
  PID_Time(kp , ki , kd , spf , tf);
  delay(20);
  readsensor();
  while (sensor_pin[3] < analogS) //white
  {
    readsensor();
    movef(sL * -1 , sR); //sL have a problem when turn use sL = 0
  }
  ao();
}
void PID_cutLineTurnL(float kp , float ki , float kd , float speeding , float sL , float sR , float spf , float tf , int analogS)
{
  PID_cutLine(kp , ki , kd , speeding , 1 , analogS);
  movef(spf,spf);
  delay(tf);
  readsensor();
  while (sensor_pin[0] > analogS) //white
  {
    readsensor();
    movef(sL , sR * -1);
  }
  ao();
}

// -------------------------------------------------------

void cRtR(float kp , float ki , float kd , float speeding , float sL , float sR , float spf , float tf , int analogS)
{
  readsensor();
  while (sensor_pin[3] < analogS) //white
  {
    readsensor();
    PD_move(kp , ki , kd , speeding);
  }
  // movef(spf,spf);
  // delay(tf);
  PID_Time(0.025 , 0 , 0.99, spf, tf);
  readsensor();
  while (sensor_pin[3] < analogS) //white
  {
    readsensor();
    movef(sL * -1 , sR);
  }
  ao();
}

void cLtL(float kp , float ki , float kd , float speeding , float sL , float sR , float spf , float tf , int analogS)
{
  readsensor();
  while (sensor_pin[0] < analogS) //white
  {
    readsensor();
    PD_move(kp , ki , kd , speeding);
  }
  // movef(spf,spf);
  // delay(tf);
  PID_Time(0.025 , 0 , 0.99, spf, tf);
  readsensor();
  while (sensor_pin[0] < analogS) //white
  {
    readsensor();
    movef(sL , sR * -1);
  }
  ao();
}

void cLtR(float kp , float ki , float kd , float speeding , float sL , float sR , float spf , float tf , int analogS)
{
  readsensor();
  while (sensor_pin[0] < analogS) //white
  {
    readsensor();
    PD_move(kp , ki , kd , speeding);
  }
  // movef(spf,spf);
  // delay(tf);
  PID_Time(0.025 , 0 , 0.99, spf, tf);
  readsensor();
  while (sensor_pin[3] < analogS) //white
  {
    readsensor();
    movef(sL * -1, sR);
  }
  ao();
}
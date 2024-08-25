void LR_TR(int speed1, float kp, float kd, float spf, float tf, float spL, float spR)
{
  readsensor();
  while (true) {
    pd1(speed1,kp,kd);
      if((sensor_pin[0] >= 500) && (sensor_pin[7] >= 500))
      {
        break;
      }
  }
   while (true) {
    readsensor();
    pd1(speed1,kp,kd);
      if((sensor_pin[0] <= 500) && (sensor_pin[7] <= 500))
      {
        ao();
        break;
      }
  }
  pid_Time(spf, kp, kd , tf);
    while (true) {
    readsensor();
    movef(spL, spR * -1);
      if(sensor_pin[7] <= 500)
      {
        ao();
        break;
      }
  }
}

void LR_TL(int speed1, float kp, float kd )
{
  readsensor();
  while (true) {
    pd1(speed1,kp,kd);
      if((sensor_pin[0] >= 500) && (sensor_pin[7] >= 500))
      {
        break;
      }
  }
   while (true) {
    readsensor();
    pd1(speed1,kp,kd);
      if((sensor_pin[0] <= 500) && (sensor_pin[7] <= 500))
      {
        ao();
        break;
      }
  }
}
void R_TURN(int speed1, float kp, float kd , float SSF, float delayy, float SSL, float SSR, int i)
{
  R(speed1, kp, kd );
  readsensor();
  movef(SSF,SSF);
  delay(delayy);
  ao();
  readsensor();
  while (sensor_pin[i] >= 500)
  {
    readsensor();
    movef(SSL, SSR * -1);
  }
  ao();
}

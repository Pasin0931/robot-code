void LR(int speed1, float kp, float kd )
{
  readsensor();
  while (true) {
    pd1(speed1,kp,kd);
      if((sensor_pin[0] >= 500) && (sensor_pin[7] >= 500))
      {
        ao();
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
void LR_DEL(int speed1, float kp, float kd, float SF, float delayy)
{
  readsensor();
  while (true) {
    pd1(speed1,kp,kd);
      if((sensor_pin[1] <= 500) && (sensor_pin[6] <= 500))
      {
        ao();
        break;
      }
  }
  movef(SF, SF);
  delay(delayy);
  ao();
}
void LR_2(int speed1, float kp, float kd )
{
  readsensor();
  while (true) {
    pd1(speed1,kp,kd);
      if((sensor_pin[0] >= 500) || (sensor_pin[7] >= 500))
      {
        ao();
        break;
      }
  }
   while (true) {
    readsensor();
    pd1(speed1,kp,kd);
      if((sensor_pin[0] <= 500) || (sensor_pin[7] <= 500))
      {
        ao();
        break;
      }
  }
}
void LR_s(int speed1, float kp, float kd )
{
  while (true) {
    pd1(speed1,kp,kd);
      if((sensor_pin[6] >= 500) && (sensor_pin[3] >= 500))
      {
        ao();
        break;
      }
  }
}

void LR_stopB(int speed1, float kp, float kd )
{
  while (true) {
    pd1(speed1,kp,kd);
      if((sensor_pin[0] >= 500) && (sensor_pin[7] >= 500))
      {
        ao();
        break;
      }
  }
}
void R_stopB(int speed1, float kp, float kd )
{
  while (true) {
    pd1(speed1,kp,kd);
      if(sensor_pin[7] >= 500)
      {
        ao();
        break;
      }
  }
}
void L(int speed1, float kp, float kd )
{
  while (true) {
    pd1(speed1,kp,kd);
      if(sensor_pin[0] >= 500)
      {
        ao();
        break;
      }
  }
   while (true) {
    readsensor();
    pd1(speed1,kp,kd);
      if(sensor_pin[0] <= 500)
      {
        ao();
        break;
      }
  }
}
void R(int speed1, float kp, float kd )
{
  readsensor();
  while (true) {
    pd1(speed1,kp,kd);
      if(sensor_pin[7] >= 500)
      {
        ao();
        break;
      }
  }
   while (true) {
    readsensor();
    pd1(speed1,kp,kd);
      if(sensor_pin[7] <= 500)
      {
        ao();
        break;
      }
  }
}

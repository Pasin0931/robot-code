void pd1(int base, float kp, float kd) // 35 0.03 0.06 pidปกติ
{
  error = 3500 - position1();
  power = (kp * error) + (kd * (error - last_error));
  last_error = error;
  L_motor = base - power;
  R_motor = base + power;
  if (L_motor >= 100)L_motor = 100;
  if (R_motor >= 100)R_motor = 100;
  if (L_motor <= -100)L_motor = -100;
  if (R_motor <= -100)R_motor = -100;
  movef(L_motor,R_motor);
}
void pid_Time(int speed1, float kp, float kd , int Times)
{
  long now_times = millis();
  while (millis() - now_times < Times)
  {
    pd1(speed1, kp, kd);
  }
  ao();
}


void PD_move(float kp , float ki , float kd , float speeding){
  error =1500 - position1();
  power = (kp * error) + (kd * (error - last_error));
  last_error = error;
  L_speed = speeding + power;
  R_speed = speeding - power;
  if (L_speed >= 100)L_speed = 100;
  if (R_speed >= 100)R_speed = 100;
  if (L_speed <= -100)L_speed = -100;
  if (R_speed <= -100)R_speed = -100;
  movef(L_speed,R_speed);
  //Serial.print(L_speed);   Serial.print(" ");   Serial.println(R_speed);
}
void PID_Time(float kp, float ki, float kd, float speeding, int timing)
{
  long now_times = millis();
  while(millis() - now_times < timing)
  {
    PD_move(kp, ki ,kd ,speeding);
  }
  ao();
}

void PD_moveb(float kp , float ki , float kd , float speeding)
{
  error = position2() - 1500;
  power = (kp * error) + (kd * (error - last_error));
  last_error = error;
  L_speed = speeding - power;
  R_speed = speeding + power;
  if (L_speed >= 100)L_speed = 100;
  if (R_speed >= 100)R_speed = 100;
  if (L_speed <= -100)L_speed = -100;
  if (R_speed <= -100)R_speed = -100;
  movef(L_speed * -1,R_speed * -1);
  //Serial.print(L_speed);   Serial.print(" ");   Serial.println(R_speed);
}
void PID_Timeb(float kp, float ki, float kd, float speeding, int timing)
{
  long now_times = millis();
  while(millis() - now_times < timing)
  {
    PD_moveb(kp, ki ,kd ,speeding);
  }
  ao();
}
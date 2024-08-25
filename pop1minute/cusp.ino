void cudp(float kp , float ki , float kd , float speeding , float count , int analogS)
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
    ao();
  }
}

void drp(float kp , float ki , float kd , float speeding, int analogS){
  while ((analog(1) > analogS) || (analog(2) > analogS)) {
    PD_move(kp, ki, kd, speeding);
  }
  ao();
}



void moc(float s1, float s2, float ana){
  readsensor();
  while((sensor_pin[0] > ana) || (sensor_pin[3] > ana)){
    readsensor();
    movef(s1, s2);
  }
  ao();
  readsensor();
  while ((sensor_pin[0] < ana) || (sensor_pin[3] < ana)){
    readsensor();
    movef(s1, s2); 
  }
  ao();
}

void bckk(float spd, int delayy){
  movef(spd * -1, spd * -1);
  delay(delayy);
  ao();
}
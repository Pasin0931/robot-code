void obja(int speed1, float kp, float kd, float SSL, float SSR, float delayy, float TLL, float TRR, float delayy2)
{
  while(analog(7) > 500){
    pd1(speed1, kp, kd);
  }
  movef(SSL, SSR * -1);
  delay(delayy);
  ao();
  movef(TLL, TRR);
  delay(delayy2);
  ao();
  readsensor();
  while(sensor_pin[3] >= 470){
    readsensor();
    movef(TLL, TRR);
  }
  ao();
}

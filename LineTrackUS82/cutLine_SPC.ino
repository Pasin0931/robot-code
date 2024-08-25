void an_R(float spf,float kp,float kd,float delayy,float spVF,float spL2,float spR2)
{
  R(spf, kp, kd);
  movef(spVF, spVF);
  delay(delayy);
  ao();
  readsensor();
  while (sensor_pin[4] >= 500)
  {
    readsensor();
    movef(spL2, spR2 * -1);
  }
  ao();
}

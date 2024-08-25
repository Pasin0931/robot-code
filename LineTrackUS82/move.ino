void movef(int L , int R ) {
  int SpeedL;
  int SpeedR;

  if (L > 0) {
    SpeedL = map(L, 0, 100, 0, 255);
  }
  else {
    SpeedL = map(L, -0, -100, 0, 255);
  }

  if (R > 0) {
    SpeedR = map(R, 0, 100, 0, 255);
  }
  else {
    SpeedR = map(R, -0, -100, 0, 255);
  }

   
   motor(1, L); 
   motor(2, R);
}
void ao(){
  motor(1,0);
  motor(2,0);
}
void turnR(float SLL, float SRR){
  readsensor();
  while (sensor_pin[3] >= 500)
  {
    readsensor();
    movef(SLL, SRR * -1);
  }
  ao();
}
void turnL(float SLL, float SRR){
  readsensor();
  while (sensor_pin[2] >= 500)
  {
    readsensor();
    movef(SLL * -1, SRR);
  }
  ao();
}

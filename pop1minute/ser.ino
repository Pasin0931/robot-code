void serdr(int pi){
  servo(pi, 64);
}
void serre(int pi){
  servo(pi, 0);
}

void set(int pi){
  servo(pi, 0);
  delay(150);
  servo(pi, 16);
  delay(150);
  servo(pi, 32);
  delay(150);
  servo(pi, 48);
  delay(150);
  servo(pi, 51);
  // servo(2, 64);
  delay(100);
  // servo(pi, 0);
}
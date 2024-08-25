void readsensor() {


  for (int channel = 0; channel < 8; channel++) {
    sensor_pin[channel] = adc.readADC(channel);
    //Serial.print(adc.readADC(channel)); Serial.print(" ");
  }
  Serial.println();
}
void view()
{ 
  readsensor();
  for(int i = 0;i <=7; i++)
  {
    Serial.print(" S");
    Serial.print(i);
    Serial.print(" [");
    //int show = i+1;
    //Serial.print(sensor_pin[show]);
    Serial.print(adc.readADC(i));
    Serial.print("  "); 
  } 
  Serial.println(""); 
}

void view() 
{
  for (uint8_t i = 0; i < Unit_sensor; i++)
  {
    readsensor();
    Serial.print(sensor_pin[i]);
    Serial.print(" ");
  }
//  Serial.print(position1());
    Serial.println('\n');
//  Serial.println(analog(5));
//  Serial.println(" ");
//  delay(200);
}
//----------------------------------------------------
void readsensor() 
{
  sensor_pin[0] = analog(0);
  sensor_pin[1] = analog(1);
  sensor_pin[2] = analog(2);
  sensor_pin[3] = analog(3);
}

// void stopr() 
// {
//   analog(0) = a;
//   analog(1) = b;
//   analog(2) = c;
//   analog(3) = d;
// }
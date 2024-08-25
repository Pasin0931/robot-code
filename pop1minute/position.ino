int position1()
{
  readsensor();
  bool In_line = false;
  long Average = 0, sum = 0;

  for (uint8_t i = 0; i < Unit_sensor ; i++)
  {
    long value = map(long(sensor_pin[i]), Black_sensor_values[i], White_sensor_values[i], 0, 1000);
    // Serial.print (position1()); Serial.print("--"); Serial.print (value); Serial.print("--"); Serial.println(In_line);

    if (value > 500)
    {
      In_line = true;
    }
    if (value > 0)
    {
      Average += (long)value * (i * 1000);
      sum += value;
    }
     Serial.print(value);
     Serial.print(" ");
  }
   Serial.println("");
  if (!In_line)
  {
    if (Last_Position < (Unit_sensor - 1) * 1000 / 3) //2.4 2.25
    {
      return 0;
    }
    else if (Last_Position < (Unit_sensor - 1) * 1000 / 1.5  && Last_Position > (Unit_sensor - 1) * 1000 / 3 ) //
    {
      return 1500;
    }
    else if (Last_Position > (Unit_sensor - 1) * 1000 / 1.5 ) //1.75 1.6
    {
      return 3000;
    }
    else
    {
      return (Unit_sensor - 1) * 1000;
    }
  }
  Last_Position = Average / sum;
  return Last_Position;
}


int position2()
{
  readsensor();
  bool In_line = false;
  long Average = 0, sum = 0;

  for (uint8_t i = 0; i < Unit_sensor ; i++)
  {
    long value = map(long(sensor_pin[i]), Black_sensor_values[i], White_sensor_values[i], 0, 1000);
    // Serial.print (position1()); Serial.print("--"); Serial.print (value); Serial.print("--"); Serial.println(In_line);

    if (value > 500)
    {
      In_line = true;
    }
    if (value > 0)
    {
      Average += (long)value * (i * 1000);
      sum += value;
    }
     Serial.print(value);
     Serial.print(" ");
  }
   Serial.println("");
  if (!In_line)
  {
    if (Last_Position < (Unit_sensor - 1) * 1000 / 3) //2.4 2.25
    {
      return 3000;
    }
    else if (Last_Position < (Unit_sensor - 1) * 1000 / 1.5  && Last_Position > (Unit_sensor - 1) * 1000 / 3 ) //
    {
      return 1500;
    }
    else if (Last_Position > (Unit_sensor - 1) * 1000 / 1.5 ) //1.75 1.6
    {
      return 0;
    }
    else
    {
      return (Unit_sensor - 1) * 1000;
    }
  }
  Last_Position = Average / sum;
  return Last_Position;
}
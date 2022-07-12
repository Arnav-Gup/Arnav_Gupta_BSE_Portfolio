#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
 
void setup(void) 
{
  Serial.begin(38400);
  Serial1.begin(38400);


  if(!accel.begin())
  {
    while(1);
  }

  accel.setRange(ADXL345_RANGE_16_G);

  Serial.println("");
}

void loop(void) 
{
  sensors_event_t event; 
  accel.getEvent(&event);
  double accelerationX = event.acceleration.x;
  double accelerationY = event.acceleration.y;
  double accelerationZ = event.acceleration.z;
  
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  if (accelerationY >= 7.50) {
    Serial.println("W");
    Serial1.write('w');
  }
  else if (accelerationY <= -5) {
    Serial.println("S");
    Serial1.write('d');
  }
  else if (accelerationX <= -5.25) {
    Serial.println("A");
    Serial1.write('a');
  }
  else if (accelerationX >= 5.25) {
    Serial.println("D");
    Serial1.write('s');
  }
  else {
    Serial.println("D");
    Serial1.write('S');
  }
  delay(300);
}

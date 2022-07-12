# Gesture Controlled Car
 This project features a robot car with an accelerometer and a glove controller with a gyroscope with the ability to affect the car's directions with a simple tilt of the wrist. Using bluetooth HC-05 modules to wirelessly transmit instructions to the car this project makes use of a variety of electrical engineering principles and is a blast to try out.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Arnav Gupta | Cupertino High School | Software Engineering | Incoming Junior

<p align="center">
<img src ="https://hackster.imgix.net/uploads/attachments/999480/edited_qR6z8Gq5H1.jpg?auto=compress%2Cformat&w=900&h=675&fit=min" width=400>
</p>

# Materials
**Here is a [List of Materials](https://docs.google.com/spreadsheets/d/1ZENtVtG4XW8agSRHn98dvI3Iegi4U5U8XJovx9Xg_Fs/edit?usp=sharing).**
 
<img src="https://hackster.imgix.net/uploads/attachments/999489/snapshot253_tUezZh7ncn.png?auto=compress%2Cformat&w=1280&h=960&fit=max" width=400>

# Final Milestone
My final milestone is assembling all my separate parts and writing my final code for my gesture controlled robot. My first step was to assemble my robot with the robot framework and setting up the dc motors and wheels. I did this by assembling all of my parts and then soldering my jumper wires so they do not get disconnected. I then hot glued my battery and arduino so that the car is wireless and taped my bluetooth module down. The next step was to put together my glove so I wired my arduino micro and bluetooth module together and taped my accelerometer down. When taping my accelerometer down I needed to tape it upside down so that it would properly fit so in the final code I needed to reverse my directions. In the final code that I wrote it sensed which direction you tilted the accelerometer with a error range of 5. I then printed to the serial monitor w, a, s, or d for which direction the robot should move. This information was received by the bluetooth module on the car and relayed it to the arduino. The arduino then processed this and sent instructions to the motor controller on which way the dc motors should turn. This project taught me so much, from the basics of electrical engineering to in depth knowledge on bluetooth. I believe this can have very important real world applications as being able to wirelessly control robots is the future of tech and can help people who might not be able to physically operate robots or controllers. 
[![Arnav's final Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1657594984/video_to_markdown/images/youtube--S47QvPaVw4s-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/S47QvPaVw4s "Arnav's final Milestone")

# Third Milestone
My third milestone is getting my motor controller and DC motors set up. I could not power my dc motor controller just by the 5 Volts that the arduino outputs so I plugged in a separate battery pack that can output 6 Volts. To eliminate power from being lost or an unstable connection I soldered my wires to the copper tabs on the dc motors. This took a lot of time because I had to make sure I did not burn the copper while putting enough solder to keep the connection secure. The cables that I used were jumper cables with the ends of the wires stripped off. I did this so I had more wire to work with and put inside the screw terminals on the motor controller. The screw terminals represent how the dc motors are powered and which wire is connected to ground. This process is called the H bridge and if you reverse the wires in the H bridge you can change the direction the wheels turn. The motor controller also manages the speed of the wheels by using a system called pulse width modulation or commonly known as pwm. This is a system where the arduino sends square waves of consistent frequency but changes the wavelength which is related to the time in between the peaks of the waves. When it reaches a peak of a wave that is when power is given to the wheels and so by changing the time in between you can thus affect the speed. 

[![Arnav's Third Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1656830763/video_to_markdown/images/youtube--ICBy_ALsH80-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=ICBy_ALsH80 "Arnav's Third Milestone")

# Second Milestone
My second milestone was setting up my accelerometer and getting it to print values. The accelerometer works by using IC2 protocol to read what value you want to hear from (x, y, or z) and then refreshes your request. What this means is that using the Adafruit library you can measure how much you tilt the accelerometer in any direction and return this value to the arduino. This code uses the SCL and SDA pins to communicate with the accelerometer and I will use this in my final project to read the user's gestures and which direction they tilt their wrist.

[![Arnav's Second Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1656718265/video_to_markdown/images/youtube--5d76lhZAEwQ-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=5d76lhZAEwQ "Arnav's Second Milestone")


# First Milestone
My first milestone is setting up my bluetooth modules and binding them together and then testing them with a button and a led. I binded my bluetooth modules by putting them in AT mode and making one module the slave and making one the master module. They communicate over the Rx and Tx lines and the baud rate or rate of communication is 38400 for these modules. I then set up the button for one arduino and a led for another and communicated over the bluetooth modules when to turn the led on or off. I figured out how to do this by using the serial monitor and printing values across arduinos.

[![Arnav's First Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1656707342/video_to_markdown/images/youtube--aD_ejw0PmUQ-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=aD_ejw0PmUQ "Arnav's First Milestone")

# Scimatics and Code

<p align="center">
<img src ="https://raw.githubusercontent.com/Arnav-Gup/BlueStamps-Engineering-Portfolio/gh-pages/guesture_car_scim.png" width=400>
</p>

<details>
<summary>
Robot Car Code

</summary>

```
//change based on motor pins
int motor1f = 6; //in1
int motor1b = 7; //in2
int motor2f = 8; //in3
int motor2b = 9; //in4
int motor1e = 5; //ena
int motor2e = 10; //enb


void setup()
{
  //opens serial monitor and bluetooth serial monitor
  Serial.begin(38400);

  //initializes all motor pins as outputs
  pinMode(motor1f, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2f, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(motor1e, OUTPUT);
  pinMode(motor2e, OUTPUT);
  analogWrite(motor1e, 255);
  analogWrite(motor2e, 255);
}

void loop()
{
  Serial.println("forward");
  forward();
  delay(10000);
  Serial.println("backward");
  back();
  delay(10000);
  Serial.println("left");
  left();
  delay(10000);
  Serial.println("right");
  right();
  delay(10000);
  Serial.println("freeze");
  freeze();
  delay(10000);
}

//moves robot forward 
void back(){
  
    //chages directions of motors
    digitalWrite(motor1f, LOW);
    digitalWrite(motor1b, HIGH);
    digitalWrite(motor2f, HIGH);
    digitalWrite(motor2b, LOW);
  }

//moves robot left
void right(){

    //changes directions of motors
    digitalWrite(motor1f, LOW);
    digitalWrite(motor1b, HIGH);
    digitalWrite(motor2f, LOW);
    digitalWrite(motor2b, HIGH);
  }

//moves robot right
void left(){

    //changes directions of motors
    digitalWrite(motor1f, HIGH);
    digitalWrite(motor1b, LOW);
    digitalWrite(motor2f, HIGH);
    digitalWrite(motor2b, LOW);
  }

//moves robot backwards
void forward(){

    //changes directions of motors
    digitalWrite(motor1f, HIGH);
    digitalWrite(motor1b, LOW);
    digitalWrite(motor2f, LOW);
    digitalWrite(motor2b, HIGH);
  }

//stops robot
void freeze(){

    //changes directions of motors
    digitalWrite(motor1f, LOW);
    digitalWrite(motor1b, LOW);
    digitalWrite(motor2f, LOW);
    digitalWrite(motor2b, LOW);
  }
```

</details>


 <details>
 <summary>
 Robot Car Glove
 </summary>
 ````
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
 ````
 </details>

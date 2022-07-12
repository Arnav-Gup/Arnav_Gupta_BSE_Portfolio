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

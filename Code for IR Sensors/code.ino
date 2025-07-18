#define IR_SENSOR_RIGHT 11
#define IR_SENSOR_LEFT 3
#define IR_SENSOR_MID 4


#define MOTOR_SPEED 180

//Right motor
int enableRightMotor=6;
int rightMotorPin1=10;
int rightMotorPin2=8;

//Left motor
int enableLeftMotor=5;
int leftMotorPin1=9;
int leftMotorPin2=7;

void setup()
{
 
  
  TCCR0B = TCCR0B & B11111000 | B00000010 ;
  
  
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  pinMode(IR_SENSOR_MID, INPUT);
  rotateMotor(0,0);   
}


void loop()
{

  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);
  int midIRSensorValue = digitalRead(IR_SENSOR_MID);


 
  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW && midIRSensorValue == LOW)
  {
    rotateMotor(0,0);
  }


  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW && midIRSensorValue == LOW)
  {
    rotateMotor(-MOTOR_SPEED,MOTOR_SPEED);
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == LOW && midIRSensorValue == HIGH)
  {
     rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
     
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW && midIRSensorValue == HIGH)
  {
     rotateMotor(-MOTOR_SPEED,MOTOR_SPEED);
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH && midIRSensorValue == LOW)
  {
     rotateMotor(MOTOR_SPEED,-MOTOR_SPEED);
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == HIGH && midIRSensorValue == LOW)
  {
     rotateMotor(MOTOR_SPEED,MOTOR_SPEED);
  }
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH && midIRSensorValue == HIGH)
  {
     rotateMotor(MOTOR_SPEED,-MOTOR_SPEED);
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == HIGH && midIRSensorValue == HIGH)
  {
     rotateMotor(MOTOR_SPEED,MOTOR_SPEED);
  }
  
} 
  

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);
    delay(15);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW); 
    delay(15);   

  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);  
    delay(15);       
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);  
    delay(15);     
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW); 
    delay(15);        
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);  
    delay(15);       
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}






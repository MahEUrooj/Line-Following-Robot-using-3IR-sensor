#define LeftMotorReverse 3
#define LeftMotorForward 5
#define RightMotorForward 6
#define RightMotorReverse 9

#define leftIR A0
#define rightIR A1
#define middleIR A2

void setup() {
  // put your setup code here, to run once:
  pinMode(LeftMotorForward,OUTPUT);
  pinMode(RightMotorForward,OUTPUT);
  pinMode(LeftMotorReverse,OUTPUT);
  pinMode(RightMotorReverse,OUTPUT);
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(middleIR, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(leftIR) == LOW  && analogRead(rightIR) == HIGH  && analogRead(middleIR) ==HIGH)//Right
  {
    analogWrite(LeftMotorForward,HIGH);
    analogWrite(RightMotorForward, LOW);
  }

  else if(analogRead(leftIR) == HIGH  && analogRead(rightIR)== LOW && analogRead(middleIR) == HIGH) //Left
  {
    analogWrite(LeftMotorForward,LOW);
    analogWrite(RightMotorForward,HIGH);
  }
  else if(analogRead(leftIR) == HIGH && analogRead(rightIR)== HIGH && analogRead(middleIR)== HIGH)//Stop
  {
    analogWrite(LeftMotorForward,LOW);
    analogWrite(RightMotorForward,LOW);
  }
  else if(analogRead(leftIR)== LOW && analogRead(rightIR)== LOW && analogRead(middleIR)==HIGH)//Forward
  {
    analogWrite(LeftMotorForward,HIGH);
    analogWrite(RightMotorForward,HIGH);
  }
  delay(1);
}

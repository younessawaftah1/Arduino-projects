
const int s0=7;
const int s1=6;
const int S2=8;
const int S3=9;
const int sensorOut=10;
const int wellLed = 5;
const int redLed = 4;  
const int greenLed = 3;  
const int blueLed = 2;
unsigned int red;  
unsigned int green;  
unsigned int blue;
int color;  

void setup(){
  Serial.begin(9600);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT); 
  pinMode(redLed, OUTPUT);  
  pinMode(greenLed, OUTPUT);  
  pinMode(blue, OUTPUT);
  pinMode(wellLed , OUTPUT);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  
}

void loop(){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  red = pulseIn(sensorOut,LOW);
  delay(20);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  green = pulseIn(sensorOut,LOW);
  delay(20);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blue = pulseIn(sensorOut,LOW);
  delay(20);
  color = (red+green+blue)/3;
    Serial.print("red: ");
    Serial.print(red);
    Serial.print(" green: ");
    Serial.print(green);
    Serial.print(" blue: ");
    Serial.print(blue);
    Serial.print(" color: ");
    Serial.println(color);
  delay(200);
  if ((color > 16) && (color < 22))
  {  
    digitalWrite(redLed, LOW); 
   digitalWrite(greenLed, LOW);
   digitalWrite(blueLed, LOW);
   digitalWrite(wellLed, HIGH);    // Turn well LED ON
}
  else if ((color > 54) && (color < 64))
  {  
    digitalWrite(redLed, LOW); 
   digitalWrite(greenLed, HIGH);   // Turn green LED ON
   digitalWrite(blueLed, LOW);
   digitalWrite(wellLed, LOW);
}
  else if  ((color > 40) && (color < 50))
  {  
    digitalWrite(redLed, HIGH); // Turn red LED ON 
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, LOW);
   digitalWrite(wellLed, LOW);
}
  else if  ((color > 30) && (color < 40))
  {  
    digitalWrite(redLed, LOW); 
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, HIGH); // Turn blue LED ON 
   digitalWrite(wellLed, LOW);
}
  else{  
    digitalWrite(redLed, LOW); 
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, LOW); 
   digitalWrite(wellLed, LOW);
}
}
  
  

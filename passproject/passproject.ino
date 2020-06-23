//#include <Key.h>
#include <Keypad.h>
#include <Password.h>
 
String newPasswordString;
char newPassword[6];

Password password = Password( "9980" );
 
byte maxPasswordLength = 6; 
byte currentPasswordLength = 0;
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
}; 
byte rowPins[ROWS] = {8,7,6,5};
byte colPins[COLS] = {4,3,2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int greenLED = 13;
int blueLED = 12;
int pir=9;
int val=0;
 
void setup(){
   Serial.begin(9600);
pinMode(greenLED,OUTPUT);
pinMode(blueLED,OUTPUT);
pinMode(pir,INPUT);
 }
 
void loop(){
  val=digitalRead(pir);
  digitalWrite(greenLED,val);
   char key = keypad.getKey();
   if (key != NO_KEY){
      delay(60); 
      switch (key){
      case '#': checkPassword(); break;
      case '*': resetPassword(); break;
      default: processNumberKey(key);
      }
   }
}
 

void checkPassword() {
   if (password.evaluate()){
      Serial.println(" Password Accepted!");
    //  digitalWrite (greenLED, HIGH);
        
    if(val==1)
      digitalWrite(greenLED,LOW);
         digitalWrite (blueLED, HIGH);
        

   } else {
      Serial.println(" Password Incorrect!");
   } 
   resetPassword();
   
}

void resetPassword() {
   password.reset(); 
   currentPasswordLength = 0; 
}
void processNumberKey(char key) {
   Serial.print(key);
   currentPasswordLength++;
   password.append(key);
   if (currentPasswordLength == maxPasswordLength) {
      checkPassword();
   } 
}

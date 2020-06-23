#define RELAY1  7                        
void setup()
{    
Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);       

}
 void loop()
{

   digitalWrite(RELAY1,0);           // Turns Off Relays 1
   Serial.println("Light ON");
   delay(2000);                                      // Wait 2 seconds

   digitalWrite(RELAY1,1);          // Turns Relay On
   Serial.println("Light OFF");
   delay(2000);
   
}

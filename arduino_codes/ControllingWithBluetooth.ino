#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 

int LED = 8; 

void setup() 
{   
 Serial.begin(9600);
 MyBlue.begin(9600);
 pinMode(LED, OUTPUT);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000");
}

void loop() 
{ 
 if (MyBlue.available())
 {
   String msg = MyBlue.readString();
   if (msg == "<turn on>") 
   {
    digitalWrite(LED, HIGH);
    MyBlue.println("LED is turned on\n"); // Then send status message to Android
   }
   else
   {
    digitalWrite(LED, LOW); 
    MyBlue.println("LED is turned off\n"); // Then send status message to Android
   }
   Serial.println(msg);
 }
}  
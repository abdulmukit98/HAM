#include <SoftwareSerial.h> 

SoftwareSerial bluetoothModule(2, 3); // RX | TX 

#define POWER_LED 8 // Load2 Pin Out

int n_load = 4;
int loadPins[] = { 13, 12, 11, 10 };

void setup() 
{
 Serial.begin(9600);
 bluetoothModule.begin(9600);
 for (int i = 0; i < n_load; i++) {
  pinMode(loadPins[i], OUTPUT);
 }
 pinMode(POWER_LED, OUTPUT);
 delay(500);
}

void loop() 
{
 if (bluetoothModule.available())
 {
   String message = bluetoothModule.readString();
   if (message[0] == '#')
   {
    int x = 0;
    for (int i = 1; i <= n_load; i++) {
      int b = message[i] - '0';
      x = x | b;
      digitalWrite(loadPins[i - 1], b);
    }
    digitalWrite(POWER_LED, x);
    bluetoothModule.println("OK " + message);
   }
   else {
    bluetoothModule.println("NOT_OK " + message);
   }
 }
}
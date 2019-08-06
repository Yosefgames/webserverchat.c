
 // http://www.arduino.cc/trigger/Button
 
 
#include <Bridge.h>
#include <HttpClient.h>
#include <SPI.h>
#include <Ethernet.h>


// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
	{
		
  while (Post.available()) { //Check connection status
    HTTPClient Post;
    Post.begin(" https://mudita.fun/api/v1/triggers"); 
    Post.addHeader("operator", "text/plain");  
    Post.POST("Key=hi&val=jagrut1");
    String payload = Post.getString();
    Post.end();
  } 
  delay(500);  
}
	
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}


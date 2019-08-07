
// http://www.arduino.cc/mudita/trigger/Button


#include <Bridge.h>
#include <HttpClient.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Bridge.h>
#include <HttpClient.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
//#include "WebServer.h"

#define USE_DHCP_FOR_IP_ADDRESS
#define USE_IMAGES
#define USE_ARDUINO_ICON

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
char server = "\r\n";
char Post   = "\002";
unsigned char HTTPClient = "";


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  server = new EthernetServer(80);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB port only
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);


    /*(Post.available())  //Check connection status*/
    HTTPClient Post
    Post.begin(" https://mudita.fun/api/v1/triggers");
    Post.addHeader("operator", "text/plain");
    Post.POST("Key=hi&val=jagrut1");
    String payload = Post.getString();
    Post.end();


  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10); // CE, CSN

long duration; // variable for the duration of sound wave travel
int distance;
int NewDistance;
const byte address[6] = "00001";

void setup() {

Serial.begin(115200);

radio.begin();
radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
radio.setPALevel(RF24_PA_MAX);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
radio.startListening();              //This sets the module as receiver

Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
Serial.println("Openened Serial Terminal");
}

void loop()
{
  
  
if (radio.available())              //Looking for the data.
{

const char text[32] = "";                 //Saving the incoming data
radio.read(&text, sizeof(text));    //Reading the data
Serial.println(text);

int distance2 = "";
radio.read(&distance2, sizeof(distance2));    //Reading the data
Serial.println(distance2);
radio.read(&duration, sizeof(duration));    //Reading the data

NewButtonPress = (int) distance2;
Serial.println();
Serial.println();
Serial.println("NEWDISTANCE");
Serial.println(NewDistance);
Serial.println();  
}


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <TinkerController.h>



// defines variables
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
long duration; // variable for the duration of sound wave travel
int distance2; // variable for the distance measurement

TinkerController controller;

void setup() {

    Serial.begin(115200);
    Serial.println("Begin");
    controller.setup();

    radio.begin();                  //Starting the Wireless communication
    radio.openWritingPipe(address); //Setting the address where we will send the data
    radio.setPALevel(RF24_PA_MAX);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
    radio.stopListening();          //This sets the module as transmitter

}

void loop() {

    const char text[] = "Connection has been made";
    radio.write(&text, sizeof(text));

    TinkerEvent e = controller.getEvent();
    
    // Event Occured?
    if(e.ok) {
        char eventType = e.type;
        int value = e.value;

        Serial.print("Event type: ");
        Serial.println(eventType);
        Serial.print("Value: ");
        Serial.println(value);
    }
    radio.write(&value, sizeof(value));
  
}

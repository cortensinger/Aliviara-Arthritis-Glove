/*********************************************************************
 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!

 MIT license, check LICENSE for more information
 All text above, and the splash screen below must be included in
 any redistribution
*********************************************************************/

#include <Arduino.h>
#include <SPI.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
  #include <SoftwareSerial.h>
#endif

#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "BluefruitConfig.h"
    #define FACTORYRESET_ENABLE         1
    #define MINIMUM_FIRMWARE_VERSION    "0.6.6"
    #define MODE_LED_BEHAVIOUR          "MODE"

// Create the bluefruit object using hardware SPI, using SCK/MOSI/MISO 
// hardware SPI pins and then user selected CS/IRQ/RST
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}


/*=========================================================================*/
/*=========================================================================*/
/*=========================================================================*/

int thumb = A0;
int index = A1;
int middle = A2;
int ring = A3;
int pinky = A4;
int thumbVal;
int indexVal;
int middleVal;
int ringVal;
int pinkyVal;


void setup(void)
{
  while (!Serial);
  delay(500);

  pinMode(thumb, INPUT);
  pinMode(index, INPUT);
  pinMode(middle, INPUT);
  pinMode(ring, INPUT);
  pinMode(pinky, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(115200);
  Serial.println(F("------------------------------------------+"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK! |") );
  Serial.println(F("------------------------------------------+"));
  Serial.println(F("Program now starting\n"));

  ble.verbose(false);

  /* Wait for connection */
  while (! ble.isConnected()) {
      delay(500);
  }
}

void loop(void)
{
  thumbVal = analogRead(thumb);
  indexVal = analogRead(index);
  middleVal = analogRead(middle);
  ringVal = analogRead(ring);
  pinkyVal = analogRead(pinky);
  thumbVal = map(thumbVal, 520, 730, 0, 100);
  indexVal = map(indexVal, 490, 740, 0, 100);
  middleVal = map(middleVal, 450, 730, 0, 100);
  ringVal = map(ringVal, 510, 755, 0, 100);
  pinkyVal = map(pinkyVal, 505, 780, 0, 100);
  
  /*
  ble.print("AT+BLEUARTTX=");
  ble.println(thumbVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(indexVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(middleVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(ringVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(pinkyVal);
  */
  
  ble.print("AT+BLEUARTTX=");
  ble.println(thumbVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(indexVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(middleVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(ringVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(pinkyVal);
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  ble.print("AT+BLEUARTTX=");
  ble.println(" \n");
  
  Serial.println("=============================");
  Serial.print("Thumb Flex Value: ");
  Serial.println(thumbVal);
  Serial.print("Index Flex Value: ");
  Serial.println(indexVal);
  Serial.print("Middle Flex Value: ");
  Serial.println(middleVal);
  Serial.print("Ring Flex Value: ");
  Serial.println(ringVal);
  Serial.print("Pinky Flex Value: ");
  Serial.println(pinkyVal);
  Serial.println("=============================\n\n");

  delay(500);

  // check response stastus
  if (! ble.waitForOK() ) {
    Serial.println(F("Failed to send?"));
  }
  

  /*
   * Each message they send back to the Microcontroller is followed
   * by an "OK" message with just the 2 chars "OK". This denotes the
   * end of the message here.
  */
  ble.println("AT+BLEUARTRX");
  ble.readline();
  if (strcmp(&ble.buffer[1], "OK") == 0) {
    // no data
    return;
  }
  Serial.println(&ble.buffer[1]);
  
  if (strcmp(&ble.buffer[1], "f") == 0) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    delay(1500);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  } else if (strcmp(&ble.buffer[1], "s") == 0) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(100);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  } else if (strcmp(&ble.buffer[1], "mon") == 0) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  } else if (strcmp(&ble.buffer[1], "moff") == 0) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  
  ble.waitForOK();
}

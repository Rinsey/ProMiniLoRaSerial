#include <SPI.h>
#include <LoRa.h>

String sentencia;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

}

void loop() {

  if(Serial.available()){
    sentencia = Serial.readString();
    // send packet
    LoRa.beginPacket();
    LoRa.print(sentencia);
    LoRa.endPacket();
  }

  delay(1000);
}
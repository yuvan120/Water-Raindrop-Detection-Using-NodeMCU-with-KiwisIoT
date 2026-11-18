#include <KiwisIoT.h>

const char* ssid = "wifi name ";
const char* pass = "password";
const char* topic = "dash_1791290485440";

#define RAIN_PIN A0

KiwisIoT kiwisiot(ssid, pass, topic);

void setup() {
  Serial.begin(115200);
  delay(1000);

  kiwisiot.begin();

  Serial.println();
  Serial.println("Raindrop Sensor Started");
}

void loop() {
  kiwisiot.run();

  // Read raindrop sensor analog value
  int rainValue = analogRead(RAIN_PIN);

  Serial.print("Raindrop Sensor Value: ");
  Serial.println(rainValue);

  // Send raindrop sensor value to KiwisIoT Channel 1
  kiwisiot.send("1", rainValue);

  delay(2000);
}
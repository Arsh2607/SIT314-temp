
#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  Serial.println("CLEARDATA");
  Serial.println("LABEL, time, temp");
   Serial.println("RESETTIMER");
  

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(4000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temp = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(temp) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  
  float hic = dht.computeHeatIndex(temp, h, false);

 
 
  Serial.println(temp);
  Serial.print("DATA, TIME, TIMER, DATE,");
  Serial.print(temp);
 
  
}

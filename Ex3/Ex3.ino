#include <DHT.h>
#define DHTPIN 2     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11

// Define the class object for the sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  // Initialize device.
  dht.begin();
  Serial.println("Group 462 DHT11");
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  double h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  double t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  double f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.print(f);
  // Delay between measurements.
  delay(500);
}

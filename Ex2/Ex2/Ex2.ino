#define ECHO_PIN 0
#define TRIGGER_PIN 0
void setup() {
  pinMode(TRIGGER_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  Serial.begin(115200); 
  Serial.println("Welcome to group 462's ultrasonic demonstrator"); 
}

void loop() {
  //This does the trigger pulse to get the sensor going
  digitalWrite(TRIGGER_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGGER_PIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGGER_PIN, LOW);

  //Read the pulse, https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/
  unsigned long ultra_sonic_output = pulseIn(ECHO_PIN, HIGH);
  Serial.print("Pulse (us): "); 
  Serial.print(ultra_sonic_output); 
  Serial.print("\t "); 
  //Fix this to get the actual distance!
  float distance_m = (ultra_sonic_output*0.0001)/2.0;
  Serial.print("Distance: "); 
  Serial.println(distance_m); 
  delay(250); 
}

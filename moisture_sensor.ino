void setup(){
  Serial.begin(9600);//comm initialized at 9600 bits per sec
}

void loop(){
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);// Need to do something later
  // Air = sensorValue of 674
  // Straight, filtered water = sensorValue of 324
  delay(100); // Wait 100 micro seconds before continuing
}  

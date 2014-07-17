void setup(){
  Serial.begin(9600);//comm initialized at 9600 bits per sec
}

void loop(){
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  Serial.print("1: ");
  Serial.print(sensorValue1);
  Serial.print("    2: ");
  Serial.println(sensorValue2);// Need to do something later
  // Air = sensorValue of 674
  // Straight, filtered water = sensorValue of 324
  delay(100); // Wait 100 micro seconds before continuing
}  

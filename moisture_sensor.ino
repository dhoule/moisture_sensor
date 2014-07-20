void setup(){
  delay(500);
  Serial.begin(9600);//comm initialized at 9600 bits per sec
  delay(500);
}

void loop(){
  int ct = determine_used_input_count();
  int inputs[ct], value;
  determine_used_inputs(inputs);
  for(int i = 0; i < ct; i++){
    value = analogRead(inputs[i]);
    Serial.print(inputs[i]);
    Serial.print(": ");
    Serial.print(value); 
    Serial.print("  ");
  }
  Serial.println("");
  // Air = sensorValue of 674
  // Straight, filtered water = sensorValue of 324
  delay(100); // Wait 100 micro seconds before continuing
} 
/*
  Function returns the number of analog inputs that are being used for moisture sensors
*/
int determine_used_input_count(){
  int availableInputs[16] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15};
  int ct = 0, input;
  for(int i = 0; i < 16; i++){
    input = analogRead(availableInputs[i]);
    if(input != 0){
      ct++;
    }  
  }  
  
  return ct; 
}  

/*
  Function modifies the array given to it by filling it with the analog inputs that are being used for 
  moisture sensors
*/
void determine_used_inputs(int *inputs){
  int availableInputs[16] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15};
  int other[16];
  int ct = 0, input = 0;
  for(int i = 0; i < 16; i++){
    input = analogRead(availableInputs[i]);
    if(input != 0){
      other[ct] = availableInputs[i];
      ct++;
    }  
  }  
  
  for(int i = 0; i < ct; i++){
    inputs[i] = other[i];
  }  
}  

//this code will simply read the A0 value
void setup() {
  //we enable the serial monitor so we can display whatever we want on it later
  Serial.begin(9600);

}

void loop() {
//we create a variable to store the potentiometer value 
int pot_value= analogRead(A0);
//to scale the value to a votlage we must do some math. the pot value gets divided by the mx which is 1024
//this will find whats the percentage of the 5v is is reading. we thens imply multiply it by 5 to see it in 
//volts and not percentage
int volts_value= (pot_value/1024)*5;
//we take all this data and print it as we wish on the monitor
Serial.print("Potentiometer value is:");
// using the \t will create a tab in our text that is standard and improves readbility
Serial.print("\t");
Serial.print(pot_value);
Serial.print("Voltage value is:");
Serial.print("\t");
Serial.print(volts_value);

}

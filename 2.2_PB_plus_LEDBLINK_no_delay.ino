//first we define the variable ledstate tat will be used to tunr on our led or turn it off 
int ledState = LOW;
//to blink wihout delay we are goin to use the millis fucntion whihc is a counter that works all the time
//as soon as the arduino starts. To use need we to define the last time the delay completed
//we do this with the previousMillis variable
unsigned long previousMillis = 0; 
//here we simply define the interval at whihc the led will blink
const long interval = 1000;
void setup() {
//before we begin our loop process we must define our pins and which function they fufill 
//in this case they are being used as OUTPUTS so we define them as such and we define pin 3 as an input
//for the button
  pinMode(2, OUTPUT);
  pinMode(3,INPUT_PULLUP);
//we must enable the serial monitor at the start of this code 
  Serial.begin(9600);
}

void loop() {
//in this line we check the cureent millis amount so we can compare it later
unsigned long currentMillis = millis();
//we read the button value and store it in a variable
int pb= digitalRead(3);
//we compare the current milli count to the previous time the delay finished and the state changed
//if this delay is bigger or equal to our interval it will switch the state of the LED
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and if its off tunr it on any time the IF command is fufilled 
    //(i.e delay is completed)
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

  //we then write to the LED the LOW state or the HIGH state
    digitalWrite(2, ledState);
  }
//we use the serial print fucntion to display the value of the push buttona dn the LED to see in which
//state they currently are
Serial.print("PB value is ");
Serial.print("\t");
Serial.print(pb);
Serial.print("\t ");
Serial.print("The LED value is ");
Serial.print("\t");
Serial.println(ledState);
}

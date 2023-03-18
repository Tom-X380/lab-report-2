//this is a simple code that alows us to control the scale of all three values in the RGB scale 
//allowing us to creat new colors

//before the code beings we define variables for the red, green and blue pins of the rgb
//this helps us switch them faster as it will change the pin value for all those vairables for the whole code
int blue=4;
int green=3;
int red=2;

void setup() {
//before we begin our loop process we must define our pins and which function they fufill 
//in this case they are being used as OUTPUTS so we define them as such 
pinMode(blue, OUTPUT);
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);


}

void loop() {
//before we write any values to the rgb we must scale the pot value to the pwm value 
//since the analog read goes from 0 to 1024 while the analog out goes from 0 to 255

int pot_value = analogRead(A0);
int rgb_value = pot_value/4;
//we then write the scaled value to the rgb so it  changes with the pot value
analogWrite(red,rgb_value)
analogWrite(green,rgb_value)
analogWrite(blue,rgb_value)
}

//this is a simple code that alows us to control the scale of all three values in the RGB scale 
//allowing us to creat new colors

//before the code beings we define variables for the red, green and blue pins of the rgb
//this helps us switch them faster as it will change the pin value for all those vairables for the whole code
int blue=3;
int green=5;
int red=6;

void setup() {
//before we begin our loop process we must define our pins and which function they fufill 
//in this case they are being used as OUTPUTS so we define them as such 
pinMode(blue, OUTPUT);
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);
//we must also begin the serial monitor so we can use it to display values
Serial.begin(9600);
}

void loop() {
//before we write any values to the rgb we must scale the pot value to the voltage valyue
//since the analog read goes from 0 to 1024 
float pot_value= analogRead(A0);
float volts_value= (pot_value/1023)*5;
//we then use if statements to compare and see what vale the voltage is
if (volts_value<=1) {
//if the value is below 1 we will print on the serial monitor that the voltage is low and make the rgb a certain color
Serial.print("Voltage is : \t");
Serial.print(volts_value);
Serial.println("\tVOLTAGE LOW INCREASE");
analogWrite(red,255);
analogWrite(blue,30);
analogWrite(green,0);

}
//if the value is between 1 and 4.5 we will print on the serial monitor that the voltage is normal and make the rgb a certain color second color
if (volts_value>1 && volts_value<4.5) {
Serial.print("Voltage is : \t");
Serial.print(volts_value);
Serial.println("\tVOLTAGE NORMAL");
analogWrite(red,255);
analogWrite(blue,235);
analogWrite(green,20);

}
//if the value is above 4.5 we will print on the serial monitor that the voltage is at the max level and make the rgb a certain color third color
if (volts_value>4.5) {
Serial.print("Voltage is : \t");
Serial.print(volts_value);
Serial.println("\tVOLTAGE MAX ");
analogWrite(red,17);
analogWrite(blue,30);
analogWrite(green,255);

}
}

//before the code beings we define variables for the red, green and blue pins of the rgb
//this helps us switch them faster as it will change the pin value for all those vairables for the whole code
//we also define the Value for all colors of the rgb so we can scale them with the analog output 
//because if the three colors have ifferent power levels we can combine them to create different new colors like
//yellow,purple,pink,etc.
int blue=4;
int green=3;
int red=2;
int Rvalue= 0;
int Gvalue= 0;
int Bvalue= 0;
void setup() {
//before we begin our loop process we must define our pins and which function they fufill 
//in this case they are being used as OUTPUTS so we define them as such 
pinMode(blue, OUTPUT);
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);

}

void loop() {
//we now write the Red value, Green value, and Blue value we defined earlier to th rgb and can change
//those values to create new colors that are not red green or blue 
analogWrite(red,Rvalue)
analogWrite(green,Gvalue)
analogWrite(blue,Bvalue)
}

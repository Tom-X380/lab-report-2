//this code reads the pot value and displays the volt value and the bit value but this time on the 
//lcd display we connect in real life

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int new_ORV;
int new_ORV2;

//here is where we define the custom ohm charcter by using the 5 by 8 matrix 
byte ohms[8] = {
	0b00000,
	0b00000,
	0b01110,
	0b10001,
	0b10001,
	0b01010,
	0b11011,
	0b00000
};
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
Serial.begin(9600);
pinMode(3, INPUT_PULLUP);
pinMode(2, INPUT_PULLUP);

lcd.createChar(0,ohms);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);

e create a variable to store the voltage at the middle point between the resistors 
float z = analogRead(A0);
//to scale the value to a votlage we must do some math. the pot value gets divided by the mx which is 1024
//this will find whats the percentage of the 5v is is reading. we thens imply multiply it by 5 to see it in 
//volts and not percentage
float A1_volts = (z/1023)*5;
//we then use the voltage divider law to find the unknown resitor value 
float ORV = (5000/(5-A1_volts))-1000;


}
//if the resitor is dbelow 1000 it is dsiplayed normally
if(ORV<1000){
lcd.clear();
lcd.print("R=");
lcd.print(ORV);
lcd.write(byte(0));
lcd.setCursor(0,1);
lcd.print("screen 3#");

}
//wihtin the ohmmeter screen we scale the value becuase if is above 1000 ohms it will take up to much space
//so we scale it to a smaller size and then add "k" to indicate it is one thousand

if(ORV>1000 && ORV<100000000){
float new_ORV= (ORV/1000);
lcd.clear();
lcd.print("R=");
lcd.print(new_ORV);
lcd.print("K");
lcd.write(byte(0));
lcd.setCursor(0,1);
lcd.print("screen 3#");
}
}
}
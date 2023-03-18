//this code reads the pot value and displays the volt value and the bit value but this time on the 
//lcd display we connect in real life

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
pinMode(2,INPUT_PULLUP);
  // Print a message to the LCD.
 
pinMode(13, INPUT);
}

void loop() {
//we store the button value in the variable and we inver it because it is in a input pullup config
bool pb_value = !digitalRead(2);
//we create a variable to store the potentiometer value 
int pot_value= analogRead(A0);
//to scale the value to a votlage we must do some math. the pot value gets divided by the mx which is 1024
//this will find whats the percentage of the 5v is is reading. we thens imply multiply it by 5 to see it in 
//volts and not percentage
int volts_value= (pot_value/1024)*5;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);

//we check if the button is on or off to see which screen to display
if(pb_value==1){
lcd.setCursor(0,1);
lcd.print("Volts");
lcd.print(volts_value);
}
else{
lcd.setCursor(0, 0);
lcd.print("Bit:");
lcd.print(pot_value); 
}
}



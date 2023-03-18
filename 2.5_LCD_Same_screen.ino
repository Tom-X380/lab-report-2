//this code reads the pot value and displays the volt value and the bit value but this time on the 
//lcd display we connect in real life

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
 
pinMode(13, INPUT);
}

void loop() {
  
int pot_value= analogRead(A0);
int volts_value= (pot_value/1024)*5;
// set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
//we then print the values we collected and calculted.
lcd.print("Bit:");
lcd.print(pot_value);
lcd.setCursor(1,0);
lcd.print("Volts");
lcd.print(volts_value);
}



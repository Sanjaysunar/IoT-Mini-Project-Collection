#include <LiquidCrystal.h>
int light = 0; 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
    // put your setup code here, to run once:
    lcd.begin(16,2);
    lcd.clear();
    lcd.setCursor(0,0);
    //lcd.print("Condition");
    Serial.begin(9600); 
    pinMode(8, OUTPUT); 
    
}

void loop() {
    // put your main code here, to run repeatedly:
    light = analogRead(A0); // read and save value from PR
    
    Serial.println(light); // print current light value
     
    if(light > 100) { // If it is bright...
        Serial.println("It is quite light!");
        digitalWrite(8,LOW); //turn LED off
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print("LIGHT OFF");
        lcd.setCursor(0,1);
        lcd.print("Saving power!");
        
    }
    
    else { // If it's dark...
        Serial.println("It is pretty dark!");
        digitalWrite(8,HIGH); // Turn left LED on
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print("LIGHT ON");
        lcd.setCursor(0,1);
        lcd.print("Overcome dark!");
        
    }
    delay(1000); 
}

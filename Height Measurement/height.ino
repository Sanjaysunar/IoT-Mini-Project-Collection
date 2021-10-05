#include <LiquidCrystal.h>

const int trigger_pin = 8;
const int echo_pin = 9;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);

  digitalWrite(trigger_pin, LOW);
  digitalWrite(echo_pin, LOW);


  /*LED SETUP */
  lcd.begin(16,2);

  //lcd.setCursor(1,1);
  //lcd.print("testing");

}

void loop() {
   lcd.setCursor(0,0);
   lcd.clear();
  lcd.print("Height Measured: ");
  //
  // put your main code here, to run repeatedly:
   lcd.setCursor(0,1);
   
   digitalWrite(trigger_pin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger_pin, LOW);
   duration = pulseIn(echo_pin, HIGH);

   distance = ( duration * 0.034 ) / 2;
   distance -= 6.5;

   float distance_ft = distance * 0.0328084;
   int df_int = (int)distance_ft;
   double df_dbl = distance_ft - df_int;
   String df_int_str = String(df_int);
   String df_dbl_str = String(df_dbl);
   if(distance_ft < 1)
     lcd.print(String(df_dbl_str + " Inch"));
   else if(distance == 1)
      lcd.print(String(df_int_str + " Foot"));
   else
      lcd.print(String(df_int_str + " Ft. " + df_dbl_str + " Inch"));
   delay(1000);

}

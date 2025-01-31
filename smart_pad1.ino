#include <LiquidCrystal.h>  

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define MOISTURE_SENSOR A0  
#define BUZZER 9  
#define LED 7  
#define THRESHOLD 500  // Adjust based on sensor readings

void setup() {  
    pinMode(MOISTURE_SENSOR, INPUT);  
    pinMode(BUZZER, OUTPUT);  
    pinMode(LED, OUTPUT);  
    lcd.begin(16, 2);  
    lcd.print("Smart Pad Ready");  
    delay(2000);  
    lcd.clear();  
}  

void loop() {  
    int moisture = analogRead(MOISTURE_SENSOR);  
    lcd.setCursor(0, 0);  
    lcd.print("Moisture: ");  
    lcd.print(moisture);  

    if (moisture > THRESHOLD) {  
        digitalWrite(BUZZER, HIGH);  
        digitalWrite(LED, HIGH);  
        lcd.setCursor(0, 1);  
        lcd.print("Change Pad Now!");  
    } else {  
        digitalWrite(BUZZER, LOW);  
        digitalWrite(LED, LOW);  
        lcd.setCursor(0, 1);  
        lcd.print("Status: Normal");  
    }  
    delay(1000);  
}
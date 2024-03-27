#include <Arduino.h>


int analogInput = 0; // Nummer des verwendeten analogen Pins hier einsetzen
float volt = 0.0;
int wert = 0;
float leistung = 0;
int widerstand = 15; // Wert des Widerstands hier einsetzen
int leistungswerte[180]; // Max 3min!
int counter = 0;
int zeit = 1000;
int multiplikator = 1000;
int runder = 0;
unsigned long Start = 0;

void setup() {
Serial.begin(9600);
pinMode(analogInput, INPUT);
}

void loop() {
Start = millis(); // Startwert setzen

wert = analogRead(analogInput);
volt = (wert * 5.0) / 1024.0; // ACHTUNG: Max 5V Spannung anlegen!
leistung = volt * volt / widerstand; // P = U² / R


if (volt > 0 && counter < 180) {

leistungswerte[counter] = leistung * multiplikator; // Umwandlung in Integer

counter++;

Serial.print(0);
Serial.print(" ");
Serial.print(volt);
Serial.print(" ");
Serial.println(leistung);

}


else {

if (counter > 0){
Serial.println("Leistungswerte:");
Serial.print("0");
Serial.print(",");

for (int i = 0; i < counter; i++) {
Serial.print(leistungswerte[i]);
Serial.print(",");
}

Serial.println("0");
counter = 0;
}

Serial.print(0);
Serial.print(" ");
Serial.print(volt);
Serial.print(" ");
Serial.println(leistung);
delay(zeit);
}


while (millis() <= (Start + zeit)) {
// warten bis der wert der vergangenen Zeit gößer als der Startwert + die gewuenschte Wartezeit ist.
}

}

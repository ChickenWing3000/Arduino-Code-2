int analogInput = 0; // Nummer des verwendeten analogen Pins hier einsetzen
float volt = 0.0;
int wert = 0;
float leistung = 0;
int widerstand = 470; // Wert des Wiederstands hier einsetzen
void setup() {
 Serial.begin(9600);
 pinMode(analogInput, INPUT);
}
void loop() {
wert = analogRead(analogInput);
volt = (wert * 5.0) / 1024.0; // ACHTUNG: Max 5V Spannung anlegen! 
leistung = volt * volt / widerstand; // U² * R = L
Serial.print(0);
Serial.print(" ");
Serial.print(volt);
Serial.print(" ");
Serial.println(leistung);
}
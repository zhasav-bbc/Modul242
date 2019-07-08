/* Author: Lisi Useini & Vion Hasaj
   Nutzen: Die Schaltung ist dazu da, die Zeit messen zu können.
   Datum: 05.07.2019
*/

int gruen[] = {1,2,3,4,5}; // Pins 1-5 für die grüne Lämpchen
int rot[] = {6,7,8,9,10};  // Pins 6-10 für die rote Lämpchen
int buttonStatus = 0;
const int buttonPin = 12; // Pin Nr. für den Button


void setup() {
  
  //gruen = Sekunden
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  //rot = Minuten
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  //Button
  pinMode(buttonPin, INPUT); // High or Low
}

void loop() {
  
  buttonStatus = digitalRead(buttonPin); // Der Zustand des Button im Pin 12 wird gelesen.
  if (buttonStatus == HIGH){
  
   for (unsigned i = 0; i < 10; i++){
      alleSekAusschalten();
        for (unsigned y = 0; y < 10; y++){
          delay(10000); // 10'000 ms = 10 sek
          digitalWrite(gruen[y], HIGH);
        }
        delay(10000); // Nach der for-Schleife beträgt die Sekundenzahl 50 und hier werden die letzten 10 Sekunden gezählt
        digitalWrite(rot[i], HIGH); 
    }
    alleMinAusschalten();
    erfolg();
  }
}

// Alle Grüne Lichter ausschalten
void alleSekAusschalten(){

  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  }

// Alle Rote Lichter ausschalten
void alleMinAusschalten(){

  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  }

// Alle Lichter blinken (Rot und Grün)
void alleBlinken(){
  
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  }

// Sobald 10min vorbei sind, leuchten die Lichter der Reihe nach an.

void erfolg(){
  
  for (unsigned x = 0; x < 10; x++){
    
      digitalWrite(1, HIGH);
      delay(100);
      digitalWrite(1, LOW);
      
      digitalWrite(2, HIGH);
      delay(100);
      digitalWrite(2, LOW);
      
      digitalWrite(3, HIGH);
      delay(100);
      digitalWrite(3, LOW);
      
      digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(4, LOW);
      
      digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(5, LOW);
      
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6, LOW);

      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      
      digitalWrite(8, HIGH);
      delay(100);
      digitalWrite(8, LOW);

      digitalWrite(9, HIGH);
      delay(100);
      digitalWrite(9, LOW);

      digitalWrite(10, HIGH);
      delay(100);
      digitalWrite(10, LOW);
      delay(1000);
   }
}

/* Author: Lisi Useini & Vion Hasaj
   Nutzen: Ein simpler Taschenrechner.
   Datum: 05.07.2019
*/
.
#include<Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', 'C'},
  {'*', '0', '=', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x3F, 16, 2);

boolean firstNumState = true;
String firstNum = "";
String secondNum = "";
float result = 0.0;
char operatr = ' ';

void setup() {
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("Arduino Calculator");
  lcd.setCursor(0, 1);
  lcd.print("hello");
  delay(1000);
  scrollDisplay();
  clr();
}

void loop() {
  char newKey = myKeypad.getKey();
  if (newKey != NO_KEY && (newKey == '1' || newKey == '2' || newKey == '3' || newKey == '4' || newKey == '5' || newKey == '6' || newKey == '7' || newKey == '8' || newKey == '9' || newKey == '0')) {

    if (firstNumState == true) {
      firstNum = firstNum + newKey;

      lcd.print(newKey);
    }
    else {
      secondNum = secondNum + newKey;

      lcd.print(newKey);
    }
 }
  if (newKey != NO_KEY && (newKey == '+' || newKey == '-' || newKey == '*' || newKey == '/')) {
    if (firstNumState == true) {
      operatr = newKey;
      firstNumState = false;
      lcd.setCursor(15, 0);
      lcd.print(operatr);
      lcd.setCursor(5, 1);
    }
  }
 if (newKey != NO_KEY && newKey == '=') {
    if (operatr == '+') {
      result = firstNum.toFloat() + secondNum.toFloat();
    }

    if (operatr == '-') {
      result = firstNum.toFloat() - secondNum.toFloat();
    }

    if (operatr == '*') {
      result = firstNum.toFloat() * secondNum.toFloat();
    }

    if (operatr == '/') {
      result = firstNum.toFloat() / secondNum.toFloat();
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(firstNum);
    lcd.print(operatr);
    lcd.print(secondNum);
    lcd.setCursor(0, 1);
    lcd.print("=");
    lcd.print(result);
    firstNumState = true;
  }

  if (newKey != NO_KEY && newKey == 'C') {
    clr();
  }
}

void scrollDisplay() {
  // 13 positionen nach links bewegen
  // offscreen links bewegen:
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    // eine position nach links bewegen:
    lcd.scrollDisplayLeft();
    // kurze Wartezeit:
    delay(300);
  }
  delay(1000);

  // 29 positionen nach rechts bewegen
  // offscreen rechts bewegen:
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    // eine position nach rechts bewegen:
    lcd.scrollDisplayRight();
    // kurze Wartezeit:
    delay(300);
  }
  delay(2000);
}
void clr() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1st: ");
  lcd.setCursor(12, 0);
  lcd.print("op ");
  lcd.setCursor(0, 1);
  lcd.print("2nd: ");
  lcd.setCursor(5, 0);
  firstNum = "";
  secondNum = "";
  result = 0;
  operatr = ' ';
}
  
    

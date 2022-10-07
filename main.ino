// Allein für diesen Zustand verantwortlich: KSMA


#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);

int num_array[11][8] = {  { 1,1,1,1,1,1,0,0 },  // 0
                          { 0,1,1,0,0,0,0,0 },  // 1
                          { 1,1,0,1,1,0,1,0 },  // 2
                          { 1,1,1,1,0,0,1,0 },  // 3
                          { 0,1,1,0,0,1,1,0 },  // 4
                          { 1,0,1,1,0,1,1,0 },  // 5
                          { 1,0,1,1,1,1,1,0 },  // 6
                          { 1,1,1,0,0,0,0,0 },  // 7
                          { 1,1,1,1,1,1,1,0 },  // 8
                          { 1,1,1,0,0,1,1,0 },  // 9
                          { 0,0,0,0,0,0,0,1 }  };  // Punkt

int first_Num = 0;
int second_Num = 0;
int total_Num = 0;

const int S1_PIN = 5;
const int S2_PIN = 6;
bool S1_wasPressed = false;
bool S2_wasPressed = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Aufgabe 9 KSMA");
  lcd.setCursor(0,1);
  lcd.print("7Segmentanzeige");

  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);

  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);

  pinMode(S1_PIN, INPUT);
  pinMode(S2_PIN, INPUT);
  
  first_Num_Write(first_Num);
  second_Num_Write(second_Num);
}

void first_Num_Write(int number) 
{
  int pin = 38;
  for  (int i = 0; i< 8; i++) {
    digitalWrite(pin, num_array[number][i]);
    pin++;
  }
}

void second_Num_Write(int number) {
  int pin = 46;
  for (int i = 0; i <8; i++){
  digitalWrite(pin, num_array[number][i]);
  pin++;
  }
}



void loop() {

bool S1_state = digitalRead(S1_PIN);
bool S2_state = digitalRead(S2_PIN);

if ((S1_state == false) && (S2_state == false)) {
  return;
}

if (S1_state == true) {
  total_Num++;
}

else if (S2_state == true) {
  total_Num--;
}

 first_Num = (total_Num/10) %10;
 second_Num = total_Num %10;

  first_Num_Write(first_Num);
  second_Num_Write(second_Num);
 delay(200);
}

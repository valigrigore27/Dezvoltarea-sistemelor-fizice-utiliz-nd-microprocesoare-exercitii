int pins[]={13,12,11,10,9,8};
int start = 0;
int distanta = 5;
int brightness = 260;
void setup() {
  for (int i = 8; i <= 13; i++){
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
  unsigned long start = millis();  

}

void loop() {

  /*
  delay(2000);
  if(start < 3){
    digitalWrite(pins[start],LOW);
    digitalWrite(pins[start + distanta], LOW);
    distanta -= 2;
    start += 1;
  }
  */
  unsigned long current = millis();
  if(current - start >= 10){
    analogWrite(pins[4],brightness);
    analogWrite(pins[5],brightness);
    brightness -= 10;
    start = current;
  }

}

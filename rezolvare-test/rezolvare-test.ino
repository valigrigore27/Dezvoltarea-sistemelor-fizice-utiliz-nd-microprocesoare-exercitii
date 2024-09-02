int pins[]={13,12,11,10,9,8};



void setup() {
  for (int i = 8; i <= 11; i++){
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
  unsigned long start = millis();  

}

void loop() {
  // put your main code here, to run repeatedly:

}

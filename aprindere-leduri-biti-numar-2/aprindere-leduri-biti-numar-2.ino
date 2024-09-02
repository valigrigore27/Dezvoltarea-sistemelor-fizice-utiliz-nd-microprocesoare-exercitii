

int pins[]={13, 12, 11, 10, 9, 8};
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
    for(int i=0;i<6;i++)
{
  pinMode(pins[i], OUTPUT);
  digitalWrite(pins[i], LOW);
}
  Serial.begin(9600);
}

void mapBitsToPin(int data)
{
  for(int i=0;i<6;i++)
  digitalWrite(pins[i], (data >> (5-i)) & 1);
}

// the loop function runs over and over again forever
void loop() {
  int nr;
  if (Serial.available() >0)
  {
    nr = Serial.parseInt();
    Serial.println(nr);
    mapBitsToPin(nr);
  }
}

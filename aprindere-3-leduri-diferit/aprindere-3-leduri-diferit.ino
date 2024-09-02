int pins[]={13,12,11,10,9,8};
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
    for(int i=0;i<6;i++)
{
  pinMode(pins[i], OUTPUT);
  digitalWrite(pins[i], LOW);
}
}
//lucreaza pe pinul 13
void f1(){
  if((millis()/1000)%2==0)
  digitalWrite(13, HIGH);
  else
  digitalWrite(13, LOW);
}
//lucreaza pe pinul 8
void f2(){
  if((millis()/100)%2==0)
  digitalWrite(8, HIGH);
  else
  digitalWrite(8, LOW);
}
void f3(){
  if((millis()/1500)%2==0)
  digitalWrite(11, HIGH);
  else
  digitalWrite(11, LOW);
}
// the loop function runs over and over again forever
void loop() {
  f1();
  f2();
  f3();
}

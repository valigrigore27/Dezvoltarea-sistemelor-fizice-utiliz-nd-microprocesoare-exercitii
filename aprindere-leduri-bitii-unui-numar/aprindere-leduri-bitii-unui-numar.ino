
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
    for(int i=8; i<=13 ;i++)
    pinMode(i, 1);

}

// the loop function runs over and over again forever
void loop() {
  int n=32;
  int m=0;
  while  (n>=1){
    if(n%2==1)
    digitalWrite(m+8, HIGH);
    m=m+1;
    n=n/2;
  }      
}

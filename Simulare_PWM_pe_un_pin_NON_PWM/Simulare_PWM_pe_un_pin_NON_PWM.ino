int led=13;
 
void setup() {  
    pinMode(led, OUTPUT);
}
 
int pas=0;
int limita=0;
int dir=5;
 
void loop() {  
  long long t=millis();
  while(millis()-t < 30)
  {
    pas++;
    if (pas<limita) digitalWrite(led,1);
            else digitalWrite(led,0);
    if (pas>255) pas=0;    
  }
  limita += dir;
  if (limita>250 || limita<5) dir*=-1;
}
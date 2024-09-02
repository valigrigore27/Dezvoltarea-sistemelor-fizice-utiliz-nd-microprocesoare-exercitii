int led=13;
 
void setup() {  
    pinMode(led, OUTPUT);
}
 
int pas=0;
int limita=0;
int dir=5;
long long t=0; 
long long contor=0;
 
void loop() {  
  if(millis()-t > 30)
  {
    t=millis();
    limita += dir;
    if(limita==0) Serial.println(contor);
    if (limita>250 || limita<5) dir*=-1;
  }
 contor++;
  pas++;
  if (pas<limita) digitalWrite(led,1);
          else digitalWrite(led,0);
  if (pas>255) pas=0;    
}
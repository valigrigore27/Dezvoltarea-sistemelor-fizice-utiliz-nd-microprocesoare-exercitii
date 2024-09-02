#include <Arduino.h>
#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8


/* Segment byte maps for numbers 0 to 9 */
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};


void setup ()
{
/* Set DIO pins to outputs */
pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO,OUTPUT);
pinMode(DATA_DIO,OUTPUT);
 Serial.begin(9600);
}

//
int count_digit(int number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}
int   flag = 0;
 int sum;

void loop() {
  int number1;
  int number2;


  if(Serial.available()&& flag==0){
      number1 = Serial.parseInt();
      flag = 1;
  }

  if(Serial.available()&& flag==1){
      number2 = Serial.parseInt();
      flag = 2;
  }


  if(flag==2){
    sum = number1 + number2;
    flag = 0;
  }
    int sum1 = sum;
    int patru = sum % 10;
     sum = sum / 10;
    int trei = sum % 10;
     sum = sum / 10;
    int doi = sum % 10;
     sum = sum / 10;
    int unu = sum % 10;

    if(count_digit(sum1)==4){
        WriteNumberToSegment(0, unu);
        WriteNumberToSegment(1, doi);
        WriteNumberToSegment(2, trei);
        WriteNumberToSegment(3, patru);
    }
    else
      {if(count_digit(sum1)==3){ 
        WriteNumberToSegment(1, doi);
        WriteNumberToSegment(2, trei);
        WriteNumberToSegment(3, patru);
}
    else 
      {if(count_digit(sum1)==2){
        WriteNumberToSegment(2, trei);
        WriteNumberToSegment(3, patru);
    }
     else{
        WriteNumberToSegment(3, patru);
     }
      }
      }

}


/* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
void WriteNumberToSegment(byte Segment, byte Value)
{
digitalWrite(LATCH_DIO,LOW);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
digitalWrite(LATCH_DIO,HIGH);
}

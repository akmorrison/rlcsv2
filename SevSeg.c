#include "SevSeg.h"
//#include <avr/io.h>
#include<Stdint.h>
#define BLANK_IDX 11 // Must match with 'digitCodeMap'
#define DASH_IDX 12

//array of segements that must be displayed to display the correct number
static const char *digitCodeMap[] = {
  //     GFEDCBA  Segments      7-segment map:
  "1111110", // 0   "0"          AAA
  "0110000", // 1   "1"         F   B
  "1101101", // 2   "2"         F   B
  "1111001", // 3   "3"          GGG
  "0110011", // 4   "4"         E   C
  "1011011", // 5   "5"         E   C
  "1011111", // 6   "6"          DDD
  "1110000", // 7   "7"
  "1111111", // 8   "8"
  "1111011", // 9   "9"
  "1110111", // A "A"
  "0011111", // b "b"
  "1001110", // C "C"
  "0111101", // d "d"
  "1001111", // E "E"
  "1000111" // F "F"
  //"0000000", // 32  ' '  BLANK
  //"0000001", // 45  '-'  DASH
};
static const long powersOf10[] = {
  1, // 10^0
  16,
};

//functions

void start (int numDigitsIn, char digitPinsIn[MAXNUMDIGITS], char segmentPinsIn[2],  struct SevSeg* sevSegDisplay) {//sets the values of the digitpin and segment pins in the struct, pinmode all of the pins, and turns them all off
  sevSegDisplay->numDigits = numDigitsIn;

  if (sevSegDisplay->numDigits > 2) {//maxDigit = 2 or 1
    sevSegDisplay->numDigits = 2;
  }

  //loops through all pins
  for (int x = 0 ; x < sevSegDisplay->numDigits ; x++) {
    sevSegDisplay->digitPins[x] = digitPinsIn[x];				//sets digits pins to the value inputted;
    pinMode(sevSegDisplay->digitPins[x], OUTPUT);				//set sdigit pins as outputs
    digitalWrite(sevSegDisplay->digitPins[x], HIGH);		//turns digit pins off
  }
  for (int x = 0; x < 7; x++) {
    sevSegDisplay->segmentPins[x] = segmentPinsIn[x];			//sets segment pins to the value inputted;
    pinMode(sevSegDisplay->segmentPins[x], OUTPUT);			//sets digits pins as outputs
    digitalWrite(sevSegDisplay->segmentPins[x], LOW);	//turns segment pins off
  }
}

void refresh(struct SevSeg* sevSegDisplay) {//refreshes display and lights up the segments
  for (int i = 0; i < sevSegDisplay->numDigits; i++) { //goes throught each digit code and lights up appriopriate segment for each one
  if(i == 0){
       //write to digit 1
     digitalWrite(sevSegDisplay->digitPins[0], LOW);//turns first segment pin on
     digitalWrite(sevSegDisplay->digitPins[1], HIGH);//turns off second digit
   }
   else if (i == 1){
       digitalWrite(sevSegDisplay->digitPins[0], HIGH);//turns off first digit
       digitalWrite(sevSegDisplay->digitPins[1], LOW);//turns on second digit
   }
    for (int j = 0; j < 7; j++) {
      if (sevSegDisplay->digitCodes[i][j] == '1') {//brackets?
        digitalWrite(sevSegDisplay->segmentPins[j], HIGH); //goes throught each number of the digitCode (0111101) and if its a '1' then light up the appropriate segment. EG:0111101 would light up f, e, d, c, and a
      } else {
        digitalWrite(sevSegDisplay->segmentPins[j], LOW);
      }
    }
    delay(10);//this is so that 2 numbers can be displayed instantaneously
  }
}

void clearSeg(char digitPinsIn[MAXNUMDIGITS], char segmentPinsIn[MAXNUMDIGITS], struct SevSeg* sevSegDisplay) {//turns pin off
  for (int x = 0 ; x < sevSegDisplay->numDigits ; x++) {
    digitalWrite(sevSegDisplay->digitPins[x], LOW);    //turns segment pins off
  }
  for (char segmentNum = 0 ; segmentNum < 7 ; segmentNum++) {
    digitalWrite(sevSegDisplay->segmentPins[segmentNum], HIGH);//turn sev pins off
  }
}

void setNewNum (uint8_t numToShow, struct SevSeg* sevSegDisplay) {//sets the number the user wants
  findDigits(numToShow, sevSegDisplay); //modifies sevSegDisplay
  setDigitCodes(sevSegDisplay->digits, sevSegDisplay);
}

void findDigits(uint8_t numToShow, struct SevSeg* sevSegDisplay) {
    //stores nibbles of numToShow in sevSegDisplay->digits
    sevSegDisplay->digits[0] = numToShow & 0x0F; //bottom nibble
    sevSegDisplay->digits[1] = (numToShow & 0xF0) >> 4; //top nibble, right shifted down
}

void setDigitCodes(uint8_t digits[], struct SevSeg* sevSegDisplay) { //this function gets the digit code of each number in the 'digit' array
  // Set the digitCode for each digit in the display(digit array)
  for (char digitNum = 0 ; digitNum < sevSegDisplay->numDigits ; digitNum++) {
    for (int x = 0; x < 7; x++) {
      sevSegDisplay -> digitCodes[digitNum][x] = digitCodeMap[digits[digitNum]][x];//eg: 0 would be "1111110"
    }
  }
}


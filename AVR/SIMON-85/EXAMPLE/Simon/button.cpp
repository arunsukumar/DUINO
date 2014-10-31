/*

  Extension to read from the buttons

    Copyright (C) 2014  Stefan Mavrodiev @ OLIMEX LTD

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "button.h"

// define some global  variables

uint32_t lastDebounceTime = 0;
uint8_t lastButtonState = 0;
uint8_t buttonState = 0;


int readButton(void){

  uint16_t sum = 0;
  for(int i = 0;  i < READ_TIMES; i++){
    sum += analogRead(ADC_PORT);
    delay(READ_DELAY);
  }

  sum /= READ_TIMES;

  if(sum > 1000){
    return 0;
  }else{
    if(sum < BUTTON1 + BUTTON_MARGIN && sum > BUTTON1 - BUTTON_MARGIN){
      // button 1 is pressed
      return 1;
    }else if(sum < BUTTON2 + BUTTON_MARGIN && sum > BUTTON2 - BUTTON_MARGIN){
      // button 2 is pressed
      return 2;
    }else if(sum < BUTTON3 + BUTTON_MARGIN && sum > BUTTON3 - BUTTON_MARGIN){
      // button 3 is pressed
      return 3;
    }else if(sum < BUTTON4 + BUTTON_MARGIN && sum > BUTTON4 - BUTTON_MARGIN){
      // button 4 is pressed
      return 4;
    }else{
      return 0;
    }
  }
}

int debounceButton(void){
  while(1){
    int a = readButton();
    if(a != -1){

      if(a != lastButtonState){
        lastDebounceTime = millis();
      }
  
      lastButtonState = a;
  
      if((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
        buttonState = a;
        return a;
      }
    }
  }
}

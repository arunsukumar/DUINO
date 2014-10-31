/*

	Extension to read from the buttons

    Copyright (C) 2014	Stefan Mavrodiev @ OLIMEX LTD

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
#ifndef __BUTTON_H_
#define __BUTTON_H_

	#include <Arduino.h>

	#define DEBOUNCE_DELAY 1
	#define READ_TIMES 5
	#define READ_DELAY 5
	#define ADC_PORT 3

	// define buttons adc threshold
    #define BUTTON1 373  // 260 @ 0.84
    #define BUTTON2 514  // 350 @ 1.13
    #define BUTTON3 601  // 424 @ 1.37
    #define BUTTON4 662  // 483 @ 1.56
    #define BUTTON_MARGIN 30

	int readButton(void);
	int debounceButton(void);
#endif

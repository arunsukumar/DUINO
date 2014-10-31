SIMON-85

The board is an implementaion of the popular simon game which tests and trains your short-term memory. There are four LEDs, four buttons and a buzzer. The LEDs blink in random pattern which you should repeat with the buttons. Each successful guess makes the buzzer produce a sound. Each successful guess increments the amount of blinks, thus the difficulty.

The only hardware requirement for normal use of the board is:

- USB type A to USB mini cable – to connect to a personal computer; used for powering the board and uploading new programs via Digisparks' Arduino

The board can be programmed with Digispark's Arduino distributions. Link to the download page of Digispark's Arduino distributions, suitable for Windows, Linux and MacOS: http://digistump.com/wiki/digispark/tutorials/connecting

The initial bootloader firmware can be uploaded with any combination of third party programming tool and programming software that are compatible with ATTiny85. 

The core design of the board is similar to the design of the previously released OLinuXino-85 and FOSDEM-85 boards. This might be helpful in your attempt to implementing additional examples.

THE DESIGN OF SIMON-85 IS BASED HEAVILY ON THE LITTLE WIRE'S DESIGN BY IHSAN KEHRIBAR AND USES DIGISTUMP'S DIGISPARK SOFTWARE. SIMON-85 WOULD NOT HAVE BEEN POSSIBLE WITHOUT THE EXISTENCE OF BOTH LITTLE WIRE AND DIGISPARK PROJECTS.

The board is completely open software and open hardware.
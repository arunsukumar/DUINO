Library with header files and three examples suitable for:

ARDUINO COMPATIBLE BOARD AND MOD-LED8x8RGB

In order to get the hardware working you have to:

Connect the MOD-LCD8x8RGB to your board according to the names of the signals. A typical connection might be seen in this blog post:

Note: the MOD-LED8x8RGB works at 5V of voltage. 3.3V will not be sufficient for powering!

In order to get the software working you have to:

1. Download the files (one by one or the whole folder containing this readme.md) and keep the directory structure as in this repository.
1. Close Arduino IDE if it is running.
2. Copy the whole folder that you downloaded (both the headers and the examples folder in it) to the libraries folder of your Arduino IDE (ex. "..\arduino-x.x.x\libraries").
3. Start Arduino IDE.
4. Select the board and serial port (check this one in your Windows Device Manager --> Ports (COM & LPT) section).
5. Go to File -> Example -> name of the folder containing the headers and the examples -> select one of the examples.
6. Compile and upload
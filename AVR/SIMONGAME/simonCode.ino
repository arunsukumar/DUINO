//Copyright(C) 2014, Olimex Ltd, www.olimex.com
//this code is released under GPL licensee.

#define BUT1   0	//button1 connected to GND and D0 with 10K pullup to +5V
#define BUT2   1	//button2 connected to GND and D1 with 10K pullup to +5V
#define BUT3   2	//button3 connected to GND and D2 with 10K pullup to +5V
#define BUT4   3	//button4 connected to GND and D3 with 10K pullup to +5V
#define LAMP1  4	//LED1 connected to GND and D4 via 560 ohm resistor
#define LAMP2  5	//LED2 connected to GND and D5 via 560 ohm resistor
#define LAMP3  6	//LED3 connected to GND and D6 via 560 ohm resistor
#define LAMP4  7	//LED4 connected to GND and D7 via 560 ohm resistor
#define BEEPER 8	//piezzo buzzer connected to D8 and +5V

#define TOTTURNS   64   //total number of game steps
#define TURNPAUSE 100   //pause between steps
#define GAMESPEED 500   //delay of blinking during gameplay
#define BLRATE 100      //blink rate of endgame lights
#define RESPTIME 500    //wait time per button to respond

int Game[TOTTURNS];	//total number or steps in the game
int Count;
boolean LoseFlag;	
boolean WinFlag;	
boolean TimeOut;	
boolean GameStart;	

void reset()  //reset game
{
  Count = 0;
  LoseFlag = false;
  WinFlag = false;
  TimeOut = true;
  for (int i=0;i<TOTTURNS;i++)
    Game[i] = random(1,5);
}

void setup() 
{
  Serial.begin(9600);
  randomSeed(analogRead(0));	//we will use random generator
  for (int i=0;i<5;i++)		//buttons are inputs
    pinMode(i, INPUT);
  for (int i=4;i<9;i++)		//leds and buzzer output
    pinMode(i, OUTPUT);
  reset();
}

int butread() //read which button is pressed
{
  int Pressed;
  if (digitalRead(BUT1) == LOW) Pressed = 1;
  else if (digitalRead(BUT2) == LOW) Pressed = 2;
  else if (digitalRead(BUT3) == LOW) Pressed = 3;
  else if (digitalRead(BUT4) == LOW) Pressed = 4;
  else Pressed = 0;
  return Pressed;
}

void win() //event in case of win
{
  for (int i=0;i<5;i++)
    litall(BLRATE);
  delay(BLRATE*2);
  for (int i=0;i<4;i++)
  {
    for (int j=0;j<4;j++)
      lit(j+1,BLRATE);
    delay(BLRATE);
    for (int j=4;j>0;j--)
      lit(j,BLRATE);
    delay(BLRATE);
  }
  delay(BLRATE*2);
  reset();
}

void lose() //event in case of loss
{
  for (int i=0;i<5;i++)
    litall(BLRATE);
  delay(BLRATE*2);
  for (int i=0;i<4;i++)
  {
    lit(1,BLRATE);
    lit(4,BLRATE);
    lit(1,BLRATE);
    lit(4,BLRATE);
  }  
  delay(BLRATE*2);
  for (int i=0;i<4;i++)
  {
    lit(3,BLRATE);
    lit(2,BLRATE);
    lit(3,BLRATE);
    lit(2,BLRATE);
  }
  delay(BLRATE*2);
  reset();
}

void lit(int Choice, int Duration) //light up a lamp
{
  int LampCh;
  if (Choice == 1) LampCh = LAMP1;
  else if (Choice == 2) LampCh = LAMP2;
  else if (Choice == 3) LampCh = LAMP3;
  else if (Choice == 4) LampCh = LAMP4;
  else LampCh = 99;
  
  digitalWrite(LampCh, HIGH);
  tone(BEEPER, Choice*200 + 500, 100);
  delay(Duration);
  digitalWrite(LampCh, LOW);
  delay(Duration);
}

void litall(int Duration) //light up all lamps
{
  digitalWrite(LAMP1, HIGH);
  digitalWrite(LAMP2, HIGH);
  digitalWrite(LAMP3, HIGH);
  digitalWrite(LAMP4, HIGH);  
  delay(Duration);
  digitalWrite(LAMP1, LOW);
  digitalWrite(LAMP2, LOW);
  digitalWrite(LAMP3, LOW);
  digitalWrite(LAMP4, LOW);
  delay(Duration);  
}

void play(int Turn) //display sequence to be repeated by user
{
  for (int i=0;i<Turn;i++)
  {
    lit(Game[i], GAMESPEED);
    delay(10);
  }
}

void human(int Turn) //receive user's attempt to repeat sequence
{
  for (int i=0;i<Turn;i++)
  {
    for (int j=0;j<RESPTIME;j++)
    {
      if (butread() == Game[i])
      {
        lit(Game[i], GAMESPEED);
        TimeOut = false;
        break;
      }
      else if (butread() != 0 && butread() !=Game[i]) 
      {
        lit(Game[i], GAMESPEED);
        TimeOut = false;
        LoseFlag = true;
      }
      else delay (10);
      if (LoseFlag == true) break;
    }
    if (TimeOut)
    {
      LoseFlag = true;
    }
    TimeOut = true;
    if (LoseFlag) break;
//    else while (butread() == Game[i]);
    if (i == TOTTURNS-1) WinFlag = true;
  } 
}

void loop() 
{
  if (digitalRead(BUT1) == LOW && digitalRead(BUT2) == LOW && GameStart == false) //start a new game
  {
    GameStart = true;
    for (int i=0;i<3;i++)
      litall(BLRATE);
    delay(2000);
  }
  if (LoseFlag)
  {
     GameStart = false;
     lose();
  }
  if (WinFlag)
  {
     GameStart = false;
     win();
  }
  
  if (GameStart)
  {
    Count++;
  
    play(Count);
    delay(200);
    human(Count);
    delay(200);
  }
}

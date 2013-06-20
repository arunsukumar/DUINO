const int buttonPin1 = 0;
const int buttonPin2 = 1;

int button1State = 0;
int button2State = 0;

int LightupDelay = 500;
int DefaultDelay = 500;
int SpeedChange = 50;
boolean directionMoving = 0;
boolean GameEnd = 0;

void setup() {
  for (int i=0; i<10; i++) {
  pinMode(i+2, OUTPUT); 
  }
  pinMode(buttonPin1, INPUT);   
  pinMode(buttonPin2, INPUT);

  digitalWrite(2, HIGH);
  for (int i=0; i<9; i++) {
  digitalWrite(i+3, LOW); 
  } 
}

void loop(){

while (!directionMoving && !GameEnd){
  for (int i=1; i<11; i++) {

      button1State = HIGH;
      button2State = HIGH;

    if (i == 10) {
      for (int j=0; j<5; j++) {
        digitalWrite(j+2, HIGH);
      }
      for (int j=5; j<10; j++) {
        digitalWrite(j+2, LOW);
      }
      GameEnd = 1;
      break;
    }
    
    digitalWrite(i+2, HIGH);
    digitalWrite(i+1, LOW);
    
    for(int cn=0; cn<LightupDelay; cn+=100) {
      if (digitalRead(buttonPin1) == LOW) 
          button1State = LOW;          
      if (digitalRead(buttonPin2) == LOW) 
          button2State = LOW;
      delay(100);
    }
  
    if (button2State == LOW && i != 9) {
      for (int j=0; j<5; j++) {
        digitalWrite(j+2, HIGH);
      }
      for (int j=5; j<10; j++) {
        digitalWrite(j+2, LOW);
      }
      GameEnd = 1;
      break;
    }
    
    if (button1State == LOW && i != 0) {
      for (int j=0; j<5; j++) {
        digitalWrite(j+2, LOW);
      }
      for (int j=5; j<10; j++) {
        digitalWrite(j+2, HIGH);
      }
      GameEnd = 1;
      break;
    }
    
    if (button2State == LOW && i == 9){
      LightupDelay -= SpeedChange;
      directionMoving = 1;
      break;
    }
  }
}


while (directionMoving && !GameEnd){
  for (int i=11; i>1; i--) {

      button1State = HIGH;
      button2State = HIGH;

    if (i == 2) {
      for (int j=0; j<5; j++) {
        digitalWrite(j+2, LOW);
      }
      for (int j=5; j<10; j++) {
        digitalWrite(j+2, HIGH);
      }
      GameEnd = 1;
      break;
    }
    
    if (i!=2) digitalWrite(i-1, HIGH);
    digitalWrite(i, LOW);
    
    for(int cn=0; cn<LightupDelay; cn+=100) {
      if (digitalRead(buttonPin1) == LOW) 
          button1State = LOW;          
      if (digitalRead(buttonPin2) == LOW) 
          button2State = LOW;
      delay(100);
    }
  
    if (button1State == LOW && i != 3) {
      for (int j=0; j<5; j++) {
        digitalWrite(j+2, LOW);
      }
      for (int j=5; j<10; j++) {
        digitalWrite(j+2, HIGH);
      }
      GameEnd = 1;
      break;
    }
    
    if (button2State == LOW && i != 11) {
      for (int j=0; j<5; j++) {
        digitalWrite(j+2, HIGH);
      }
      for (int j=5; j<10; j++) {
        digitalWrite(j+2, LOW);
      }
      GameEnd = 1;
      break;
    }
    
    if (button1State == LOW && i == 3){
      LightupDelay -= SpeedChange;
      directionMoving = 0;
      break;
    }
  }
}

 if (digitalRead(buttonPin1) == LOW && digitalRead(buttonPin2) == LOW && GameEnd) {
  LightupDelay = DefaultDelay;
  directionMoving = 0;
  digitalWrite(2, HIGH);
  for (int i=0; i<9; i++) {
  digitalWrite(i+3, LOW);
  }
  GameEnd = 0;
  delay(1000);
 }
}


#define aPin 7  
#define bPin 8  
#define cPin 2  
#define dPin 3  
#define ePin 4  
#define fPin 6  
#define gPin 5  


#define PIN_BUTTON A0
#define PIN_BUZZER 10

const byte PIN_CHAOS = A5; 
const unsigned int BEEP_FREQUENCY = 3000;
const int DEBOUNCE_DELAY = 50;  


#define COMMON_CATHODE true  

int On, Off; 
bool rolling = false; 

void setup() {
  randomSeed(analogRead(PIN_CHAOS));

  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT); 
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  
  pinMode(PIN_BUTTON, INPUT_PULLUP); 
  pinMode(PIN_BUZZER, OUTPUT);       

  
  if (COMMON_CATHODE) {
    On = 1; Off = 0;
  } else {
    On = 0; Off = 1;
  }

  testSegments(); 
}

void loop() {
  static bool buttonPressed = false;  

  if (digitalRead(PIN_BUTTON) == LOW) { 
    delay(DEBOUNCE_DELAY);  

    if (!buttonPressed) {   
      buttonPressed = true; 
      rolling = true;        
      rollTheDice();
    }
  } else {
    buttonPressed = false;  
  }
}


void rollTheDice() {
  if (rolling) {
    
    for (int i = 0; i < 10; i++) {
      showNumber(random(1, 7));
      tone(PIN_BUZZER, BEEP_FREQUENCY, 50);
      delay(100);
    }

    
    int finalNumber = random(1, 7);
    showNumber(finalNumber);
    tone(PIN_BUZZER, BEEP_FREQUENCY, 400);
    
    rolling = false; 
  }
}


void showNumber(int x) {
   switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
  }
}


void testSegments() {
  digitalWrite(aPin, On);
  digitalWrite(bPin, On);
  digitalWrite(cPin, On);
  digitalWrite(dPin, On);
  digitalWrite(ePin, On);
  digitalWrite(fPin, On);
  digitalWrite(gPin, On);
  delay(1000);
  digitalWrite(aPin, Off);
  digitalWrite(bPin, Off);
  digitalWrite(cPin, Off);
  digitalWrite(dPin, Off);
  digitalWrite(ePin, Off);
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
}


void one() { digitalWrite(aPin, Off); digitalWrite(bPin, On); digitalWrite(cPin, On); digitalWrite(dPin, Off);
            digitalWrite(ePin, Off); digitalWrite(fPin, Off); digitalWrite(gPin, Off); }

void two() { digitalWrite(aPin, On); digitalWrite(bPin, On); digitalWrite(cPin, Off); digitalWrite(dPin, On);
            digitalWrite(ePin, On); digitalWrite(fPin, Off); digitalWrite(gPin, On); }

void three() { digitalWrite(aPin, On); digitalWrite(bPin, On); digitalWrite(cPin, On); digitalWrite(dPin, On);
              digitalWrite(ePin, Off); digitalWrite(fPin, Off); digitalWrite(gPin, On); }

void four() { digitalWrite(aPin, Off); digitalWrite(bPin, On); digitalWrite(cPin, On); digitalWrite(dPin, Off);
             digitalWrite(ePin, Off); digitalWrite(fPin, On); digitalWrite(gPin, On); }

void five() { digitalWrite(aPin, On); digitalWrite(bPin, Off); digitalWrite(cPin, On); digitalWrite(dPin, On);
             digitalWrite(ePin, Off); digitalWrite(fPin, On); digitalWrite(gPin, On); }

void six() { digitalWrite(aPin, On); digitalWrite(bPin, Off); digitalWrite(cPin, On); digitalWrite(dPin, On);
            digitalWrite(ePin, On); digitalWrite(fPin, On); digitalWrite(gPin, On); }

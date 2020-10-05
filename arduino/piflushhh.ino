/*
 * POWERMYPI UNO
 * thinkedinthesea
 * 
 * rev01
 * 010118
 * production release
 * 
 * rev02
 * 100920
 * major update on SR
*/
//attiny85 pins
const int POWER_OUT = 0;
const int POWER_LED = 1;
const int WATCHDOG = 2;
const int POWER_BTN = 3;
const int SR = 4;
//define max watchdog wait in startup state
const int WAITWD = 50;
//define max watchdog wait in poweroff state
const int WAITWD2 = 20;
//variables
int reboot;
int restart;
int tempo;
//
void setup() {
  //declare the pins
  pinMode (POWER_OUT, OUTPUT);
  pinMode (POWER_LED, OUTPUT);
  pinMode (SR, OUTPUT);
  pinMode (WATCHDOG, INPUT);
  pinMode (POWER_BTN, INPUT);
  //variables
  reboot = 0;
  restart = 0;
  tempo = 0;
  //pins
  digitalWrite(POWER_LED, LOW);
  digitalWrite(POWER_OUT, LOW);
}
//
void loop() {
  //check for power button
  while (digitalRead(POWER_BTN) == HIGH) {
    // check for previous reboot state
    if (reboot == 1) {
      // reset the reboot variable
      reboot = 0;
      break;
    }
    //bla bla bla
  }
  //fire up the board
  digitalWrite(POWER_OUT, HIGH);
  //check for WATCHDOG signal HIGH
  checkWatchdog();
  if (restart == 0) {
    //if we are here, we correctly receive the watchdog signal HIGH
    //make POWER_LED HIGH without blink
    //check for watchdog signal and for power button
    digitalWrite(POWER_LED, HIGH);
    checkWatchdogAndPower();
  }
  if (restart == 0) {
    //power button pressed
    //explain button:
    //REBOOT: SR HIGH 50ms
    //POWEROFF: SR HIGH 200ms
    tempo = 0;
    while (digitalRead(POWER_BTN) == LOW) {
      delay(10);
      tempo++;
    }
    if (tempo > 100) {
      //poweroff
      //SR high 200ms
      digitalWrite(SR, HIGH);
      delay(200);
      digitalWrite(SR, LOW);
      //check for WD low
      while (digitalRead(WATCHDOG) == HIGH) {
        digitalWrite(POWER_LED, HIGH);
        delay(100);
        digitalWrite(POWER_LED, LOW);
        delay(100);
      }
      //kill the board
      delay(10000);
      digitalWrite(POWER_OUT, LOW);
      digitalWrite(POWER_LED, LOW);
      //reboot
      reboot = 1;
    } else if (tempo < 101) {
      //SR high 50ms
      digitalWrite(SR, HIGH);
      delay(50);
      digitalWrite(SR, LOW);
      //check for WD low
      while (digitalRead(WATCHDOG) == HIGH) {
        digitalWrite(POWER_LED, HIGH);
        delay(1000);
        digitalWrite(POWER_LED, LOW);
        delay(1000);
      }
      
    }
  }
}
////////////////////////////////////////////////
////////////////////////////////////////////////
void checkWatchdog() {
  tempo = 1;
  while (digitalRead(WATCHDOG) == LOW) {
    digitalWrite(POWER_LED, HIGH);
    delay(200);
    digitalWrite(POWER_LED, LOW);
    delay(200);
    // increase tempo
    tempo++;
    restart = 0;
    if (tempo > WAITWD) {
      // no WATCHDOG reived, kill the power
      digitalWrite(POWER_OUT, LOW);
      digitalWrite(POWER_LED, LOW);
      restart = 1;
      break;
      // game over
      //while (1);
    }
  }
  
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
void checkWatchdogAndPower() {
  while (digitalRead(POWER_BTN) == HIGH && restart == 0) {
    tempo = 0;
    if (digitalRead(WATCHDOG) == LOW) {
      while (digitalRead(WATCHDOG) == LOW) {
        digitalWrite(POWER_LED, HIGH);
        delay(500);
        digitalWrite(POWER_LED, LOW);
        delay(500);
        // increase tempo
        tempo++;
        if (tempo > WAITWD2) {
          // no WATCHDOG reived, kill the power
          digitalWrite(POWER_OUT, LOW);
          digitalWrite(POWER_LED, LOW);
          // game over
          // while (1);
          restart = 1;
          break;
        }
      }
     //if (digitalRead(WATCHDOG) == HIGH){
      //digitalWrite(POWER_LED, HIGH);
     }
     if (restart == 0){
      digitalWrite(POWER_LED, HIGH);
     }
    }
  }

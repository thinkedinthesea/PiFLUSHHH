/*
   PiFLUSHHH
   thinkedinthesea


   rev01
   131020
   production release
*/
//attiny85 pins
const int MOSFET = 4;
const int WD = 0;
const int SWITCH = 2;
const int ATTINY = 1;
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
  pinMode (MOSFET, OUTPUT);
  pinMode (ATTINY, OUTPUT);
  pinMode (WD, INPUT);
  pinMode (SWITCH, INPUT);
  //variables
  reboot = 0;
  restart = 0;
  tempo = 0;
  //pins
  digitalWrite(MOSFET, LOW);
  digitalWrite(ATTINY, LOW);
}
//
void loop() {
  //check for power button
  while (digitalRead(SWITCH) == LOW) {
    // check for previous reboot state
    if (reboot == 1) {
      // reset the reboot variable
      reboot = 0;
      break;
    }
    //bla bla bla
  }
  //fire up the board
  digitalWrite(MOSFET, HIGH);
  //check for WATCHDOG signal HIGH
  checkWatchdog();
  if (restart == 0) {
    //if we are here, we correctly receive the watchdog signal HIGH
    //make POWER_LED HIGH without blink
    //check for watchdog signal and for power button
    checkWatchdogAndPower();
  }
  if (restart == 0) {
    //power button pressed
    //explain button:
    //REBOOT: SR HIGH 50ms
    //POWEROFF: SR HIGH 200ms
    tempo = 0;
    while (digitalRead(SWITCH) == HIGH) {
      delay(10);
      tempo++;
    }
    if (tempo > 100) {
      //poweroff
      //SR high 200ms
      digitalWrite(ATTINY, HIGH);
      delay(200);
      digitalWrite(ATTINY, LOW);
      //check for WD low
      while (digitalRead(WD) == HIGH) {

      }
      //kill the board
      delay(10000);
      digitalWrite(MOSFET, LOW);
      //reboot
      reboot = 1;
    } else if (tempo < 101) {
      //SR high 50ms
      digitalWrite(ATTINY, HIGH);
      delay(50);
      digitalWrite(ATTINY, LOW);
      //check for WD low
      while (digitalRead(WD) == HIGH) {

      }

    }
  }
}
////////////////////////////////////////////////
////////////////////////////////////////////////
void checkWatchdog() {
  tempo = 1;
  while (digitalRead(WD) == LOW) {
    tempo++;
    restart = 0;
    if (tempo > WAITWD) {
      // no WATCHDOG reived, kill the power
      digitalWrite(MOSFET, LOW);
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
  while (digitalRead(SWITCH) == LOW && restart == 0) {
    tempo = 0;
    if (digitalRead(WD) == LOW) {
      while (digitalRead(WD) == LOW) {
        tempo++;
        if (tempo > WAITWD2) {
          // no WATCHDOG reived, kill the power
          digitalWrite(MOSFET, LOW);
          // game over
          // while (1);
          restart = 1;
          break;
        }
      }
      //if (digitalRead(WATCHDOG) == HIGH){
      //digitalWrite(POWER_LED, HIGH);
    }
    if (restart == 0) {
      //digitalWrite(POWER_LED, HIGH);
    }
  }
}

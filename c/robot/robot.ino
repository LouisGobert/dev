//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/
#include <Stepper.h>

const int stepPerRevol = 2048;
const int rolePerMin = 17;
const int stepD = 10;

// MOTEUR 1
#define ENABLE_M1 5
#define DIRA_M1 4
#define DIRB_M1 2

// MOTEUR 2
#define ENABLE_M2 11
#define DIRA_M2 10
#define DIRB_M2 8

// JOYSTICK
#define SW_JOY A2
#define X_pin A1
#define Y_pin A0 

// TRANSISTOR
#define TR_1 13 
#define TR_2 7

// STEPPER MOTOR
Stepper myStepper(stepPerRevol, 12, 6, 3, 9);


int V_M1, V_M2;
bool SW_STATE = false;
int i;
int rotateEffect;
bool rotateModeActived;
bool g, d;

void setup() {
  
  // MOTEUR 1
  pinMode(ENABLE_M1,OUTPUT);
  pinMode(DIRA_M1,OUTPUT);
  pinMode(DIRB_M1,OUTPUT);

   // MOTEUR 2
  pinMode(ENABLE_M2,OUTPUT);
  pinMode(DIRA_M2,OUTPUT);
  pinMode(DIRB_M2,OUTPUT);

  // Joystick
  pinMode(SW_JOY, INPUT);
  digitalWrite(SW_JOY, HIGH);
  Serial.begin(9600);


  pinMode(TR_1, OUTPUT);
  pinMode(TR_2, OUTPUT);
  digitalWrite(TR_1, LOW);
  digitalWrite(TR_2, LOW);

  // Moteur pas a pas
  myStepper.setSpeed(rolePerMin);
}

void loop() {

    lectureJoy();


    delay(100);
}


void lectureJoy()
 {
    V_M1 = analogRead(X_pin);
    //Serial.println("Watch..");

    // MOTEUR 1
    if (V_M1 > 530) {

      analogWrite(ENABLE_M1, ((V_M1 - 510) / 2)-1);
      digitalWrite(DIRA_M1, HIGH);
      digitalWrite(DIRB_M1, LOW);

    } else if (V_M1 < 460) {

      analogWrite(ENABLE_M1, (510 - V_M1) / 2);
      digitalWrite(DIRA_M1, LOW);
      digitalWrite(DIRB_M1, HIGH);

    } else {
      digitalWrite(ENABLE_M1, LOW);
    }

     // MOTEUR 2
    V_M2 = analogRead(Y_pin);
   
    if (V_M2 > 530) {

      analogWrite(ENABLE_M2, ((V_M2 - 510) / 2)-1);
      digitalWrite(DIRA_M2, HIGH);
      digitalWrite(DIRB_M2, LOW);
    } else if (V_M2 < 470) {


      analogWrite(ENABLE_M2, (510 - V_M2) / 2);
      digitalWrite(DIRA_M2, LOW);
      digitalWrite(DIRB_M2, HIGH);
    } else {
      digitalWrite(ENABLE_M2, LOW);
    }


    // Click on joystick
    if (analogRead(SW_JOY) < 500) {

      i = 0;
      rotateModeActived = false;
       while (analogRead(SW_JOY) < 500) {
          if (i >=10) {
            rotateModeActived = true;
              Serial.println("Mode rotation...");
              rotateMode();
              digitalWrite(12, LOW);
              digitalWrite(6, LOW);
              digitalWrite(3, LOW);
              digitalWrite(9, LOW);
              while (analogRead(SW_JOY) < 500) {
                Serial.println("block");
                delay(100);
              }

             
              
             
          }
           delay(100);
           i++;
      }

      if (rotateModeActived == false) {
         if (SW_STATE == true) {
        Serial.println("changement");
        digitalWrite(TR_2, LOW);
        delay(50);
        digitalWrite(TR_1, HIGH);
        SW_STATE = false;

        }
     else {
      SW_STATE = true;
        digitalWrite(TR_1, LOW);
        delay(50);
        digitalWrite(TR_2, HIGH);
      }
      }
     }
 }


 void rotateMode() {
  g = false;
  d = false;
  digitalWrite(9, HIGH);
  while (analogRead(SW_JOY) < 500);
  digitalWrite(9, LOW);
  
  while(true) {

  //Serial.println("led ");
    
    V_M1 = analogRead(X_pin);
    if (V_M1 > 600 ) {
      if (!g) {
        g = true;
        myStepper.step(stepPerRevol / stepD);
        Serial.print("Rotation a droite, nouvelle valeur : ");
      }
    
    } else if (V_M1 < 400) {
      if (!d) {
        d = true;
        myStepper.step(-(stepPerRevol / stepD));
        Serial.print("Rotation a gauche");
      }
    } else {
        //resetStepper();
        if (d) {
           myStepper.step(stepPerRevol / stepD);
          d = false;
        }
        else if (g) {
            g = false;
            myStepper.step(-stepPerRevol / stepD);
        }
    }


    i = 0;
    
    while (analogRead(SW_JOY)< 500) {
      if (i >= 10) {
        //resetStepper();
        Serial.println("Fin de rotation.");
        return;
      }
      i++;
      delay(100);
    }
    delay(10);//10
  }
 }

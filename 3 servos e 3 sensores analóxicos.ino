/*

Realiza a montaxe para controlar tres servos empregando tres potenciómetros independentes.
O programa debe ser reactivo a cada potenciómetro, de maneira que se poida accionar 8 veces 
por segundo como moito. 


Autor: Nicolás Sanlés Álvarz
Fecha: Maio 2025

*/

#include <Servo.h>

Servo servoA, servoB, servoC;

int potA = A0, potB = A1, potC = A2;
int valA, valB, valC;
int posA = 90, posB = 90, posC = 90;



void setup() {
  servoA.attach(9);
  servoB.attach(10);
  servoC.attach(11);
}

void loop() {
  valA = analogRead(potA);
  valB = analogRead(potB);
  valC = analogRead(potC);

  // Servo (a): precisión de 12º
  
  valA = map(valA, 0, 1023, 0, 15) * 12;
  if (valA != posA) {
    servoA.write(valA);
    posA = valA;
  }

  // Servo (b): precisión de 5º
  
  valB = map(valB, 0, 1023, 0, 36) * 5;
  if (valB != posB) {
    servoB.write(valB);
    posB = valB;
  }

  // Servo (c): precisión de 0.5º
  
  valC = map(valC, 0, 1023, 0, 360) * 0.5;
  if (valC != posC) {
    servoC.write(valC);
    posC = valC;
  }

  delay(125); 
}

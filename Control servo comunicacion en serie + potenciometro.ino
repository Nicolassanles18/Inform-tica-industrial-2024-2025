/* Posicionamento dun servo analoxicas+comunicacion en serie
Nicolás Sanlés Álvarez 2025
*/






#define POTENCIOMETRO A0
#include <Servo.h>



Servo servoMotor;


int val;              // valor do potenciómetro
int angulo = 0;       // ángulo pra o servo
bool modoSerial = false; // false = potenciómetro, true = monitor serie
unsigned long ultimoTiempoSerie = 0; // para volver ao modo potenciómetro

void setup() {
  servoMotor.attach(9); // establecer pin del servo
  Serial.begin(9600);
  Serial.println("Modo inicial: Potenciómetro.");
  Serial.println("Escribe un ángulo (0-180) para control desde el Monitor Serie.");
}



void loop() {
  // Ler se hai datos
  if (Serial.available() > 0) {
    int entrada = Serial.parseInt();
    if (entrada >= 0 && entrada <= 180) {
      angulo = entrada;
      modoSerial = true;
      ultimoTiempoSerie = millis();
      Serial.print("Modo serie: ángulo = ");
      Serial.println(angulo);
    } else {
      Serial.println("Ángulo inválido. Debe estar entre 0 y 180.");
    }
  }

  // 
  if (!modoSerial) {
    val = analogRead(POTENCIOMETRO);
    angulo = map(val, 0, 1023, 0, 180);
  }

 
  servoMotor.write(angulo);
  delay(15);

  // Salir do modo serie se pasaron máis de 5 segundos sen entrada
  if (modoSerial && (millis() - ultimoTiempoSerie > 5000)) {
    modoSerial = false;
    Serial.println("Sin entrada en serie. Volviendo a control por potenciómetro.");
  }
}

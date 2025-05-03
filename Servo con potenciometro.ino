#include <Servo.h>

Servo meuServo; // Crear un obxecto Servo

const int pinServo = 3;     // Pin PWM conectado ao control do servo
const int pinPot = A5;      // Pin analóxico conectado ao potenciómetro

unsigned long ultimoTempo = 0; // Gardar o último tempo de actualización
const int intervalo = 125;     // Intervalo de actualización en milisegundos (8 veces/segundo)

void setup() {
  meuServo.attach(pinServo); // Asignar o pin ao obxecto servo
}

void loop() {
  unsigned long tempoActual = millis(); // Ler o tempo actual

  // Só actualizar se pasaron 125 ms
  if (tempoActual - ultimoTempo >= intervalo) {
    ultimoTempo = tempoActual;

    int lecturaPot = analogRead(pinPot); // Ler o valor do potenciómetro (0-1023)

    // Mapear a lectura a un ángulo de 0 a 180 en pasos de 10 grados
    int angulo = map(lecturaPot, 0, 1023, 0, 180);

    // Redondear o ángulo ao múltiplo de 10 máis próximo
    angulo = (angulo / 10) * 10;

    // Limitar o ángulo para que non pase de 180
    if (angulo > 180) {
      angulo = 180;
    }

    meuServo.write(angulo); // Mover o servo ao ángulo calculado
  }
}

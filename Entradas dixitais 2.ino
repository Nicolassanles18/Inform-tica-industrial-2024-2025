/* Práctica 14 Nicolás Sanlés Álvarez
*/




#define L_AMARILLO 13
#define L_VERDE    12
#define RELE       11
#define PULS       10


bool pulsador = 0;

void setup(){
  
  pinMode(L_AMARILLO, OUTPUT);
  
  pinMode(L_VERDE, OUTPUT);
  
  pinMode(RELE, OUTPUT);
  
  pinMode(PULS, INPUT);
}

void loop() {
  
     pulsador = digitalRead(PULS);
     if(pulsador == 0) {
    digitalWrite(L_AMARILLO, HIGH); // encende pin 13
    delay(4000); // wait for 3000 millisecond(s)
    digitalWrite(L_VERDE, LOW); // encende pin 12
    delay(4000); // wait for 3000 millisecond(s)
    digitalWrite(RELE, LOW); // encende pin 11
    delay(4000); // wait for 3000 millisecond(s)
    digitalWrite(L_AMARILLO, LOW); // encende pin 13
    delay(2000); // wait for 3000 millisecond(s)
    digitalWrite(L_VERDE, HIGH); // ENCENDE PIN 12
    delay(2000); // wait for 3000 millisecond(s)
    digitalWrite(RELE, HIGH); // encende pin 11
    delay(2000); // wait for 3000 millisecond(s)
 
  
  }
  
  else(pulsador == 1);{
    digitalWrite(L_AMARILLO, LOW);
    digitalWrite(L_VERDE, LOW);
    digitalWrite(RELE, LOW);
  }
}

    

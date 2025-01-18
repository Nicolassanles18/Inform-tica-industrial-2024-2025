/* Programa para simular o comportamento dunha porta lóxica doutra  práctica
O script activa unha saída luminosa en funcion das entradas dos interruptores
seguindo a dunción f= not a* b* not c + not a*b*c + a * not b *c + a*b*c
*/




#define A 10
#define B 9
#define C 8
#define LAMP 11


bool a = 0;
bool b = 0;
bool c = 0;
bool condition;

void setup(){
  
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(LAMP, OUTPUT);
}

void loop() {
 
 a = digitalRead(A);
    b = digitalRead(B);
    c = digitalRead(C);
    
    bool condicion1 = !a && b && !c;
    bool condicion2 = !a && b && c;
    bool condicion3 = a && !b && c;
    bool condicion4 = a && b && c;
     bool condicion = condicion1 || condicion2 || condicion3|| condicion4;
    if(condicion1) {
      digitalWrite(LAMP, HIGH);
    }
else if(condicion2) {
  digitalWrite(LAMP, HIGH);
}
    else if(condicion3) {
      digitalWrite(LAMP, HIGH);
    }
  else if(condicion4){
    digitalWrite(LAMP, HIGH);
  }
  else {
      digitalWrite(LAMP, LOW);
    }
   }

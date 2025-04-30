/* Ponte H con relés

Nicolás Sanlés Álvarez, 2025 */





#define PULS 9
#define ARRIBA_1 13
#define ABAJO_1 12
#define ARRIBA_2 11
#define ABAJO_2 10


bool acciona =0; // variable para o accionamento
int estado =1 ;// variable de estado funcionamiento




void setup() {
  pinMode(PULS, INPUT);
  pinMode(ARRIBA_1, OUTPUT);
  pinMode(ABAJO_1, OUTPUT);
  pinMode(ARRIBA_2, OUTPUT);
  pinMode(ABAJO_2, OUTPUT);
 
 }

void loop() {
  acciona = digitalRead(PULS);
  delay(20);
  if(acciona){
   
    estado=(estado+1)%4; //cambia o estado ao accionar o pulsador
   
       while(digitalRead(PULS)){
      delay(10);
         
       }
  }
      
  if (estado==0){// sube
        digitalWrite(ARRIBA_1, HIGH);
        digitalWrite(ARRIBA_2, HIGH);
    digitalWrite(ABAJO_1, LOW);
         digitalWrite(ABAJO_2, LOW);
       
      }

      if (estado==1){// para
         digitalWrite(ARRIBA_1, LOW);
  digitalWrite(ARRIBA_2, LOW);
        digitalWrite(ABAJO_1, LOW);
         digitalWrite(ABAJO_2, LOW);
      }
 
 
  if (estado==2){// pasa a subida
     digitalWrite(ARRIBA_1, LOW);
  digitalWrite(ARRIBA_2, LOW);
        digitalWrite(ABAJO_1, HIGH);
         digitalWrite(ABAJO_2, HIGH);
    }
   if (estado==3){// para
         digitalWrite(ARRIBA_1, LOW);
  digitalWrite(ARRIBA_2, LOW);
        digitalWrite(ABAJO_1, LOW);
         digitalWrite(ABAJO_2, LOW);
  }
}

#include <EEPROM.h>
#include <Servo.h>              // Libreria para el servomotor
Servo miServo;                  // Asignación del nombre servomotor
//*************************** PINES ********************************
const int pinPot=0;             // Lectura del potenciometro
const int pinServo=7;           // Salida para el servomotor
int const grab_off=2;
int const grab_on=3;
int const lectura=4;
int const pulso=5;
int const modo=6;
//*************************** VARIABLES - CONSTANTES ****************
const int pulsoMin=600;         // Rango minimo de pulso
const int pulsoMax=2400;        // Rango maximo de pulso
int address=0;
int i=0;
int j=0;
int k=0;
int valor;                      // variable almacena datos analogico
int angulo;                     // variable almacena el angulo de giro

void setup() {
  // put your setup code here, to run once:
 pinMode(modo,INPUT);       // entrada
 pinMode(pulso,INPUT);      // entrada
 pinMode(lectura,INPUT);   // entrada
 pinMode(grab_on,OUTPUT);
 pinMode(grab_off,OUTPUT);
 miServo.attach(pinServo, pulsoMin, pulsoMax);   // define variable a usar para el servomotor
 Serial.begin(9600);
}

void loop() {
 
//**************************** OPCIÓNES *********************  
  if(digitalRead(modo)==0)
  { i++;
    if(i==1)
     { Serial.println("*********GRABANDO:ON**********");
       digitalWrite(grab_on,HIGH);
       digitalWrite(grab_off,LOW);

     }
 
    if(i>=2)
      {i=0;
      Serial.println("*********GRABANDO:OFF*********");
      digitalWrite(grab_on,LOW);
      digitalWrite(grab_off,HIGH);
     // digitalWrite(lectura_on,LOW);
      }
      delay(100);
      while(digitalRead(modo)==0){}         
  }   
//***************** ESCRITURA EEPROM *****************************
   if(i==1)
      {
          valor = analogRead(0) / 4;  
          angulo=map(valor, 0, 256, 0, 180);       // escalamiento de datos
          miServo.write(angulo);                    // envia el angulo de giro al servomotor miServo
          delay(20);                                // delay banda muerta
        
        if(digitalRead(pulso)==0)
          {
          j++;  
          EEPROM.write(j,valor);          
          Serial.print("Posicion ");
          Serial.print(j);
          Serial.print(":Valor ");
          Serial.println(valor);                   
          
          delay(100);
          while(digitalRead(pulso)==0){} 
          }
      }
//******************* LECTURA EEPROM ***************************** 
    if(digitalRead(lectura)==0)
    {   
     Serial.println("************ REPRODUCIENDO *************** ");
      for(k=1;k<(j+1);k++)       
      { 
        int memo=EEPROM.read(k);
        angulo=map(memo, 0, 256, 0, 180);       // escalamiento de datos
        miServo.write(angulo);                    // envia el angulo de giro al servomotor miServo
        delay(20);                                // delay banda muerta
        Serial.print("Posicion ");
        Serial.print(k);
        Serial.print(":Valor ");
        Serial.println(memo);
        delay(300);
      }  
      j=0;
    }
//********************************************************************
 
  
}

/* Codigo que realiza el encendido de un diodo led
 ademas puede hacerlo parpadear por un tiempo definido
 por el usuario
 */
 
 void setup() {        
   pinMode(4,OUTPUT);      // Declara el pin4 como salida
 }  
 
 void loop() {               // bucle
   digitalWrite(4,HIGH);     // pone en nivel alto el pin4
   delay(250);              // espera 1 segundo
   digitalWrite(4,LOW);      // pone en nivel bajo el pin4
   delay(250);              // espera 1 segundo
  }
 
  

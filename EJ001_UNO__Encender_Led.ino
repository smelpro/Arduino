/* Codigo que realiza el encendido de un diodo led
 ademas puede hacerlo parpadear por un tiempo definido
 por el usuario
 */
 
 void setup() {
   pinMode(4,OUTPUT);
 }  
 
 void loop() {
   digitalWrite(4,HIGH);
   delay(1000);
   digitalWrite(4,LOW);
   delay(1000);
  }
 
  

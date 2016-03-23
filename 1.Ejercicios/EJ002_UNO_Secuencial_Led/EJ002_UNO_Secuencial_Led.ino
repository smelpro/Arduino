 int i;                // declarando variable i
 void setup() {        
   pinMode(0,OUTPUT);      // Declara el pin0 como salida
   pinMode(1,OUTPUT);      // Declara el pin1 como salida
   pinMode(2,OUTPUT);      // Declara el pin2 como salida
   pinMode(3,OUTPUT);      // Declara el pin3 como salida
 }  
 
 void loop() {                   // bucle
   for(i=0;i<4;i++){            // for para controlar el encendio de 4 leds
   digitalWrite(i,HIGH);         // enciende el diodo led conectado al pin i
   delay(500);
   digitalWrite(i,LOW);          // apaga el diodo led conectado al pin i
   delay(500);          
  }   
  }
 
  

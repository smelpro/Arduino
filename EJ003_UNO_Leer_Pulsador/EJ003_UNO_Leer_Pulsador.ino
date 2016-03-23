 
 void setup() {
   pinMode(5,INPUT);                // declarando pin5 como entrada
   pinMode(6,OUTPUT);              // declarando pin6 como salida
   }
 void loop() {
   
   if(digitalRead(5)==0){                  // estructura de control IF-ELSE, consulta si alguien preciono el pulsador
     digitalWrite(6,HIGH);        // si se presiono el pulsador entonces enciende led conectado al pin6 
     while(digitalRead(5)==0) {}           // antirrebote por codigo, condicion que elimina rebotes
     }  
   else{
   digitalWrite(6,LOW);            // apaga diodo led conectada al pin6
   }
 }

   

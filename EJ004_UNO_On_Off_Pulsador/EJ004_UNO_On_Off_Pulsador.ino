
 int i=0;                       // declarando variable i 
 const int pulsador=5;          // declarando pin5 con nombre pulsador
 const int led = 6;            // declarando pin13 con nombre led
 
 void setup() {
   Serial.begin(9600);  // inicializo el envio de datos serial
   pinMode(pulsador,INPUT);      // declarando pulsador como entrada
   pinMode(led,OUTPUT);          // declarando led como salida
   }
 void loop() {
   
  
   if(digitalRead(pulsador)==0)                      // si se preciona pulsador 
   {  
     i=i+1;                            // contador de cuantas veces se presiona el pulsador
     if(i>=2)                           // si es mayor igual que 2 entonces inicializa la variable i=0 
     {i=0;}
  
   Serial.print("i: ");
   Serial.print(i);
   Serial.println(" intento");
   delay(500);   
    
   while(digitalRead(pulsador)==0)    // codigo antirrebote, no hace nada
   {}                                  // no ejecuta ningun codigo
   
     if(i==1)                          // si se presiona la primera vez , se enciende el led
     {digitalWrite(led,HIGH);}     
     else{                             // si se presiona por segunda vez, se apaga el diodo led   
     digitalWrite(led,LOW);}
         
   }
 
 }

   

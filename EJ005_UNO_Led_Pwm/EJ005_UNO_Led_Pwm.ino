/* Codigo que realiza el atenuado de un diodo led, para lo cual
utiliza el PWM del pin3
 */
 
 const int led=3 ;    // declara pin3 como led
 int brillo;          // declara variable brillo
 
 void setup() {
   pinMode(led,OUTPUT);    // declara pin led como salida
 }

void loop() {
 for(brillo=0; brillo<256; brillo++){      // for para aumentar la luminosidad del diodo led
   analogWrite(led,brillo);                // enviando señal analogica PWM al diodo led
   delay(10);
   }
 for(brillo=255; brillo>=0; brillo--){    // for para disminuir la luminosidad del diodo led
   analogWrite(led,brillo);                // enviando señal analogica PWM al diodo led
   delay(10);
   } 
   
  } 

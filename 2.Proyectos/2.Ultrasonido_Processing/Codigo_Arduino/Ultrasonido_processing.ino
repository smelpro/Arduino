//********************* CODIGO ARDUINO ULTRASONIDO CON PROCESSING ********
long distancia;
long tiempo;
const int trigger = 8;
const int echo = 7;

void setup(){
  Serial.begin(9600);       // inicializo el envio de datos serial
  pinMode(trigger, OUTPUT); //trigger como salida  para el envio del pulso ultrasónico
  pinMode(echo, INPUT);     // echo como entrada para medir pulso del eco retorno del ultrasonido
}

void loop(){

  digitalWrite(trigger,LOW);      // Pone a nivel bajo el trigger
  delayMicroseconds(5);           // espera 5us para establecer 
  digitalWrite(trigger, HIGH);   // Pone a nivel alto el trigger
  delayMicroseconds(10);         // Envia rafaga de pulsos segun especificacion tecnica
  tiempo=pulseIn(echo, HIGH); /*Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
                                del pulso ultrasónico y cuando el sensor recibe el rebote */ 
  distancia= int(0.017*tiempo); //fórmula  distancia = ((340/2)*100)/1000000  // se multiplica por 100 cm y se divide entre 1000000 para pasarloa a us
 
 /************* COGIO PARA ENVIAR POR MONITOR SERIAL ARDUINO **********
  Serial.print("Distancia ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(500);                // delay para mostrar en el monitor serial del arduino.
  ********************************************************/
  
  Serial.write(distancia);      // Enviando Distancia a Processing
  delay(350);                   // Pause para estabilizar datos
}

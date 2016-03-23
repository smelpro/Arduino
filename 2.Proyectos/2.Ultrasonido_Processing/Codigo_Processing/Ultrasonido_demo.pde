// ****************** Lectura se de sensor Ultrasonido ****************

import processing.serial.*;                     // Importa la libreria serial
    
Serial miPuerto;                                 // Nombra el puerto serie  
int pos_x=50;                                    // Variebles
int pos_y=220;                                   //     
int data=0;                                      //  
int diam=40;                                     //
float pos_ultra;                                 //
float a=0;                                       //     
PFont f,n;                                       //

void setup() {
  
  printArray(Serial.list());                               // Lista los puertos disponibles
  miPuerto = new Serial(this, Serial.list()[18], 9600);    // Configuración puerto
  size(500,400);                                           // Tamaño de la ventana
 
}

void draw() {
    
    background(255);                         // Pinta el fondo de blanco( Limpia )
    while (miPuerto.available() > 0) {       // Consulta si hay un byte disponible en el puerto
    data = miPuerto.read();                  // Lectura del puerto serie
    println(data);                           // Envia el datos serial a la consola    
    pos_ultra=map(data,5,300,20,480);        // Escalando distancia VS pixeles 
  }
    fill(0,0,0);                             // Color del texto
    f = createFont("Arial",16,true);         // Configura tipo de letra, tamaño y anti-aliasing ON
    textFont(f,30);                          // Configura tamaño para este texto
    text("Distancia:", 130, 130);                     // Envia texto 
    text(data, 280, 130);                     // Envia distancia en coordenada 
    text("cm", 330, 130);                     // Envia texto 
        
 //  Para usar la el dibujo por Linea tienes que deshabilitar el dibujo de la Elipse
    
 // **************************** DIBUJO DE ELIPSE *******************************   
      noStroke();                                  // Deshabilita linea de borde   
      fill(0);                                     // Color relleno    
      ellipse(pos_x+pos_ultra,pos_y,diam,diam);    // Dibuja la elipse
      delay(200);                                  // Pause 100ms
      
 // **************************** FIN DE ELEIPSE ********************************
 
 // *************************** DIBUJO DE LINEA ********************************
   /* stroke(0);                                  // Color de la linea
    strokeWeight(4);                              // Grosor de la linea
    line(pos_x,pos_y,pos_x+pos_ultra,pos_y);      // Dibuja la linea  
    delay(100);                                   // Pause de 100ms
 */
 // **************************** FIN DE LINEA ***********************************
  
  //*********************** Texto a Cabecera ********************************   
  fill(23,161,165);                               // Color del texto
//  n = createFont("Arial",16,true);           // Configura tipo de letra, tamaño y anti-aliasing ON
 // textFont(n,35);                            // Configura tamaño para este texto
  text("SENSOR ULTRASONIDO", 80, 50);         // Envia texto
 //*********************** Fin de texto a pie de pagina ************************* 

  
 //*********************** Texto a Pie de pagina ********************************   
  fill(23,161,165);                               // Color del texto
  n = createFont("Arial",16,true);           // Configura tipo de letra, tamaño y anti-aliasing ON
  textFont(n,25);                            // Configura tamaño para este texto
  text("www.smelpro.com", 140, 350);         // Envia texto
 //*********************** Fin de texto a pie de pagina ************************* 
  
}
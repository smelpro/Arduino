#include <SPI.h>
#include <Ethernet.h>

//Declaración de la direcciones MAC e IP. También del puerto 80
byte mac[]={0xDE,0xAD,0xBE,0xEF,0xFE,0xED};     //MAC del arduino Shield
IPAddress ip(192,168,1,10);                     //IP del arduino Shield
EthernetServer servidor(80);                    // Puerto 80 del servidor

int PIN_LED=2;

String readString=String(30);            // declara variable string de 30 elementos
String state=String(3);                  // declara variable string de 3 elementos

void setup()
{
  Ethernet.begin(mac, ip);              //Inicializamos con las direcciones asignadas
  servidor.begin();                     // Inicializa servidor
  pinMode(PIN_LED,OUTPUT);              // declara pin_led como salida
  digitalWrite(PIN_LED,HIGH);           
  state="OFF";
}

void loop()
{
  EthernetClient cliente= servidor.available();
  
  if(cliente)
  {
    boolean lineaenblanco=true;
    while(cliente.connected())//Cliente conectado
    {
      if(cliente.available())
      {
        char c=cliente.read();
        if(readString.length()<30)//Leemos petición HTTP caracter a caracter
        {
          readString.concat(c); //Almacenar los caracteres en la variable readString
        }
        if(c=='\n' && lineaenblanco)//Si la petición HTTP ha finalizado
        {
          int LED = readString.indexOf("LED=");
          if(readString.substring(LED,LED+5)=="LED=T")
          {
            digitalWrite(PIN_LED,HIGH);
            state="ON";
          } else if (readString.substring(LED,LED+5)=="LED=F")
          {
            digitalWrite(PIN_LED,LOW);
            state="OFF";
          }
          
         
          //Cabecera HTTP estándar
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println();        
          //Página Web en HTML
          cliente.println("<html>");
          cliente.println("<head>");
          cliente.println("<title>ENCENDER LED</title>");
          cliente.println("</head>");
          cliente.println("<body width=50% height=50%>");
          cliente.println("<center>");
          cliente.println("<h1>LED ON/OFF</h1>");
          cliente.print("<br><br>");
          cliente.print("Estado del diodo LED: ");
          cliente.print(state);
          cliente.print("<br><br><br><br>");
          cliente.println("<input type=submit value=ON style=width:75px;height:70px onClick=location.href='./?LED=T\'>");
          cliente.println("<input type=submit value=OFF style=width:75px;height:70px onClick=location.href='./?LED=F\'>");
          cliente.println("</center>");
          cliente.println("</body>");
          cliente.println("</html>");
          cliente.stop();//Cierro conexión con el cliente
          readString="";
        }
      }
    }
  }
}

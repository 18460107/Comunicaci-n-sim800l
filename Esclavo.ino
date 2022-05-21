#include <SoftwareSerial.h>
SoftwareSerial S800(11,12); //RX 11 TX 12

const int Trigger =2;  //Pines
const int Echo =3;     //y
float tiempo;          //variables 
float distancia;       //Usadas a lo
String dato;           //Largo del 
String MSGE;            //Código

void setup() {
  Serial.begin(9600);
  S800.begin(9600);
  
  pinMode(Trigger,OUTPUT);
  pinMode(Echo,INPUT);
  digitalWrite(Trigger, LOW);

  delay(2000);
  S800.println("AT+CNMI=2,2,0,0,0");//RECIBIR MENSAJES Y HACER QUE LEA
  delay(100);
  S800.println("AT+CMGF=1");//FORMATO SMS
  S800.println("AT+CMGS=\"+523121009761\"");//Numero Maestro +523121009761
}

void loop() {
if(S800.available()>0){
  
  MSGE=S800.readString();
  
  if(MSGE.indexOf("KP58CD")>=0){
      
      digitalWrite(Trigger, HIGH);       //Se encarga 
      delayMicroseconds(10);             //De calcular 
      digitalWrite(Trigger, LOW);        //Todo eso 
      tiempo = pulseIn(Echo, HIGH);      //De la 
      distancia = tiempo/59;             //Distancia
      dato=String(distancia);                //Transformación de la distancia
      delay(1000);
      S800.print("Distancia "+dato);    //Mensaje enviado
      //Serial.println(dato);
      S800.write(26);
      

         S800.println("AT+CMGF=1");
         S800.println("AT+CMGS=\"+523121009761\"");//Numero Maestro
    }
  }

}

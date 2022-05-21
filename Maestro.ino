#include <SoftwareSerial.h>
SoftwareSerial S800(11,12); //RX 11  TX 12

                          
String Msg;              //Pines y variables    
String co1="KP58CD";     //Que se usaron 
char letra;              //Durante    
int reco=0;           // A lo largo de    
char bufer[100];           //Todo el    
char Dat[5]="";         //Código
String cadenaStr;        
float resultado=0;

void setup()
{
Serial.begin(9600);
S800.begin(9600);
delay(2000);  
S800.println("AT+CNMI=2,2,0,0,0");
delay(100);
S800.println("AT+CMGF=1");    //SMS texto
S800.println("AT+CMGS=\"+523121013202\"");//Nunero Esclavo    523121013202  


  }

  void loop(){
    if(Serial.available()>0){

      letra=Serial.read();

        if(letra=='C'){                     //Boton labview
         
          S800.print(co1);            //Código para enviar
          S800.write(26);                 
         
          
          S800.println("AT+CMGF=1");   //SMS texto
          S800.println("AT+CMGS=\"+523121013202\""); //Numero Esclavo  523121013202
          delay(3000);
          reco=1;
          letra='D';

        }
        letra='D';
    }
    if(reco==1){ //se ocupa apachurrar el boton primero    
      Msg=S800.readString();
      
      if(Msg.indexOf("Distancia")>=0){
                                            
        //Serial.println(Msg);
        //Serial.println("________________");
        

        Msg.toCharArray(bufer,100);
        int j=0;
        for(int i=58;i<64;i++){//64 AUN HAY VALORES FANTASMA
        //Serial.print(bufer[i]);//El mensaje que se recivirá ya es directo
        (bufer[i]);//El mensaje que se recivirá ya es directo
        delay(50);
        Dat[j]=bufer[i];
        j++;
        }
        cadenaStr=String(Dat); 
        resultado = cadenaStr.toFloat();
        //Serial.println("resultado2___");
        Serial.println(resultado);                                  //Se manda el valor al labview
        delay(1);     
        ///////////////////////////////////////////////////////////////////////modificar fin el valor obtenido
        
        delay(2000);
        reco=0;
     
      }
  }
    }

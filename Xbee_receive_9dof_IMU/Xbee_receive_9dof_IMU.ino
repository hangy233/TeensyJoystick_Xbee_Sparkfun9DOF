#include <SoftwareSerial.h>


SoftwareSerial xBeeSerial = SoftwareSerial( 9,10);
char GotChar;
//char c = 'A';

int p=0;
int r=0;
int h=0;

String temp;

boolean get=false;

void setup()
{
  Joystick.useManualSend(true);
  xBeeSerial.begin(9600);
  Serial.begin(9600);
}

void loop(){
 if ( xBeeSerial.available() ) {
      GotChar = xBeeSerial.read();
      
      if(get==false && (String(GotChar) == "H" || String(GotChar) == "P" || String(GotChar) == "R")){
        get = true;
        GotChar='0';
      }
      
      
      
      if(get == true && String(GotChar) == "P"){
        get = false;
        //Serial.println(temp.toInt());
        Joystick.Y(temp.toInt());
        Joystick.send_now();
        temp = ""; 
      }
      if(get == true && String(GotChar) == "R"){
        get = false;
        //Serial.println(temp.toInt());
        Joystick.X(temp.toInt());
        Joystick.send_now();
        temp = ""; 
      }
      if(get == true && String(GotChar) == "H"){
        get = false;
        //Serial.println(temp.toInt());
        Joystick.Z(temp.toInt());
        Joystick.send_now();
        temp = ""; 
      }
      
      
      
      
      
      
      
      
      if(get == true){
         temp+=GotChar; 
      }
      
      
      
  }
}
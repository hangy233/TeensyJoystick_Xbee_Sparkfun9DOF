#include <SoftwareSerial.h>


SoftwareSerial xBeeSerial = SoftwareSerial( 9,10);
char GotChar;
//char c = 'A';


String temp;

String getC;

boolean get=false;

void setup()
{
  Joystick.useManualSend(true);
  xBeeSerial.begin(9600);
  Serial.begin(9600);


}

void loop(){
 if ( xBeeSerial.available() ) {
     //read xbee data
      GotChar = xBeeSerial.read();
      
      //Serial.print(String(GotChar));
      //Serial.println(temp);
      

      
      //end get value
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
      if(get == true && String(GotChar) == "X"){
        get = false;
        //Serial.println(temp.toInt());
        Joystick.Z(temp.toInt());
        Joystick.send_now();
        temp = ""; 
      }
      
       if(get == true && String(GotChar) == "Y"){
        get = false;
        //Serial.print(temp.toInt());
        Joystick.button(1, temp.toInt());
        temp = ""; 
      }
       if(get == true && String(GotChar) == "Z"){
        get = false;
        Joystick.button(2, temp.toInt());
        temp = ""; 
      }
       if(get == true && String(GotChar) == "H"){
        get = false;
        Joystick.button(3, temp.toInt());
        temp = ""; 
      }
      
      
      //start get value
       if(get==false && (String(GotChar) == "H" || String(GotChar) == "P" || String(GotChar) == "R" || String(GotChar) == "X" || String(GotChar) == "Y" || String(GotChar) == "Z")){
        get = true;
        getC= String(GotChar);
        GotChar='0';
      }
      
      
      
      //getting value
      if(get == true){
         temp+=GotChar; 
      }
      
      
      
  }
}

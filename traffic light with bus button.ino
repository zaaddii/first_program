int red = 12;
int yellow = 11;
int green = 10;
int button =9;
int buttonState = 0;
const int redstate=0;
const int yellowstate=1;
const int greenstate=2;
int currentstate=0;
int buttonpressed=0;

  
  
void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
  //digitalWrite(red,HIGH);//light should stay green unless somebody press the button
  //delay(3000);  
 
}

void loop()
{
  
 switch(currentstate)
 {
   
  case redstate:
   //Serial.println(currentstate);
   digitalWrite(red, HIGH);
   Serial.println("make the red light high");
   for(int i=0; i<5;i++)
   {
    
     delay(1000);
     Serial.println("loop for red light before pressing button");
     buttonpressed = digitalRead(button);
       //Serial.println(button);
     
     if(buttonpressed==HIGH)
     {
      
       Serial.println("buttonpressed now move to yellow");
       currentstate=2;
       digitalWrite(red,LOW);
       break;
     }
   } 
   currentstate=1;
   digitalWrite(red,LOW);
   Serial.println("Turn the red low");
   break;
      
     
 case  yellowstate :
   Serial.println("Now in yellow");
     digitalWrite(yellow,HIGH);
     delay(2000);
     currentstate=2;
   Serial.println("Now turn yellow off and move to green");
     digitalWrite(yellow,LOW);
      
   break;
   
  case greenstate:
   digitalWrite(green, HIGH);
   for(int i=0;i<5;i++)
   {
   delay(1000);
   
   Serial.println("loop for green before pressing the button");
   if(digitalRead(button)==HIGH)
   { 
    
     Serial.println("button pressed");
   for(int j=0;j<3;j++)
   {
   	delay(1000);
     Serial.println("loop after pressing buttonState");
   }
   }
   }
   currentstate= 0;
   digitalWrite(green ,LOW);
   break;
 }
 }
  




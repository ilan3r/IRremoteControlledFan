#include <IRremote.h> 
int IRpin=3;
IRrecv IR(IRpin); 
String myCom; 
decode_results cmd; 

int speedpin = 6; 
int dir1=5; 
int dir2=4; 
int mspeed=255; 


void setup(){
Serial.begin(9600); 
IR.enableIRIn(); 
pinMode(speedpin, OUTPUT); 
pinMode(dir1, OUTPUT); 
pinMode(dir2, OUTPUT); 
digitalWrite(dir1, HIGH); 
digitalWrite(dir2, LOW);
}


void loop(){
  
while (IR.decode(&cmd)==0){
}
delay(500); 
IR.resume();

if (cmd.value==0xFF6897){
  myCom="zero"; 
}

if (cmd.value==0xFF30CF){
  myCom="one"; 
}

if (cmd.value==0xFF18E7){
  myCom="two"; 
}

if (cmd.value==0xFF7A85){
  myCom="three"; 
}

if (cmd.value==0xFF10EF){
  myCom="four"; 
}

if (cmd.value==0xFF38C7){
  myCom="five"; 
}

if (cmd.value==0xFF5AA5){
  myCom="six"; 
}

if (cmd.value==0xFF42BD){
  myCom="seven"; 
}

if (cmd.value==0xFF4AB5){
  myCom="eight"; 
}

if (cmd.value==0xFF52AD){
  myCom="nine"; 
}

if (cmd.value==0xFF9867){
  myCom="eq"; 
}

if (cmd.value==0xFFB04F){
  myCom="repeat"; 
}

if (cmd.value==0xFF906F){
  myCom="scrollup"; 
}

if (cmd.value==0xFFE01F){
  myCom="scrolldown"; 
}

if (cmd.value==0xFFA857){
  myCom="voldown"; 
}

if (cmd.value==0xFF629D){
  myCom="volup"; 
}

if (cmd.value==0xFF02FD){
  myCom="play/pause"; 
}

if (cmd.value==0xFFC23D){
  myCom="next"; 
}

if (cmd.value==0xFF22DD){
  myCom="previous"; 
}

if (cmd.value==0xFFE21D){
  myCom="stop"; 
}

if (cmd.value==0xFFA25D){
  myCom="pwr"; 
}


if (myCom=="pwr"){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
  mspeed=255;  
  analogWrite(speedpin, mspeed); 
}


if (myCom=="stop"){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH); 
  mspeed=0; 
  analogWrite(speedpin, mspeed); 
}

if (myCom=="next"){
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH); 
  analogWrite(speedpin, mspeed); 
}

if (myCom=="previous"){
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW); 
  analogWrite(speedpin, mspeed); 
}

if (myCom=="volup"){
  mspeed=mspeed+15; 
  if (mspeed>255){
    mspeed=255; 
  }
  analogWrite(speedpin, mspeed);
}

if (myCom=="voldown"){
  mspeed=mspeed-15; 
  if (mspeed<105){
    mspeed=105; 
  }
  analogWrite(speedpin, mspeed);
}

Serial.print(myCom); 
Serial.print(" == motor speed is: "); 
Serial.println(mspeed); 

myCom=" ";

}

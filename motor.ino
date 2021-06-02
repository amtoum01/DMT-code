int inA=10;
int inB=11;
int PWM=12;


void setup() {
  // put your setup code here, to run once:

  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(PWM,OUTPUT);

  digitalWrite(inA,HIGH);
  digitalWrite(inB,LOW);

  analogWrite(PWM,255);
  
}

void loop() {

  anticlockwise();
  delay(4000);
  stop_motor();
  delay(500);
  clockwise();
  delay(4000);
  stop_motor();
  delay(500);


}

void clockwise(){

  digitalWrite(inA,HIGH);
  digitalWrite(inB,LOW);
  
}

void anticlockwise(){

  digitalWrite(inA,LOW);
  digitalWrite(inB,HIGH);
  
}

void stop_motor(){
  
  digitalWrite(inA,LOW);
  digitalWrite(inB,LOW);

  

}

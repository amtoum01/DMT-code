

// change values 34 and 3 to whatever you connect channel A and B inputs from the endocder to the arduino
#define ChannelA1 7
#define ChannelB1 3

#define ChannelA2 6
#define ChannelB2 2

int counter1=0;
int counter2=0;

int angle1;
int angle2;

int max_value = 256;

String encdir1="";
String encdir2="";



void setup() {

  pinMode(ChannelA1,INPUT_PULLUP);
  pinMode(ChannelB1,INPUT_PULLUP);
  pinMode(ChannelA2,INPUT_PULLUP);
  pinMode(ChannelB2,INPUT_PULLUP);
  

  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(ChannelB1), updateEnc, RISING);
  attachInterrupt(digitalPinToInterrupt(ChannelB2), updateEnc, RISING);

}

void loop() {

  analogWrite(12,200);
  
}

void updateEnc(){
  cli();

  if(digitalRead(ChannelA1) != 1){
    counter1 ++;
    encdir1="CCW";
  }
  else if(digitalRead(ChannelA1) == 1){
    counter --;
    encdir1="CW";
  }
  else if(digitalRead(ChannelA2) != 1){
    counter2 ++;
    encdir2="CCW";
  }
  else if(digitalRead(ChannelA2) == 1){
    counter2 --;
    encdir2="CW";
  }
  

  angle1 = map(encdir1, 0 , 256 , 0 , 360);
  angle2 = map(encdir2, 0 , 256 , 0 , 360);

  Serial.print(angle1);
  Serial.print("     ");
  Serial.print(angle2);
  Serial.println("");
  sei();
}

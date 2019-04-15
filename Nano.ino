int echo1 = 13;
int trigger1 = 10;
int echo2 = 5;
int echo3 = 6;


//
int trigger2 = 3;
int trigger3 = 11;



int ir = 4;



double timer1 ;
double timer2 ;
double timer3 ;
double distance1;
double distance2;
double distance3;
 int vibrator1 = A2;
 int vibrator2 = A1;
 int vibrator3 = A3;


void setup() {
  
  // put your setup code here, to run once:
  pinMode(echo1, INPUT);
  pinMode(ir,INPUT);
  pinMode(trigger1, OUTPUT);
   pinMode(echo2, INPUT);
  pinMode(trigger2, OUTPUT);
   pinMode(echo3, INPUT);
  pinMode(trigger3, OUTPUT);
  pinMode(vibrator1, OUTPUT);
   pinMode(vibrator2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(ir)==0){
  analogWrite(vibrator1,0);
  analogWrite(vibrator2,0);
  analogWrite(vibrator3,0);
  // put your main code here, to run repeatedly:

    digitalWrite(trigger1, LOW);

  delay(1);
  digitalWrite(trigger1, HIGH);

  delay(1);
  digitalWrite(trigger1, LOW);
  timer1 = pulseIn(echo1, HIGH);
//  timer3 = pulseIn(echo3,HIGH);
  
    digitalWrite(trigger2, LOW);

  delay(1);
  digitalWrite(trigger2, HIGH);

  delay(1);
  digitalWrite(trigger2, LOW);

  



    timer2 = pulseIn(echo2,HIGH);




digitalWrite(trigger3, LOW);

  delay(1);
  digitalWrite(trigger3, HIGH);

  delay(1);
  digitalWrite(trigger3, LOW);

  



    timer3 = pulseIn(echo3,HIGH);

    


  distance1 = timer1 * 0.017;
  distance2 = timer2 * 0.017;
  distance3 = timer3 * 0.017;
  Serial.println("-----------------------------------------");
  Serial.print("first");
  Serial.println(distance1);
  Serial.print("second");
Serial.println(distance2);
Serial.print("third");
Serial.println(distance3);




if (distance1<50){
  analogWrite(vibrator1,700);
  delay(10);
}
if (distance2<50){
  analogWrite(vibrator2,700);
  delay(10);
}
if (distance3<50){
  analogWrite(vibrator3,700);
  delay(10);
}
delay(125);
}
else{
 digitalWrite(vibrator2, LOW);
 digitalWrite(vibrator1, LOW);
 digitalWrite(vibrator3,LOW);

  
}

}

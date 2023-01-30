void setup() {
  Serial.begin(9600);
  srv.attach(8);
  pinMode(2, OUTPUT); // Red Led
  pinMode(3, OUTPUT); // Blue Led
  pinMode(6, INPUT);// Left Button
  pinMode(7, INPUT);// Right Button

}

void loop() {
  button_case();
  UDLR();
}

void button_case(){
  for(int i=2; i<=3; i++){
    digitalWrite(i,1);
    delay(100);
    digitalWrite(i,0);
    delay(100);}
 }

void UDLR(){
  int up_down = analogRead(A0);
  int left_right = analogRead(A1);
  
  if(up_down > 700 && left_right > 700)
    Serial.println("UP/Right");
  else if(up_down > 700 && left_right < 500)
    Serial.println("UP/Left");
    
  else if(up_down < 400 && left_right > 700)
    Serial.println("Down/Right");
  else if(up_down < 400 && left_right < 500)
    Serial.println("Down/Left");
    
 else if(up_down < 700 && up_down > 400 && left_right < 500 )
    Serial.println("Midel/Left");
 else if(up_down < 700 && up_down > 400 && left_right > 700 )
    Serial.println("Midel/Right");

 else if(left_right < 700 && left_right > 400 && up_down > 700 )
    Serial.println("Up / Midel");
  else if(left_right < 700 && left_right > 400 && up_down < 500 )
    Serial.println("Down / Midel");
    
  else
    Serial.println("Midel");
  }

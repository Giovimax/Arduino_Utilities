

void setup() {
Serial.begin(9600);
pinMode(2,INPUT);
pinMode(13,OUTPUT);
}

void loop() {
  int s0 = digitalRead(2);
  Serial.println(s0);//prints the result
  if (s0 == true) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
}

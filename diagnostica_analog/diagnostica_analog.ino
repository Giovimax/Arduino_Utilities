

void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(13,OUTPUT);
}

void loop() {
  int s0 = analogRead(A0);
  Serial.println(s0);//prints the result
  if (s0 >= 512) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
}

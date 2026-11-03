int count = 0;

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(115200);
  Serial.println("boot ok");
}

void loop() {
  count++;
  digitalWrite(9, HIGH);
  Serial.print("tick ");
  Serial.print(count);
  Serial.println("  LED=ON");
  delay(500);

  digitalWrite(9, LOW);
  Serial.print("tick ");
  Serial.print(count);
  Serial.println("  LED=OFF");
  delay(500);
}

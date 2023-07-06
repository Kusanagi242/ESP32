int Counter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Counter:");
  Serial.println(Counter);
  Counter++;
  if(Counter == 3)
  { 
    Counter = 0;
  }
  delay(50);
}

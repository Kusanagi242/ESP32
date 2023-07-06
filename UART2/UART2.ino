// UART2
void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial2.println("Hello Boss from UART2!");
  delay(100);
}

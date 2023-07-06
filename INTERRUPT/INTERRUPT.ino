// Interruppt
#define button 0
#define LED 2
int numPress = 0;
bool isPress = false;

void IRAM_ATTR isr(){
numPress += 1;
isPress = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  attachInterrupt(button, isr, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(isPress) {
    digitalWrite(LED, !digitalRead(LED));
    Serial.printf("Nut nhan da duoc an %u lan\n", numPress);
    isPress = false;
  }
}

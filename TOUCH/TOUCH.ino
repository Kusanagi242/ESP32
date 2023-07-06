#define LED 2
#define Button 4
bool buttonState = 1; 
void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("Touch test");
  pinMode(LED, OUTPUT);
}
void loop()
{
  if(touchRead(Button) < 10)
  {
    if(buttonState == 1)
    {
      digitalWrite(LED, !digitalRead(2));
    }
    buttonState = 0;
  }
  else
  {
    buttonState = 1;
  }
  if(digitalRead(LED) == HIGH)
  {
    Serial.println("LED: ON");
  }
  else
  {
    Serial.println("LED: OFF");
  }
  delay(100);
}

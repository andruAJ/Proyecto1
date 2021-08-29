int Counter = 20;
void config()
{
 Serial.println(Counter);
  if (digitalRead(13)== HIGH)
  {
    Counter++;
  }
  if (digitalRead(12)== HIGH)
  {
    Counter--;
  }
  if (digitalRead(10)== HIGH
  {
      countDown();
  }
}
void countDown(); 
void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(10, INPUT);
 Serial.begin(115200);
 config();
}

void loop()
{
  
}

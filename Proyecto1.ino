int counter = 20;
void config()
{
 Serial.println(counter);
  if (counter <= 59 && counter >= 11)
  {
   if (digitalRead(13)== HIGH)
   {
    
   }
   else
   {
    counter++;
    Serial.println(counter);
   } 
   if (digitalRead(12)== HIGH)
   {
    
   }
   else
   {
    counter--;
    Serial.println(counter);
   }  
   if (digitalRead(10)== HIGH)
   {
      
   }
   else
   {
    //countDown();
   }  
  }
  else if (counter = 60)
  {
   if (digitalRead(12)== HIGH)
   {
    counter--;
    Serial.println(counter);
   }
   if (digitalRead(10)== HIGH)
   {
      //countDown();
   }
  }
  else if (counter = 10)
  {
   if (digitalRead(13)== HIGH)
   {
    counter++;
    Serial.println(counter);
   }
   if (digitalRead(10)== HIGH)
   {
      //countDown();
   }
  }
}
void countDown(){}
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

int counter = 20;
int boton1;
int boton2;
int boton3;
const int val1 = 13;
const int val2 = 12;
const int val3 = 10;
void config()
{
 Serial.println(counter);
  if (counter <= 59 && counter >= 11)
  {
   if (boton1 == HIGH)
   {
    counter++;
    Serial.println("En el 13:");
    Serial.println(counter);
   } 
   boton2 = digitalRead(val2);
   if (boton2 == HIGH)
   {
    counter--;
    Serial.println("En el 12:");
    Serial.println(counter);
   }
   boton3 = digitalRead(val3); 
   if (boton3 == HIGH)
   {
    //countDown();  
   } 
  }
  else if (counter = 60)
  {
   boton2 = digitalRead(val2);
   if (boton2 == HIGH)
   {
    counter--;
    Serial.println("En el 12:");
    Serial.println(counter);
   }
   boton3 = digitalRead(val3); 
   if (boton3 == HIGH)
   {
    //countDown();  
   } 
  }
  else if (counter = 10)
  {
   boton1 = digitalRead(val1);
   if (boton1 == HIGH)
   {
    counter++;
    Serial.println("En el 13:");
    Serial.println(counter);
   } 
   boton3 = digitalRead(val3); 
   if (boton3 == HIGH)
   {
    //countDown();  
   } 
  }
}
void countDown(){}
void setup()
{
  pinMode(val1, INPUT);
  pinMode(val2, INPUT);
  pinMode(val3, INPUT);
 Serial.begin(115200);
 config();
}

void loop()
{
  
}

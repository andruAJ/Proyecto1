int counter = 20;
int limite = 20;
int boton1;
int boton2;
int boton3;
const int val1 = 13;
const int val2 = 12;
const int val3 = 10;
uint32_t previousMillis = 0;
const uint32_t intervalo = 1000;

void config()
{
 Serial.println("En caso de activación accidental recuerde presionar el boton arm y luego la secuencia de desactivación");
 Serial.println(counter);
 /*if (counter <= 59 && counter >= 11)
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
    countDown(); 
    limite = counter; 
   } 
  }
  else if (counter == 60)
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
    countDown();
    limite = counter; 
   } 
  }
  else if (counter == 10)
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
    countDown(); 
    limite = counter;  
   } 
  }*/
 countDown();
}
void countDown()
{
  
  Serial.println(counter);
  while (counter > 0)
  {
    uint32_t tiempo = millis();
    if (tiempo - previousMillis >= intervalo) 
    {
       previousMillis = tiempo;
       counter--;
       Serial.println(counter);
       if(counter == 0)
       {
         Serial.println("¡BOOM!");
         config();
       }
    }
  }
}
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

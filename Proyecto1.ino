int counter = 20;
int valor = 0;
uint32_t previousMillis = 0;
const uint32_t intervalo = 1000;

void config()
{
 Serial.println("En caso de activacion accidental recuerde presionar el boton arm y luego la secuencia de desactivacion");
 Serial.println(counter);
 valor = Serial.read();
 while(valor == -1 || valor == 119 || valor == 115)
  {
    if (counter <= 59 && counter >= 11)
    {
     if (Serial.available() > 0)
     {
      valor = Serial.read();
      if (valor == 119)
      {
       counter++;
       Serial.println(counter);
      } 
     
      if (valor == 115)
      {
        counter--;
        Serial.println(counter);
      }
        
      if (valor == 32)
      {
        countDown(); 
      } 
     }
    }  
    else if (counter == 60)
    {
      if (Serial.available() > 0)
      {
        valor = Serial.read();
        if (valor == 115)
        {
          counter--;
          Serial.println(counter);
        } 
        if (valor == 32)
        {
          countDown();
        }
      }
    }
    else if (counter == 10)
    {
      if (Serial.available() > 0)
      {
        valor = Serial.read();
        if (valor == 119)
        {
          counter++;
          Serial.println(counter);
        }  
        if (valor == 32)
        {
          countDown(); 
        } 
      } 
    }
  } 
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
      counter = 20;
      config();
     }
    }
   /* if()
    {
    
    }*/
  }
}
  
void desactivacion()
{
  /*if (){}
  else {}*/
}  

void setup()
{
 Serial.begin(115200);
 config();
}

void loop()
{
   
}

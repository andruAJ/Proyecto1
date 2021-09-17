int counter = 20;
int valor = 0;
uint32_t previousMillis = 0;
const uint32_t intervalo = 1000;
int sec[6] = {115,119,115,115,119,32};
int correct = 0;
int intentos = 0;
int pos = 0;
static int comb[6];

void task1()
{
  enum Estados {CONFIG, COUNTDOWN, DESACTIVACION};
  static Estados estadoActual = CONFIG;

  
  switch (estadoActual)
  {
    case CONFIG: 
    {
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
              estadoActual = COUNTDOWN; 
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
               estadoActual = COUNTDOWN;
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
               estadoActual = COUNTDOWN; 
              } 
            } 
          }
        } 
      
     break; 
    }
    
    case COUNTDOWN:
    {
     valor = -1;
     while (counter > 0)
     {
       valor = Serial.read();
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
         estadoActual = CONFIG;
        }
       }
       if(valor == 32 || valor == 119 || valor == 115)
       {
         estadoActual = DESACTIVACION;
       }
     }
      
     break;
    }
    
    case DESACTIVACION:
    {
      comb[pos] = valor;
      pos++;
      intentos++;
      if (intentos < 6)
      {}
      else 
      {
        for (int i = 0; i < 6; i++)
        {
          if(comb[i] == sec[i])
          {
            correct++;
          }
        }
        if(correct== 6)
        {
          Serial.println("Desactivacion completada");
          counter = 20;
          intentos = 0;
          pos = 0;
          estadoActual = CONFIG; 
        }
        else
        {
          if (intentos == 6)
          {
            if (correct == 0 || correct == 1 || correct == 2 || correct == 3|| correct == 4|| correct == 5)
            {
              correct = 0;
              Serial.println("INCORRECTO");
              for (int a = 0; a < 6; a++)
              {
                comb[a] = 0;
              }
              }
            pos = 0;
            intentos = 0;
          } 
        }
        
      }
      
     break;
    }
    
     default:
     Serial.println("Error");
     break;
    
  }

}

void setup()
{
 Serial.begin(115200);
 task1();
}

void loop()
{
   
}

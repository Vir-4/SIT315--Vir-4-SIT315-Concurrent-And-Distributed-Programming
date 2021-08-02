//C++ CODE 

//Pins Used for sensor and led 
int SENSOR_PIN = 2;
int LED_PIN = 13;

int motion = 0;

//Initialising the setup 
void setup()
{
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
}

//DETECTING THE MOTION 
void loop()
{
  
  motion = digitalRead(SENSOR_PIN);
  
  if(motion == HIGH)
  {
    digitalWrite(LED_PIN,HIGH);
    Serial.println("There is a Motion, Turning on the LED");
    
    delay(2000);
  }
  else
  {
    digitalWrite(LED_PIN,LOW);
    Serial.println("There is no motion,Turning off the LED");
    
    delay(2000);
  }
  
}
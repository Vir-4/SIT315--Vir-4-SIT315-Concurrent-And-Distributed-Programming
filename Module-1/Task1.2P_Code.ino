// Module-1 (Task 1.2P)

// C++ code

// Pins
int const SENSOR_PIN = 2;
int const LED_PIN = 13;

volatile int STATE;

// Setup
void setup()
{
  pinMode(SENSOR_PIN,INPUT); 	
  pinMode(LED_PIN, OUTPUT);		
  
  Serial.begin(9600); 
  
  //Interrupt
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN),toggle,CHANGE);
}

// Adding delay
void loop()
{
  delay(100);
}

//Interrupt function
void toggle()
{
  STATE = digitalRead(SENSOR_PIN); 	
  digitalWrite(LED_PIN,STATE);
  
  if (STATE == 1)                 
  {
    Serial.print(STATE);
    Serial.print("There is a motion, Turning ON the LED");
  }
   else
   {
     Serial.print(STATE);
     Serial.print("There is NO motion, Turning OFF the LED");
   }
}
// Module-1 (Task 1.3C)

// C++ code

int reading=0;

// LED Pins
const uint8_t LED_PIN1 = 13;
const uint8_t LED_PIN2 = 8;

// SENSOR pins 
const uint8_t SENSOR_PIN1 = 2;
const uint8_t SENSOR_PIN2 = 3;


// Setup
void setup()
{
  // Sensor Inputs
  pinMode(SENSOR_PIN1,INPUT); 
  pinMode(SENSOR_PIN2,INPUT);
  
  // Sensor Outputs
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);
  
  Serial.begin(9600); 
  
  //Interrupts
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN1),toggle1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN2),toggle2 ,CHANGE);
}

// Adding delay
void loop()
{
  delay(100);
}

//Interrupt function1
void toggle1()
{
  reading = digitalRead(SENSOR_PIN1); 
  
  Serial.println("Motion Detected - SENSOR 1");
  
  if(reading == HIGH)
  {
    digitalWrite(LED_PIN1, HIGH);  	
  }
  else
  {
    digitalWrite(LED_PIN1, LOW);
  }
}

//Interrupt function2
void toggle2()
{
  reading = digitalRead(SENSOR_PIN2); 
  
  Serial.println("Motion Detected - SENSOR 2");
  
  if(reading == HIGH)
  {
    digitalWrite(LED_PIN2, HIGH);  	
  }
  else
  {
    digitalWrite(LED_PIN2, LOW);
  }
}


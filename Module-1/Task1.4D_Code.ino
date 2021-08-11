// Module - 1(Task 1.4D)

// C++ Code 

// LED Pins 
const uint8_t LED1 = 8;
const uint8_t LED2 = 10;
const uint8_t LED3 = 12;

const byte TimerLED = 13;

// SENSOR PINS 
const uint8_t PIR1 = 2;
const uint8_t PIR2 = 3;
const uint8_t PIR3 = 4;

// LED PINS FOR INTERUPTS 
volatile byte Led1 = 0;
volatile byte Led2 = 0;
volatile byte Led3 = 0;

// SETTING UP DIFFERENT INPUTS AND OUTPUTS 
void setup()
{
    pinMode(TimerLED, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    
    pinMode(PIR1, INPUT);
    pinMode(PIR2, INPUT);
    pinMode(PIR3, INPUT);

    Serial.begin(9600);

    // TURNING ON D PORT
    PCICR |= 0b00000100; 
    // ACTIVATING THE SENSOR PINS 
    PCMSK2 |= 0b00011100;

  // STARING THE TIMER 
    startTimer(); 
}

void loop()
{
    digitalWrite(LED1, Led1);
    digitalWrite(LED2, Led2);
    digitalWrite(LED3, Led3);
}

void startTimer(){
  
  // STOPPING THE INTERUPTS
  noInterrupts();
  
  // CLEARING THE REGISTERS 
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  
  // TIMERLED BLINKING EVERY 2 SECONDS  
  
  OCR1A = 31249; 
  TCCR1B |= (1 << WGM12);
  
  // SETTING UP BITS FOR 1024 PRESCALER
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10);
  
  // ENABLE TIMER AND COMPARE INTERUPTS
  TIMSK1 |= (1 << OCIE1A);
  
  // ALLOWING INTERUPTS
  interrupts();
}

ISR(PCINT2_vect) 
{
    Led1 = PIND & B00000100;
    Led2 = PIND & B00001000;
    Led3 = PIND & B00010000;
  
    if (Led1)
    {
        Serial.println("DETECTED MOTION IN PIR1");
    }
    if (Led2)
    {
        Serial.println("DETECTED MOTION IN PIR2");
    }
    if (Led3)
    {
        Serial.println("DETECTED MOTION IN PIR3");
    }
    
}

// TIMER INTERUPTS

ISR(TIMER1_COMPA_vect)
{
  // BLINKING THE TIMERLED AT 500MS INTERVALS 
    digitalWrite(TimerLED, digitalRead(TimerLED) ^ 1);
  
    Serial.print("TIMER:");
    Serial.println(digitalRead(TimerLED));
}
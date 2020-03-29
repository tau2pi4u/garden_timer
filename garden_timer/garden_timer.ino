// Quick timer program written to help in a home
// irrigation scheme to check that everything is 
// still alive
// Author: William Thomas (tau2pi4u)
// If for some strange reason someone wants to extend
// this or use it for something else, just give me 
// credit
// Mess about with this define to change the time
// period before it times out
#define TIMEOUT_PERIOD 1000 // Timeout period in seconds
#define INPUT_PINS {0, 1, 2, 3, 4, 5, 6, 7}
#define OUTPUT_PINS {8, 9, 10, 11, 12, A0, A1, A2}

// Leave these alone
#define TIMEOUT_PERIOD_MS TIMEOUT_PERIOD * 1000
#define ACTIVE_SIGNAL HIGH
#if (ACTIVE_SIGNAL == HIGH)
#define INACTIVE_SIGNAL LOW
#else
#define INACTIVE_SIGNAL HIGH
#endif

const int input_pins[8] = INPUT_PINS;
const int output_pins[8] = OUTPUT_PINS; 
unsigned long lastSeen[8];

void setup() {
  // put your setup code here, to run once:
  for(unsigned int i = 0; i < 8; i++)
  {
    pinMode(input_pins[i], INPUT);
    pinMode(output_pins[i], OUTPUT);
    digitalWrite(output_pins[i], ACTIVE_SIGNAL);
    lastSeen[i] = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(unsigned int i = 0; i < 8; i++)
  {
    if(digitalRead(input_pins[i]) == ACTIVE_SIGNAL)
    {
      lastSeen[i] = millis();
      digitalWrite(output_pins[i], ACTIVE_SIGNAL);
    }
    else if(lastSeen[i] + TIMEOUT_PERIOD_MS < millis())
    {
      digitalWrite(output_pins[i], INACTIVE_SIGNAL);
    }
  }
}

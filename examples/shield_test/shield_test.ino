/*
 * shield_test.ino
 * Tests and demonstrates all of the shield functions work and how to use them.
 * This is used for factory test and can be used both as a learning and
 * troubleshooting resource!
 * 
 * IMPORTANT - For this to work properly, set the line ending in the serial monitor
 * to be "Newline"
 */

#include <lglearning.h>
 
void setup()
{
  // Setup the pin modes
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);;
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_SWITCH_A, INPUT);
  pinMode(PIN_SWITCH_B, INPUT);
  pinMode(PIN_SWITCH_C, INPUT);
  pinMode(PIN_SWITCH_D, INPUT);

  // Start a serial connection
  Serial.begin(115200);
}

void waitForEnter(void)
{
  // Waits to receive a line ending
  while(1)
  {
    if(Serial.read() != -1)
    {
      Serial.read();
      break;
    }
  }
}

void testLEDS(void)
{
  // Check that each LED works and is the correct color
  Serial.println("Press enter if blue LED is on.");
  digitalWrite(PIN_LED_BLUE, HIGH);
  waitForEnter();
  digitalWrite(PIN_LED_BLUE, LOW);

  Serial.println("Press enter if red LED is on.");
  digitalWrite(PIN_LED_RED, HIGH);
  waitForEnter();
  digitalWrite(PIN_LED_RED, LOW);

  Serial.println("Press enter if yellow LED is on.");
  digitalWrite(PIN_LED_YELLOW, HIGH);
  waitForEnter();
  digitalWrite(PIN_LED_YELLOW, LOW);

  Serial.println("Press enter if green LED is on.");
  digitalWrite(PIN_LED_GREEN, HIGH);
  waitForEnter();
  digitalWrite(PIN_LED_GREEN, LOW);
}


void testTemperature(void)
{
  // See if the temperature sensor reads a reasonable value.
  Serial.println("Check that the temperatures below seem reasonable (degC). Press enter to continue.");
  for(int i=0; i<5; i++)
  {
    Serial.println(readTemperatureCelsius());
  }
  waitForEnter();
}


void testBuzzer(void)
{
  // Play a little song on the buzzer
  Serial.println("Verify that the buzzer plays a song. Press enter to continue.");
  int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

  int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
  };

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIN_BUZZER, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN_BUZZER);
  }
  waitForEnter(); 
}


void testKnob(void)
{
  // Check that the potentiometer works
  Serial.println("Turn the knob and verify that the numbers change 0-1023. Press enter to exit.");
  delay(3000);
  while(1)
  {
    delay(100);
    Serial.println(analogRead(PIN_POT));
    if(Serial.read() != -1)
    {
      Serial.read();
      break;
    }
  }
}


void testLight(void)
{
  // Verify that the light sensor works properly.
  Serial.println("Cover/uncover the light sensor and verify that the numbers change. Press enter to exit.");
  delay(3000);
  while(1)
  {
    delay(100);
    Serial.println(analogRead(PIN_LIGHT_SENSOR));
    if(Serial.read() != -1)
    {
      Serial.read();
      break;
    }
  }
}


void testButtons(void)
{
  // Verify that the buttons work
  Serial.println("Press buttons and verify LED by them comes on. Press enter when done with all four buttons.");
  while(1)
  {
    // Switch A
    if (digitalRead(PIN_SWITCH_A))
    {
      digitalWrite(PIN_LED_GREEN, HIGH);  
    }
    else
    {
      digitalWrite(PIN_LED_GREEN, LOW);
    }

    // Switch B
    if (digitalRead(PIN_SWITCH_B))
    {
      digitalWrite(PIN_LED_RED, HIGH);  
    }
    else
    {
      digitalWrite(PIN_LED_RED, LOW);
    }

    // Switch C
    if (digitalRead(PIN_SWITCH_C))
    {
      digitalWrite(PIN_LED_BLUE, HIGH);  
    }
    else
    {
      digitalWrite(PIN_LED_BLUE, LOW);
    }

    // Switch D
    if (digitalRead(PIN_SWITCH_D))
    {
      digitalWrite(PIN_LED_YELLOW, HIGH);  
    }
    else
    {
      digitalWrite(PIN_LED_YELLOW, LOW);
    }

    if(Serial.read() != -1)
    {
      Serial.read();
      break;
    }
  }
}

void loop()
{
  // Run through the tests forever!
  testLEDS();
  testTemperature();
  testBuzzer();
  testKnob();
  testLight();
  testButtons();
  Serial.println("Complete! Starting again!");
}

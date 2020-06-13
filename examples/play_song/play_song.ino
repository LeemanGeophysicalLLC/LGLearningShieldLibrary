/*
 * play_song.ino
 * Plays a song to demonstrate using the buzzer
 */

#include <lglearning.h>

void setup()
{
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop()
{
  // Setup the notes of the melody
  int melody[] = {
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_B4,
  0, NOTE_G4, NOTE_A4, NOTE_AS4,
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, 0, NOTE_B3, NOTE_C4,
  NOTE_D4, 0, NOTE_E4, NOTE_DS4,
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_E4,
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_CS4,
  NOTE_D4, 0, NOTE_G3, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_C4,
  NOTE_B3, NOTE_D4, NOTE_C4, NOTE_B3
  };

  int noteDurations[] = {
  8, 8, 8, 4,
  4, 4, 4, 2,
  8, 8, 8, 8,
  4, 4, 4, 4,
  2, 8, 8, 8,
  8, 8, 4, 8, 
  8, 8, 8, 8, 
  8, 8, 8, 8,
  4, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  };
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 48; thisNote++)
  {
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
}

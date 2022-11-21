//#include <stdio.h>
#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "buzzer_tone.h"
#include "state_machines.h"

// SWITCH 1 Majora Mask Healing of Song by Koji Kondo
void play_song_1()
{
  static char curr_note = 0;
  int notes[25] = {B4,B4,A4,A4,F4,F4,B4,B4,A4,A4,F4,F4,B4,B4,A4,A4,E4,D4,E4,E4,E4,E4,E4,E4,0};
  int n = 25;
  int s = 1;

  if (curr_note < n)
    {
      if(notes[curr_note] != notes[(curr_note - 1)])
	{
	  swap_leds(s);
	  
	}
      else
	{
	  swap_leds(s-1);
	}
      
      curr_note++;
    }
  else
    {
	  curr_note = 0;
    }
}

// SWITCH 2
void play_song_2()
{
  static char curr_note = 0;
  int notes[15] = {G4_SHARP, G4_SHARP, 0, B4, B4, 0, A4_SHARP, A4_SHARP, A4_SHARP, A4, 0, E4, 0, D4_SHARP, 0};
  int n = 15;

  if (curr_note < n){
    buzzer_set_period(notes[curr_note]);
    curr_note++;
  }
  else{                         // LOOP SONG
    curr_note = 0;
    
  }
}

// SWITCH 3
void play_song_3()
{
  static char curr_note = 0;

  switch(curr_note){
  case 0:
    buzzer_set_period(C6_SHARP);
    swap_leds(1);
    curr_note++;
    break;
  case 1:
    buzzer_set_period(F6_SHARP);
    swap_leds(0);
    curr_note++;
    break;
  case 2:
    buzzer_set_period(G6_SHARP);
    swap_leds(1);
    curr_note++;
    break;
  case 3:
    buzzer_set_period(A6);
    swap_leds(0);
    curr_note++;
    break;
  case 5:
    buzzer_set_period(C6_SHARP);
    swap_leds(1);
    curr_note++;
    break;
  case 7:
    buzzer_set_period(F6_SHARP);
    swap_leds(0);
    curr_note++;
    break;
  case 8:
    buzzer_set_period(G6_SHARP);
    swap_leds(1);
    curr_note++;
    break;
  case 10:
    buzzer_set_period(A6);
    swap_leds(0);
    curr_note++;
    break;
  case 14:
    buzzer_set_period(D6);
    swap_leds(1);
    curr_note++;
    break;
  case 15:
    buzzer_set_period(F6_SHARP);
    swap_leds(0);
    curr_note++;
    break;
  case 16:
    buzzer_set_period(G6_SHARP);
    swap_leds(1);
    curr_note++;
    break;
  case 18:
    buzzer_set_period(D6);
    swap_leds(0);
    curr_note++;
    break;
  case 20:
    buzzer_set_period(F6_SHARP);
    swap_leds(1);
    curr_note++;
    break;
  case 21:
    buzzer_set_period(G6_SHARP);
    swap_leds(0);
    curr_note++;
    break;
  case 22:
    buzzer_set_period(A6);
    swap_leds(1);
    curr_note++;
    break;
  case 26:                              // LOOP BACK TO BEGINNING
    buzzer_set_period(0);
    leds_on(0);
    curr_note = 0;
    break;
  default:
    curr_note++;
    break;
  }
}

// SWITCH 4 
void play_off()
{
  buzzer_set_period(0);
  leds_on(0);
  static char curr_note =0;
}
  

#include "out.h"
#include <PCM.h>

#define IN 7

bool is_playing = false;

void setup() {
  pinMode(IN, INPUT_PULLUP);
}

void loop() {
  auto val = digitalRead(IN);

  if (val == LOW && !is_playing) {
    is_playing = true;

    play_audio();
  } else if (val == HIGH && is_playing) {
    is_playing = false;
  }
}

void play_audio() {
  startPlayback(samples, sizeof(samples));
}
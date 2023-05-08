#ifndef Voice_h
#define Voice_h

#include "Patch.h"
#include <Arduino.h>

enum VoiceStatus { voice_off, voice_held, voice_decay };

class Voice {
public:
  Voice();
  void setPatch(const Patch *patch);
  void noteOn(byte _channel, byte _pitch, byte velocity);
  void noteOff();
  void tick();
  VoiceStatus getStatus();

  // state management
  uint16_t frequency_cents;
  byte level;
  byte pitch;
  byte channel;

private:
  PatchState _patch_state;
  bool _on;
  bool _held;
};

#endif

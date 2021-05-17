#ifndef _SMS_H
#define _SMS_H

#include "../dispatch.h"
#include "../macroInt.h"
#include "sound/sn76496.h"

class DivPlatformSMS: public DivDispatch {
  struct Channel {
    int freq, baseFreq, pitch;
    unsigned char ins, note;
    bool active, insChanged, freqChanged, keyOn, keyOff;
    signed char vol;
    DivMacroInt std;
    Channel(): freq(0), baseFreq(0), pitch(0), ins(0), note(0), active(false), insChanged(true), freqChanged(false), keyOn(false), keyOff(false), vol(15) {}
  };
  Channel chan[4];
  unsigned char snNoiseMode;
  bool updateSNMode;
  sn76496_device* sn;
  public:
    void acquire(int& l, int& r);
    int dispatch(DivCommand c);
    void tick();
    int init(DivEngine* parent, int channels, int sugRate);
};

#endif
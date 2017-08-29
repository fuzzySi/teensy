/*
 * teensyduino program to play a Shepard-Risset tone - this is a slowly rising glissando which fades in gently & out again, so it always sounds like it's ascending
 * also known as the 'barber-pole' illusion. 
 * 
 */

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthToneSweep      tonesweep1;     //xy=149,604
AudioSynthToneSweep      tonesweep4;     //xy=150,733
AudioSynthToneSweep      tonesweep3;     //xy=151,690
AudioSynthToneSweep      tonesweep5;     //xy=152,888
AudioSynthToneSweep      tonesweep2;     //xy=153,647
AudioSynthToneSweep      tonesweep7;     //xy=158,989
AudioSynthWaveformSine   sine1;          //xy=169,494
AudioSynthToneSweep      tonesweep8;     //xy=175,1041
AudioOutputAnalog        dac1;           //xy=183,268
AudioSynthToneSweep      tonesweep6;     //xy=183,932
AudioOutputAnalogStereo  dacs1;          //xy=191,359
AudioEffectFade          fade1;          //xy=335,604
AudioEffectFade          fade7;          //xy=335,993
AudioEffectFade          fade2;          //xy=338,653
AudioEffectFade          fade3;          //xy=352,701
AudioEffectFade          fade6;          //xy=353,941
AudioEffectFade          fade5;          //xy=354,900
AudioEffectFade          fade4;          //xy=355,743
AudioEffectFade          fade8;          //xy=368,1043
AudioMixer4              mixer1;         //xy=547,669
AudioMixer4              mixer2;         //xy=555,939
AudioOutputI2S           i2s1;           //xy=740,823
AudioConnection          patchCord1(tonesweep1, fade1);
AudioConnection          patchCord2(tonesweep4, fade4);
AudioConnection          patchCord3(tonesweep3, fade3);
AudioConnection          patchCord4(tonesweep5, fade5);
AudioConnection          patchCord5(tonesweep2, fade2);
AudioConnection          patchCord6(tonesweep7, fade7);
AudioConnection          patchCord7(tonesweep8, fade8);
AudioConnection          patchCord8(tonesweep6, fade6);
AudioConnection          patchCord9(fade1, 0, mixer1, 0);
AudioConnection          patchCord10(fade7, 0, mixer2, 2);
AudioConnection          patchCord11(fade2, 0, mixer1, 1);
AudioConnection          patchCord12(fade3, 0, mixer1, 2);
AudioConnection          patchCord13(fade6, 0, mixer2, 1);
AudioConnection          patchCord14(fade5, 0, mixer2, 0);
AudioConnection          patchCord15(fade4, 0, mixer1, 3);
AudioConnection          patchCord16(fade8, 0, mixer2, 3);
AudioConnection          patchCord17(mixer1, 0, i2s1, 0);
AudioConnection          patchCord18(mixer2, 0, i2s1, 1);

// GUItool: end automatically generated code

AudioControlSGTL5000 audioShield;

float toneVol = 0.2;
int startFreq = 440;
int endFreq = 880; // swap these to go down
int riseTime = 5;  // actually in secs
int ribbons = 8; // number of tones
int fadeTime = riseTime * 1000 / ribbons * 2; // * 2 is kludge as sounds better

void setup() {
  AudioMemory(8);
  audioShield.enable();
  audioShield.volume(0.45);

}

void loop() {

  fade2.fadeOut(fadeTime);
  fade1.fadeIn(fadeTime);
  tonesweep1.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

  fade6.fadeOut(fadeTime);
  fade5.fadeIn(fadeTime);
  tonesweep5.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

  fade3.fadeOut(fadeTime);
  fade2.fadeIn(fadeTime);
  tonesweep2.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

  fade7.fadeOut(fadeTime);
  fade6.fadeIn(fadeTime);
  tonesweep6.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

  fade4.fadeOut(fadeTime);
  fade3.fadeIn(fadeTime);
  tonesweep3.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

  fade8.fadeOut(fadeTime);
  fade7.fadeIn(fadeTime);
  tonesweep7.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

  fade1.fadeOut(fadeTime);
  fade4.fadeIn(fadeTime);
  tonesweep4.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

  fade5.fadeOut(fadeTime);
  fade8.fadeIn(fadeTime);
  tonesweep8.play(toneVol, startFreq, endFreq, riseTime);
  delay(riseTime * 1000 / ribbons);

}

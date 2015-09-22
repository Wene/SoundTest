#include "tone.h"
#include "Arduino.h"

Tone::Tone(int p)
{
    pin = p;
    pinMode(pin, OUTPUT);
    pinMode(4, OUTPUT);
    isHigh = false;
}

void Tone::setTone(unsigned int freq)
{
    frequency = freq;
    delayTime = (1e6 / 2) / freq; //half wave length because one wave is half time high and half time low
    lastTime = micros();
    startTime = lastTime;
}

void Tone::play()
{
    unsigned long now = micros();
    if(now > lastTime + delayTime)
    {
        if(isHigh)
        {
            isHigh = false;
            digitalWrite(pin, LOW);
        }
        else
        {
            isHigh = true;
            digitalWrite(pin, HIGH);
        }
        lastTime = now;
    }

}

void Tone::stop()
{
    digitalWrite(pin, LOW);
    isHigh = false;
}

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
}

void Tone::play()
{
    unsigned long now = micros();
    if(now < 1e6)                   //because of the 2 second delay at start, this must be an overflow of micros()
    {
        digitalWrite(13, HIGH);     //LED on to indicate detected overflow
        if(lastTime > now)          //only corect if necessary
        {
            lastTime = 0;
        }
    }
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

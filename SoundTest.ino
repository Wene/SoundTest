#define DEBUG 13
#include "tone.h"

Tone t1(6);
Tone t2(7);
unsigned long time = 0;
unsigned long now = 0;
int pos = 0;

void setup()
{
    pinMode(DEBUG, OUTPUT);
    digitalWrite(DEBUG, HIGH);
    delay(2000);
    digitalWrite(DEBUG, LOW);
    time = millis();
}

void loop()
{
    now = millis();
    if(now < 1000)                  //Must be an overflow of millis(). The 2 sec delay at start leads to over 2000.
    {
        if(time > now)              //only corect if necessary
        {
            time = 0;
        }
    }
    switch(pos)                     //loop trough the melody
    {
    case 0:
        t1.setTone(Tone::c3);
        t2.setTone(Tone::e1);
        pos++;
        break;
    case 1:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
        }
        break;
    case 2:
        t2.play();
        if(now > time + 100)
        {
            pos++;
            time = millis();
            t1.setTone(Tone::d3);
        }
        break;
    case 3:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
            t2.stop();
            t2.setTone(Tone::c1);
        }
        break;
    case 4:
        t2.play();
        if(now > time + 100)
        {
            pos++;
            time = millis();
            t1.setTone(Tone::e3);
        }
        break;
    case 5:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
        }
        break;
    case 6:
        t2.play();
        if(now > time + 100)
        {
            pos++;
            time = millis();
            t1.setTone(Tone::f3);
        }
        break;
    case 7:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
            t2.stop();
            t2.setTone(Tone::d1);
        }
        break;
    case 8:
        t2.play();
        if(now > time + 100)
        {
            pos++;
            time = millis();
            t1.setTone(Tone::g3);
        }
        break;
    case 9:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
        }
        break;
    case 10:
        t2.play();
        if(now > time + 100)
        {
            pos++;
            time = millis();
            t1.setTone(Tone::a3);
        }
        break;
    case 11:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
        }
        break;
    case 12:
        t2.play();
        if(now > time + 100)
        {
            pos++;
            time = millis();
            t1.setTone(Tone::h3);
        }
        break;
    case 13:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
        }
        break;
    case 14:
        t2.play();
        if(now > time + 100)
        {
            pos++;
            time = millis();
            t1.setTone(Tone::c4);
        }
        break;
    case 15:
        t1.play();
        t2.play();
        if(now > time + 500)
        {
            pos++;
            time = millis();
            t1.stop();
            t2.stop();
        }
        break;
    case 16:
        if(now > time + 1000)
        {
            pos=0;
            time = millis();
        }
        break;
    }
}




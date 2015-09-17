#define DEBUG 13
#include "tone.h"

void setup()
{
    pinMode(DEBUG, OUTPUT);
    digitalWrite(DEBUG, HIGH);
    delay(2000);
    digitalWrite(DEBUG, LOW);
}

Tone t1(6);
Tone t2(4);
Tone t3(9);

void loop()
{
    unsigned long time = millis();
    digitalWrite(DEBUG, HIGH);
    t1.setTone(400, 7e6);
    t2.setTone(800, 5e6);
    t3.setTone(50, 8e6);
    while(time + 9000 > millis())
    {
        t1.play();
        t2.play();
        t3.play();
    }
    digitalWrite(DEBUG, LOW);
    delay(1000);
}




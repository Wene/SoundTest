
#define DEBUG 13

//TODO: this class actually ignores overflows of long's. 
class Tone
{
private:
    unsigned long frequency;
    unsigned long playTime;
    unsigned long delayTime;
    unsigned long lastTime;
    unsigned long startTime;
    bool isHigh;
    int pin;
    
public:
    Tone(int p)
    {
        pin = p;
        pinMode(pin, OUTPUT);
        pinMode(4, OUTPUT);
        isHigh = false;
    }

    void setTone(unsigned int freq, unsigned long time)
    {
        frequency = freq;
        playTime = time;
        delayTime = (1e6 / 2) / freq; //half wave length because one wave is half time high and half time low
        lastTime = micros();
        startTime = lastTime;
    }

    void play()
    {
        unsigned long now = micros();
        if(now < startTime + playTime)
        {       
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
        else    //not playing - time is out
        {
            digitalWrite(pin, LOW);
            isHigh = false;
        }
    }
};


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




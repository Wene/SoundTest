
//TODO: this class actually ignores overflows of long's.
class Tone
{
private:
    unsigned long frequency;
    unsigned long delayTime;
    unsigned long lastTime;
    bool isHigh;
    int pin;

public:
    Tone(int p);
    void setTone(unsigned int freq);
    void play();
    void stop();
    enum note{c1=131, d1=147, e1=165, f1=175, g1=196, a1=220, h1=247, c2=262, d2=294, e2=330, f2=350, g2=392, a2=440, h2=494,
              c3=523, d3=587, e3=659, f3=699, g3=784, a3=880, h3=988, c4=1047, d4=1175, e4=1319, f4=1397, g4=1568, a4=1760, h4=1976};
};

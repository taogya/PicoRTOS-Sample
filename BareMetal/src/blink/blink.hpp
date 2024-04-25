#ifndef __BLINK_BLINK_HPP__
#define __BLINK_BLINK_HPP__

class Blink
{
private:
    int pin;

public:
    Blink() {}
    Blink(int pin);
    void toggle();
};

#endif // __BLINK_BLINK_HPP__
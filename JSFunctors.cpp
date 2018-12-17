#include "JSFunctors.h"

XAxisFunctor::XAxisFunctor(Joystick_ *joystick)
{
    _joystick = joystick;
}
void XAxisFunctor::setValue(int16_t newValue)
{
    _joystick->setXAxis(newValue);
}

YAxisFunctor::YAxisFunctor(Joystick_ *joystick)
{
    _joystick = joystick;
}
void YAxisFunctor::setValue(int16_t newValue)
{
    _joystick->setYAxis(newValue);
}

ZAxisFunctor::ZAxisFunctor(Joystick_ *joystick)
{
    _joystick = joystick;
}
void ZAxisFunctor::setValue(int16_t newValue)
{
    _joystick->setZAxis(newValue);
}

RudderAxisFunctor::RudderAxisFunctor(Joystick_ *joystick)
{
    _joystick = joystick;
}
void RudderAxisFunctor::setValue(int16_t newValue)
{
    _joystick->setRudder(newValue);
}

ThrottleAxisFunctor::ThrottleAxisFunctor(Joystick_ *joystick)
{
    _joystick = joystick;
}
void ThrottleAxisFunctor::setValue(int16_t newValue)
{
    _joystick->setThrottle(newValue);
}

BrakeAxisFunctor::BrakeAxisFunctor(Joystick_ *joystick)
{
    _joystick = joystick;
}
void BrakeAxisFunctor::setValue(int16_t newValue)
{
    _joystick->setBrake(newValue);
}

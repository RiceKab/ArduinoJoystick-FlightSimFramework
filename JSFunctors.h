/**
  * JSFunctors.h - Collection of functors to drive the axis for JFSF.
  * Created on 2018/12/13 by Kevin Chi Yan Tang.
  * Released under the MIT License.
  */
#ifndef JSFunctors_h
#define JSFunctors_h

#include "Joystick.h"

class AbstractAxisFunctor
{
  public:
    virtual void setValue(int16_t newValue);
};

class XAxisFunctor : public AbstractAxisFunctor
{
  public:
    XAxisFunctor(Joystick_ *joystick);
    void setValue(int16_t newValue);

  private:
    Joystick_ *_joystick;
};

class YAxisFunctor : public AbstractAxisFunctor
{
  public:
    YAxisFunctor(Joystick_ *joystick);
    void setValue(int16_t newValue);

  private:
    Joystick_ *_joystick;
};

class ZAxisFunctor : public AbstractAxisFunctor
{
  public:
    ZAxisFunctor(Joystick_ *joystick);
    void setValue(int16_t newValue);

  private:
    Joystick_ *_joystick;
};

class RudderAxisFunctor : public AbstractAxisFunctor
{
  public:
    RudderAxisFunctor(Joystick_ *joystick);
    void setValue(int16_t newValue);

  private:
    Joystick_ *_joystick;
};

class ThrottleAxisFunctor : public AbstractAxisFunctor
{
  public:
    ThrottleAxisFunctor(Joystick_ *joystick);
    void setValue(int16_t newValue);

  private:
    Joystick_ *_joystick;
};

class BrakeAxisFunctor : public AbstractAxisFunctor
{
  public:
    BrakeAxisFunctor(Joystick_ *joystick);
    void setValue(int16_t newValue);

  private:
    Joystick_ *_joystick;
};

#endif
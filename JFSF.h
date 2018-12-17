/**
  * JFSF.h - Library for handling Joystick input.
  * Created on 2018/12/09 by Kevin Chi Yan Tang.
  * Released under the MIT License.
  */
#ifndef JFSF_h
#define JFSF_h

#include "Arduino.h"
#include "Joystick.h"
#include "JSFunctors.h"

#define MAX_ACTIONS 128

class AbstractAction
{
public:
  virtual void loop();
};

/* A Switch holds a button pressed and releases  when turned off. Essentially acts as a push button. */
class SwitchHold : public AbstractAction
{
public:
  SwitchHold(Joystick_ *joystick, int pin, int btnIndex);
  void loop();

private:
  Joystick_ *_joystick;
  int _pin;
  int _btnIndex;
};

/* A Switch that sends a press when switched on and again when switched off. This is the most common use for a toggle switch.
   The on and off button indexes can be the same, eg. if a single button is used as for a toggle action. */
class SwitchPress : public AbstractAction
{
public:
  SwitchPress(Joystick_ *joystick, int pin, int btnIndexOn, int btnIndexOff);
  void loop();

private:
  Joystick_ *_joystick;
  int _pin;
  int _currentState;
  int _btnIndexOn;
  int _btnIndexOff;
};

/* A mapping of an analog input to an axis output. */
class AnalogAxisAction : public AbstractAction
{
public:
  AnalogAxisAction(AbstractAxisFunctor *axisFunctor, int analogPin, double valueFactor, int minClampValue, int maxClampValue);
  void loop();

private:
  AbstractAxisFunctor *_axisFunctor;
  int _analogPin;
  double _valueFactor;
  int _minClampValue;
  int _maxClampValue;
};

class JFSF
{
public:
  JFSF(Joystick_ *joystick, bool doSendState); // doSendState should be true if Joystick_ does not auto send state.
  void loop();
  void addAction(AbstractAction *action);

private:
  Joystick_ *_joystick;
  AbstractAction *_actions[MAX_ACTIONS];
  int _nextActionIndex;
  bool _doSendState;
};

#endif
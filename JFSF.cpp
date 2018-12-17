#include "JFSF.h"

#define PRESSED 1
#define RELEASED 0

SwitchHold::SwitchHold(Joystick_ *joystick, int pin, int btnIndex)
{
    _joystick = joystick;
    _pin = pin;
    _btnIndex = btnIndex;
    pinMode(_pin, INPUT_PULLUP);
}

void SwitchHold::loop()
{
    int _state = digitalRead(_pin) == LOW ? PRESSED : RELEASED;
    _joystick->setButton(_btnIndex, _state);
}

SwitchPress::SwitchPress(Joystick_ *joystick, int pin, int btnIndexOn, int btnIndexOff)
{
    _joystick = joystick;
    _pin = pin;
    _btnIndexOn = btnIndexOn;
    _btnIndexOff = btnIndexOff;
    pinMode(_pin, INPUT_PULLUP);
    _currentState = digitalRead(_pin);
}

void SwitchPress::loop()
{
    int newState = digitalRead(_pin);
    if (newState != _currentState)
    {
        if (newState == LOW)
        {
            _joystick->pressButton(_btnIndexOn);
        }
        else
        {
            _joystick->pressButton(_btnIndexOff);
        }
        _currentState = newState;
    }
    else
    {
        _joystick->releaseButton(_btnIndexOn);
        _joystick->releaseButton(_btnIndexOff);
    }
}

AnalogAxisAction::AnalogAxisAction(AbstractAxisFunctor *axisFunctor, int analogPin, double valueFactor = 1.0, int minClampValue = 0, int maxClampValue = 1023)
{
    _axisFunctor = axisFunctor;
    _analogPin = analogPin;
    _valueFactor = valueFactor;
    _minClampValue = minClampValue;
    _maxClampValue = maxClampValue;
    pinMode(_analogPin, INPUT);
}

void AnalogAxisAction::loop()
{
    int _newValue = analogRead(_analogPin) * _valueFactor;
    _newValue = constrain(_newValue, _minClampValue, _maxClampValue);
    _axisFunctor->setValue(_newValue);
}

JFSF::JFSF(Joystick_ *joystick, bool doSendState)
{
    _joystick = joystick;
    _nextActionIndex = 0;
    _doSendState = doSendState;
}

void JFSF::addAction(AbstractAction *action)
{
    _actions[_nextActionIndex++] = action;
}

void JFSF::loop()
{
    for (int n = 0; n < _nextActionIndex; n++)
    {
        if (_actions[n])
        {
            _actions[n]->loop();
        }
    }
    if (_doSendState)
    {
        _joystick->sendState();
    }
}
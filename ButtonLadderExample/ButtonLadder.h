/*
 * ButtonLadder.h
 *
 *  Created on: Mar 3, 2020
 *      Author: musicrizz
 *     Copyright (C) 2020 Giovanni Grandinetti <grandinetti.giovanni13@gmail.com>
 *
 */
struct ButtonLadder {
  private:
    short analogPin        = -1;
    int   state            = -1;
    int   lastState        = -1;
    int   value            = -1;
    void  (*pfunction)(int) = 0;

    unsigned long debounceDelay = 10;
    unsigned long lastDebounceTime = 0;

    bool not_Eq(int a, int b)  {
        if(abs(a-b) < 15) return false;
        return true;
    }

  public:
  
    ButtonLadder(short pin, void (*function)(int))  {
      analogPin   = pin;
      pfunction   = function;
      state       = -1;
      lastState   = -1;
      value       = -1;
      debounceDelay = 10;
      lastDebounceTime = 0;
    }

    ButtonLadder(const ButtonLadder& b)  {
      analogPin  = b.analogPin;
      state      = b.state;
      lastState  = b.lastState;
      value      = b.value;
      pfunction  = b.pfunction;
      debounceDelay    = b.debounceDelay;
      lastDebounceTime = b.lastDebounceTime;
    }

    bool check()  {
      if (analogPin < 0 || pfunction == 0)  {
        return false;
      }

      value = analogRead(analogPin);

      if (not_Eq(value, lastState)) {
        lastDebounceTime = millis();
      }

      if ((millis() - lastDebounceTime) > debounceDelay) {
        if (not_Eq(value, state)) {
          state = value;

          if (state > 1) {
            (*pfunction)(value);
          }
        }
      }

      lastState = value;
      return true;
    }



    void setDebounceDelay(unsigned long d)   {
      debounceDelay = d;
    }

};

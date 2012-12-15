#include <iostream>
#include "State.h"

State::State() {
	_state = _iterate();
}

State::~State() {
}

int State::_iterate() {
    static int save_state = 0;
  save_state++;
  return save_state-1;
}

void State::addNext(int state, Edge &ed) {
	_next[state] = ed;
}

void State::setFinal(bool f) {
  _final = f;
}

bool State::isFinal() const {
  return _final;
}

int State::getName() const
{
  return _state;
}

char State::getChar()
{
  if (_final == false)
    return _next[getName() + 1].getChar();
  return '\0';
}

int	State::checkState(char letter)
{
  if (_next[getName() + 1].getChar() == letter)
    return 0;
  return -1;
}

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

std::list<int>&	State::closure()
{
  if (_closure.empty() == true)
    {
      _closure.push_back(getName());
      for (std::map<int, Edge>::const_iterator it = _next.begin();
	   it != _next.end(); ++it)
	_closure.push_back((*it).first);
    }
  return _closure;
}

int State::getStateNum(Edge e)
{
  for (std::map<int, Edge>::const_iterator it = _next.begin(); it != _next.end(); ++it)
    {
      if ((*it).second.getChar() ==  e.getChar())
	return (*it).first;
    }
  return 0;
}

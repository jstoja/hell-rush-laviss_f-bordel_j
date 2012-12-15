#include <iostream>
#include "FSA.h"

FSA::FSA() {
}

FSA::~FSA() {
}

void FSA::addState(State *st) {
	_states[st->getName()] = st;
}

void FSA::operator+=(State *s) {
  _states[s->getName()] = s;
}

void FSA::setInitial(int i) {
	_initial = i;
}

int FSA::checkState(Edge& c, int pos)
{
  return _states[pos]->checkState(c.getChar());
}

void FSA::displayState() {
  for (std::map<int, State*>::iterator it = _states.begin();
       it != _states.end(); ++it)
    {
      std::cout << (*it).second->getName() << ' ' << (*it).second->getChar() << std::endl;
    }
}

bool FSA::isFinalState(int statePos)
{
  return _states[statePos]->isFinal();
}

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

State *FSA::getInitial() {
  if (_states.size() == 0)
    return new State();
  return _states[_initial];
}

int FSA::checkState(Edge& c, int pos)
{
  if (pos < _states.size())
    return _states[pos]->checkState(c.getChar());
  return -1;
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

void FSA::testClosure()
{
  for (std::map<int, State*>::const_iterator it = _states.begin();
       it != _states.end(); ++it)
    {
      std::list<int> cl = (*it).second->closure();
      for (std::list<int>::iterator it = cl.begin(); it != cl.end(); ++it)	
	std::cout << (*it) << ' ';
      std::cout << std::endl;
    }
}

int FSA::getStateNum(Edge e, int stateNum)
{
  return _states[stateNum]->getStateNum(e);
}

State *FSA::getStateByNum(int pos)
{
  return _states[pos];
}

std::list<int> FSA::closure(int pos)
{
  if (pos < _states.size())
    return _states[pos]->closure();
  return std::list<int>();
}

std::list<int> FSA::move(int pos)
{
  std::list<int> ret;
  if (pos <_states.size())
    {
      ret =  _states[pos]->closure();
      for (std::list<int>::iterator it = ret.begin(); it != ret.end(); ++it)
	tmp.push_back(*it);
      
    }
  return ret;
}

void FSA::testMove()
{
  std::list<int> test;

  test = move(0);
  for (std::list<int>::iterator it = test.begin(); it != test.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;
}




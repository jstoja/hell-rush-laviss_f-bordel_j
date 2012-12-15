#include <iostream>
#include "Edge.h"
#include "Matcher.h"

Matcher::Matcher(FSA &fsa) : _fsa(fsa) {
  _fsa.setInitial(0);
}

void Matcher::init(std::string &alpha) {
  static int stateNum = 0;
  int tmpStateNum = 0;

  for (size_t i = 0; i < alpha.size(); ++i)
    {      
      State *st;
      Edge e(alpha[i]);
      if (_fsa.checkState(e, tmpStateNum) == 0)
	{
	  while ((_fsa.checkState(e, tmpStateNum) == 0))
	    {
	      tmpStateNum = _fsa.getStateNum(e, tmpStateNum);
	      st = _fsa.getStateByNum(tmpStateNum);
	    } 
	  tmpStateNum = stateNum;
	}
      else
	{
	  if (i == 0)
	    {
	      st = _fsa.getInitial();
	      tmpStateNum = stateNum;
	    }
	  else
	    st = new State();
	}
      if (i < alpha.size())
	{
	  Edge *e = new Edge(alpha[i]);
	  if (i != alpha.size() - 1)
	    {
	      st->addNext(tmpStateNum + 1, *e);
	      tmpStateNum++;
	    }	
	}
      (i == alpha.size() - 1 ? st->setFinal(true) : st->setFinal(false));
      _fsa.addState(st);
    }
  if (tmpStateNum > stateNum)
    stateNum = tmpStateNum;
}

Matcher::~Matcher() {
}

bool Matcher::find(std::string &word) {
	int i = 0;
	find(word, i);
	if (i == 0)
		return false;
	else
		return true;
}

int find_position(char C, const std::string &word)
{
	int i = 0;
	while (i < word.size()) {
		if (word[i] == C)
			return i;
		++i;
	}
	return i;
}

bool Matcher::find(std::string &word, int &matchCount) {
  std::string arg = std::string(word);
  std::string token = std::string("");
  int i = 0;
  int statePos = 0;
  
  matchCount = 0;
  while (i < word.size())
    {
      Edge	letter(word[i]);
      if (_fsa.checkState(letter, statePos) == 0)
	{
	  token += letter.getChar();
	  if (_fsa.isFinalState(statePos) == true)
	    {
	      std::cout << "find token : " << token << std::endl;
	      matchCount++;
	      token.clear();
	      statePos = 0;
	    }
	  else
	    statePos++;
	}
      else
	{
	  token.clear();
	  statePos = 0;
	}      
      i++;
    }
  std::cout << "match count " << matchCount << std::endl;
  return true;
}

void	Matcher::testClosure()
{
  _fsa.testClosure();
}

void Matcher::testMove()
{
  _fsa.testMove();
}

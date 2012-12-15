#include <iostream>
#include "Edge.h"
#include "Matcher.h"

Matcher::Matcher(FSA &fsa) : _fsa(fsa) {
}

void Matcher::init(std::string &alpha)
{
    for (size_t i = 0; i < alpha.size(); ++i)
      {      
	State *st = new State();
	if (i < alpha.size())
	  {
	    Edge *e = new Edge(alpha[i]);
	    st->addNext(i + 1, *e);
	  }
	if (i == alpha.size() - 1)
	  st->setFinal(true);
	else
	  st->setFinal(false);
	_fsa.addState(st);
    }
    //_fsa.displayState();
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
			std::cout << "find token : " << token.c_str() << std::endl;
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

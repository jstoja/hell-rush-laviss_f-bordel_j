#include <iostream>
#include "FSA.h"
#include "Matcher.h"

void getAutomata(char *w, char **av, int argc) {
	std::string word(w);
	int count;
	FSA fsa = FSA();
	Matcher match(fsa);
	for (int i = 2; i < argc; ++i)
	  {
	    std::string alpha(av[i]);
	    match.init(alpha);
	  }
	match.testMove();
	//match.testClosure();
	match.find(word, count);
}

int main(int ac, char **av) {
	if (ac < 3)
		return -1;
	else {
	  getAutomata(av[1], av, ac);
	}
}

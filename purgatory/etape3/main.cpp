#include <iostream>
#include "FSA.h"
#include "Matcher.h"

void getAutomata(char *a, char *w) {
	std::string alpha(a);
	std::string word(w);
	if (alpha.size() == 0 || word.size() == 0)
		return;
	int count;
	FSA fsa = FSA();
	Matcher match(fsa);
	match.init(alpha);
	match.find(word, count);
}

int main(int ac, char **av) {
	if (ac < 3)
		return -1;
	else {
		getAutomata(av[1], av[2]);
	}
}

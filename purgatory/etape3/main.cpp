#include "FSA.h"
#include "Matcher.h"

void getAutomata(char *a, char *w) {
	std::string alpha(a);
	std::string word(w);
	FSA fsa = FSA();

}

int main(int ac, char **av) {
	if (ac < 3)
		return -1;
	else {
		getAtomata(av[1], av[2]);
	}
}

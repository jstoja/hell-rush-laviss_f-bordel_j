#include "Matcher.h"

Matcher::Matcher(FSA &fsa) : _fsa(fsa) {
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

bool Matcher::find(std::string &word, int &i) {
	return true;
}

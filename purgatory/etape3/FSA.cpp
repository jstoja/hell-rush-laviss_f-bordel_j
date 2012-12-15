#include "FSA.h"

FSA::FSA() {
}

FSA::~FSA() {
}

void FSA::addState(State &st) {
	_states[st.getName()] = st;
}

void FSA::operator+=(State &s) {
	_states[s.getName()] = s;
}

void FSA::setInitial(int i) {
	_initial = i;
}

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

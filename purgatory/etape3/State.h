#ifndef _STATE_H_
# define _STATE_H_

#include "Edge.h"
#include <map>

class State {
	public:
		State();
		~State();

		int getName() const { return _state;};
		void addNext(int state, Edge &ed);
	private:
		static int _iterate();

		std::map<int, Edge> _next;
		int _state;
		int _final;
};

#endif

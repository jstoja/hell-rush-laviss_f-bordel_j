#ifndef _STATE_H_
# define _STATE_H_

#include "Edge.h"
#include <map>

class State {
	public:
		State();

		~State();

		int getName() const;
		void addNext(int state, Edge &ed);
		void setFinal(bool);
		bool isFinal() const;
		char getChar();
		int checkState(char);
	private:
		static int _iterate();

		std::map<int, Edge> _next;
		int _state;
		bool _final;
};

#endif

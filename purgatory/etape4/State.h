#ifndef _STATE_H_
# define _STATE_H_

#include "Edge.h"
#include <map>
#include <list>

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
		std::list<int>& closure();
		int getStateNum(Edge);
	private:
		static int _iterate();
		std::list<int> _closure;
		std::map<int, Edge> _next;
		int _state;
		bool _final;
};

#endif

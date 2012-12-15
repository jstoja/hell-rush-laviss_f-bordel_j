#ifndef _FSA_H_
# define _FSA_H_

#include "State.h"

class FSA {

	public:
		FSA();
		~FSA();

		void addState(State *s);
		void operator+=(State *s);
		State &operator[](int s) const;
		void displayState();
		void setInitial(int i);
		int checkState(Edge&, int);
		bool isFinalState(int);
	private:
		std::map<int, State*> _states;
		int _initial;
};

#endif

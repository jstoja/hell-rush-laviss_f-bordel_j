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
		State *getInitial();
		int checkState(Edge&, int);
		bool isFinalState(int);
		std::list<int> closure(int);
		void testClosure();
		void testMove();
		int getStateNum(Edge, int);
		State* getStateByNum(int);
		std::list<int> move(int);
	private:
		std::map<int, State*> _states;
		int _initial;
};

#endif

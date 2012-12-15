#ifndef _MATCHER_H_
# define _MATCHER_H_

#include "FSA.h"

class Matcher {

	public:
		Matcher(FSA &fsa);
		~Matcher();

		bool find(std::string &word);
		bool find(std::string &word, int &fi);
	private:
		FSA _fsa;
};

#endif

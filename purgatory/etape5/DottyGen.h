#ifndef _DOTTY_GEN_H_
# define _DOTTY_GEN_H_

#include <iostream>
#include <fstream>

class DottyGen {
	public:
		DottyGen(std::string &filename);
		~DottyGen();

		void addLink(std::string &from, std::string &to, std::string &label);
		void addFinalLink(std::string &from, std::string &to, std::string &label);

	private:
		std::ofstream file;
};

#endif

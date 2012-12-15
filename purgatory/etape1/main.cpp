#include <string>
#include <iostream>
#include "Machine.hpp"

int find_position(char C, const std::string &word)
{
	int i = 0;
	while (i < word.size()) {
		if (word[i] == C)
			return i;
		++i;
	}
	return i;
}

void purge(char *str)
{
	std::string const alpha = std::string("mechant");
	std::string arg = std::string(str);
	std::string token = std::string("");
	eState state = S0;
	int i;
	while (arg.empty() == false) {	
		i = find_position(arg[0], alpha);
		if (gActionTable[state][i] == MA) {
			state = gStateTable[state][i];
			token += alpha[i];
			arg.erase(0, 1);
			if (gActionTable[state][i] == HR) {
				std::cout << "Token found: " << token << std::endl;
				token.clear();
				state = S0;
			} 
		} else {
			arg.erase(0, 1);
		}
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return -1;
	else
		purge(av[1]);
}

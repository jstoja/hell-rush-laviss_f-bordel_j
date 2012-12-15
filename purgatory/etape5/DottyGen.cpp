#include "DottyGen.h"

DottyGen::DottyGen(std::string &filename)
: file(filename.c_str()){
	//file = new std::ofstream(filename.c_str());
	file << "digraph G {" << std::endl;
}

DottyGen::~DottyGen() {
	file << "}" << std::endl;
	file.close();
}

void DottyGen::addLink(std::string &from, std::string &to, std::string &label) {
	file << from << " -> " << to << " [label=\"" << label <<  "\"];" << std::endl;
}

void DottyGen::addFinalLink(std::string &from, std::string &to, std::string &label) {
	file << "node [style=filled,color=\".7 .3 1.0\"];" << std::endl;
	file << from << " -> " << to << ";" << std::endl;
}

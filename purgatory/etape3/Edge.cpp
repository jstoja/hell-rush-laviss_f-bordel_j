#include "Edge.h"

Edge::Edge(char c)
: _c(c)
{
}

Edge::~Edge()
{
}

bool Edge::operator>(char c) const {
	return _c > c;
}

bool Edge::operator>=(char c) const {
	return _c >= c;
}

bool Edge::operator<(char c) const {
	return _c < c;
}

bool Edge::operator<=(char c) const {
	return _c <= c;
}

bool Edge::operator==(char c) const {
	return _c == c;
}

bool Edge::operator()(char c) const {
	return _c == c;
}

#ifndef _EDGE_H_
# define _EDGE_H_

class Edge {
	public:
		Edge(char c);
		Edge() {}
		~Edge();
		char getChar() const { return _c; }
		bool operator>(char c) const;
		bool operator>=(char c) const;
		bool operator<(char c) const;
		bool operator<=(char c) const;
		bool operator==(char c) const;
		bool operator()(char c) const;
	private:
		char	_c;
};

#endif

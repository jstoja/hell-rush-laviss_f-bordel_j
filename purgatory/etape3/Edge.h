#ifndef _EDGE_H_
# define _EDGE_H_

class Edge {
	public:
		Edge(char c);
		~Edge();

		bool operator>(char c);
		bool operator>=(char c);

		bool operator<(char c);
		bool operator<=(char c);

		bool operator==(char c);

		bool operator()(char c);
	private:
		char	_c;
};

#endif

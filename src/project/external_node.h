#ifndef _EXTERNAL_NODE_H_
#define _EXTERNAL_NODE_H_

#include <vector>
#include <tuple>
#include <climits>

#include "mpi.h"

#include "macros.h"
#include "node.h"
#include "types.h"


class ExternalNode : Node
{
public:
	ExternalNode(int rank, int total_nodes);

	virtual void run();
	void bubbleSort(int size, std::tuple<int, int> ptr);
	std::tuple<int, int> malloc_rep(int *values, int length);
	void free_rep(std::tuple<int, int> ptr);
	void rewrite_rep(std::tuple<int, int> ptr, int position, int value);
	int read_rep(std::tuple<int, int> ptr);
	int read_rep(std::tuple<int, int> ptr, int position);

private:
	int _total_nodes;
};


#endif /* _EXTERNAL_NODE_H_ */
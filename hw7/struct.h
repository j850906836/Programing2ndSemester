#ifndef STRUCT_H
#define STRUCT_H

struct hnode
{
	char key[100];
	int cnt;
	struct hnode*next;
};


#endif

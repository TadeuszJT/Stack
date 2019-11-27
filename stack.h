#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

#define Stack(T) struct {T *array; int len, cap;}

#define Stack_init(s)\
{\
	(s)->len = 0;\
	(s)->cap = 16;\
	(s)->array = malloc(sizeof(*(s)->array) * 16);\
}

#define Stack_push(s, item)\
{\
	if ((s)->len >= (s)->cap) {\
		(s)->cap = (s)->len * 2;\
		*(void**)&(s)->array = realloc((s)->array,\
			sizeof(*(s)->array) * (s)->cap);\
	}\
	(s)->array[(s)->len++] = (item);\
}

#define Stack_pop(s, pItem)\
((s)->len <= 0 ? 0 : (\
	(s)->len < (s)->cap / 4 ?\
		*(void**)&(s)->array = realloc((s)->array,\
			sizeof(*(s)->array) * ((s)->cap /= 4)) : 0,\
	*(pItem) = (s)->array[--(s)->len],\
	1))


#define Stack_destroy(s)\
{ free((s)->array); }

#endif 

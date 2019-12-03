#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

#define Stack(T) struct {T *array; int len, cap;}

#define Stack_init(s)\
do {\
	(s)->len = 0;\
	(s)->cap = 16;\
	(s)->array = malloc(sizeof(*(s)->array) * 16);\
} while (0)

#define Stack_push(s, item)\
do {\
	if ((s)->len >= (s)->cap) {\
		(s)->cap = (s)->len * 2;\
		*(void**)&(s)->array = realloc((s)->array,\
			sizeof(*(s)->array) * (s)->cap);\
	}\
	(s)->array[(s)->len++] = (item);\
} while (0)

#define Stack_pop(s, pItem)\
((s)->len <= 0 ? 0 : (\
	(s)->len < (s)->cap / 4 ?\
		*(void**)&(s)->array = realloc((s)->array,\
			sizeof(*(s)->array) * ((s)->cap /= 4)) : 0,\
	*(pItem) = (s)->array[--(s)->len],\
	1))


#define Stack_destroy(s)\
do { free((s)->array); } while (0)

#endif 

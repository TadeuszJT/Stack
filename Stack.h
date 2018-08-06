#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

#define Stack(T) struct {T *array; int len, cap;}


#define Stack_init(s)\
do {\
	(s)->array = NULL;\
	(s)->len = (s)->cap = 0;\
} while (0)


#define Stack_push(s, item)\
do {\
	int pos = (s)->len;\
	if (++(s)->len >= (s)->cap) {\
		*(void**)&(s)->array = realloc(\
			(s)->array,\
			sizeof(*(s)->array) * ((s)->cap = (s)->len*2)\
		);\
	}\
	(s)->array[pos] = (item);\
} while (0)


#define Stack_pop(s)\
(--(s)->len < (s)->cap/4 ?\
*(void**)&(s)->array = realloc(\
	(s)->array,\
	sizeof(*(s)->array)*((s)->cap/=4)\
):0, (s)->array[(s)->len])


#define Stack_destroy(s)\
do {free((s)->array);} while (0)

#endif 

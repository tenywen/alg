#ifndef _COMMON_H_
#define _COMMON_H_
// 向下取整
#define FLOOR(a) ((int)a)

// 向上取整
#define CEIL(a) ((int)(a+1))

typedef int ERROR;

enum Error {
	CREATE_ERR	= 1,
	EMPTY		= 2,
	FULL		= 3,
};

#endif

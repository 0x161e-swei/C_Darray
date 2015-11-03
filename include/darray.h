#ifndef _DARRAY_H_
#define _DARRAY_H_

#include <stdlib.h>
#include <string.h>
#include 

#ifdef DEBUG

#define darray_log_err(M, ...) \
	fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define darray_log_info(M, ...) \
	fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) \
	do{ \
		if(!(A)) { \
			log_err(M, ##__VA_ARGS__); \
			errno=0; \
			goto error; \
		} \
	}while(0)

#endif


#define _darray_type(T) \
	struct { size_t element_size; size_t capacity; size_t length; T* content; }

typedef struct _d_array
{
	/* data */
	const size_t element_size;
	size_t capacity;
	size_t length;
	char* content;		// TODO: figure out char* or char** works better
} DArray;



DArray *darray_create(size_t reserve_size, size_t element_size);

bool _darray_reserve(DArray *arr, size_t n);

bool _darray_expand(DArray *arr);

void* _darray_get(DArray *arr, size_t index);

void* _darray_set(DArray *arr, size_t index);

typedef _darray_type(char) 		DArray_CHAR;
typedef _darray_type(int) 		DArray_INT;
typedef _darray_type(long) 		DArray_LONG;
typedef _darray_type(float) 	DArray_FLOAT;
typedef _darray_type(double) 	DArray_DOUBLE;

#endif /* _DARRAY_H_ */


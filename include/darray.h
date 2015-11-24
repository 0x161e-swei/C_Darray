#ifndef _DARRAY_H_
#define _DARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "config.h"

#ifdef DEBUG

#define darray_log_err(M) \
	fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__)

#define darray_log_info(M) \
	fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__)

#define check(A, M) \
	do{ \
		if(!(A)) { \
			darray_log_err(M); \
			goto error; \
		} \
	}while(0)

#endif

#define _darray_type_declare(T) \
	struct _darray_struct_##T { \
		const size_t element_size; \
		size_t capacity; \
		size_t length; \
		T *content; \
		void (* const get)(DArray *, size_t, PDataType *); \
		void (* const set)(DArray *, size_t, T *); \
	}\

#define _darray_assert(data) \
	do { \
		assert(NULL != data); \
		assert(NULL != (data)->content); \
	} while(0)

#define _darray_index_assert(data, index) \
	do { \
		_darray_assert(data); \
		assert(index < (data)->length && index < (data)->capacity);	\
	} while(0)
	

#define darray_get(data, index, res) \
	do { \
		_darray_index_assert(data, index); \
		(data)->get((data), index, &(res)); \
	} while(0)

#define darray_set(data, index, val) \
	do { \
		_darray_index_assert(data, index); \
		(data)->set((data), index, &(val)); \
	} while(0)

#define darray_expand(data) \
	do { \
		if ((data)->length + 1 > (data)->capacity) { \
			_darray_expand(data); \
		} \
	} while(0)

#define darray_push(data, val) \
	do { \
		if ((data)->length + 1 > (data)->capacity) { \
			_darray_expand(data); \
		} \
		(data)->set((data), (data->length), &(val)); \
		((data)->length)++; \
	} while(0)
	
#define darray_vec_push(data, src, n) \
	do { \
		while ((data)->length + n > (data)->capacity) { \
			_darray_expand(data); \
		} \
		_darray_vec_push(data, src, n); \
	} while(0)

#define darray_clear(data) \
	data->length = 0;

typedef	enum _dataType {
	CHAR,
	INT,
	LONG,
	FLOAT,
	DOUBLE,
	SIZET
} DataType;

typedef union _pdatatype {
	char *pchar;
	int *pint;
	long *plong;
	float *pfloat;
	double *pdouble;
	size_t *psizet;
} PDataType;

typedef struct _d_array DArray;
struct _d_array {
	/* data */
	const size_t element_size;
	size_t capacity;
	size_t length;
	void *content;		// TODO: figure out char* or char** works better
	void (* const get)(DArray *, size_t, PDataType *);
	void (* const set)(DArray *, size_t, void *);
};

typedef _darray_type_declare(char)		DArray_CHAR;
typedef _darray_type_declare(int)		DArray_INT;
typedef _darray_type_declare(long)		DArray_LONG;
typedef _darray_type_declare(float)		DArray_FLOAT;
typedef _darray_type_declare(double)	DArray_DOUBLE;
typedef _darray_type_declare(size_t)	DArray_SIZET;

DArray *darray_create(size_t reserve_size, DataType dtype);

bool _darray_reserve(DArray *arr, size_t n);

bool _darray_expand(DArray *arr);

bool darray_destory(DArray *arr);

void _darray_vec_push(DArray *arr, const void * src, size_t n);

void darray_swap(DArray *arr, size_t idx1, size_t idx2);

static inline void _darray_set_content_char(DArray *self, size_t index, char *val) {
	((DArray_CHAR *)self)->content[index] = *val;
	// *(char *)(arr->content + index * arr->element_size) = val;
}

static inline void _darray_set_content_int(DArray *self, size_t index, int *val) {
	((DArray_INT *)self)->content[index] = *val;
}

static inline void _darray_set_content_long(DArray *self, size_t index, long *val) {
	((DArray_LONG *)self)->content[index] = *val;
}

static inline void _darray_set_content_float(DArray *self, size_t index, float *val) {
	((DArray_FLOAT *)self)->content[index] = *val;
}

static inline void _darray_set_content_double(DArray *self, size_t index, double *val) {
	((DArray_DOUBLE *)self)->content[index] = *val;
}

static inline void _darray_set_content_sizet(DArray *self, size_t index, size_t *val) {
	((DArray_SIZET *)self)->content[index] = *val;
}

static inline void _darray_get_content_char(DArray *self, size_t index, PDataType *res) {
	res->pchar = &(((DArray_CHAR *)self)->content[index]);
}

static inline void _darray_get_content_int(DArray *self, size_t index, PDataType *res) {
	res->pint = &(((DArray_INT *)self)->content[index]);
}

static inline void _darray_get_content_long(DArray *self, size_t index, PDataType *res) {
	res->plong = &(((DArray_LONG *)self)->content[index]);
}

static inline void _darray_get_content_float(DArray *self, size_t index, PDataType *res) {
	res->pfloat = &(((DArray_FLOAT *)self)->content[index]);
}

static inline void _darray_get_content_double(DArray *self, size_t index, PDataType *res) {
	res->pdouble = &(((DArray_DOUBLE *)self)->content[index]);
}

static inline void _darray_get_content_sizet(DArray *self, size_t index, PDataType *res) {
	res->psizet = &(((DArray_SIZET *)self)->content[index]);
}



#endif /* _DARRAY_H_ */


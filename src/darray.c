#include "darray.h"

DArray *darray_create(size_t reserve_size, DataType dtype) {
	static DArray_CHAR generic_char_array = {	.element_size = sizeof(char),
										.capacity = 0, .length = 0, .content = NULL,
										.get = _darray_get_content_char,
										.set = _darray_set_content_char};
	static DArray_INT generic_int_array = {	.element_size = sizeof(int), 
										.capacity = 0, .length = 0, .content = NULL,
										.get = _darray_get_content_int,
										.set = _darray_set_content_int};
	static DArray_LONG generic_long_array = {	.element_size = sizeof(long),
										.capacity = 0, .length = 0, .content = NULL,
										.get = _darray_get_content_long,
										.set = _darray_set_content_long};
	static DArray_FLOAT generic_float_array = {	.element_size = sizeof(float),
										.capacity = 0, .length = 0, .content = NULL,
										.get = _darray_get_content_float,
										.set = _darray_set_content_float};
	static DArray_DOUBLE generic_double_array = {	.element_size = sizeof(double),
										.capacity = 0, .length = 0, .content = NULL,
										.get = _darray_get_content_double,
										.set = _darray_set_content_double};
	static DArray_SIZET generic_sizet_array = {	.element_size = sizeof(size_t),
										.capacity = 0, .length = 0, .content = NULL,
										.get = _darray_get_content_sizet,
										.set = _darray_set_content_sizet};
	
	DArray *arr = malloc(sizeof(DArray));
	check(NULL != arr, "Out of memory");
	switch (dtype) { 					// Initialize the DArray with specified type
		case CHAR: {
			memcpy(arr, &generic_char_array, sizeof(DArray_CHAR));
			break;	
		}
		case INT: {
			memcpy(arr, &generic_int_array, sizeof(DArray_INT));
			break;	
		}
		case LONG: {
			memcpy(arr, &generic_long_array, sizeof(DArray_LONG));
			break;	
		}
		case FLOAT: {
			memcpy(arr, &generic_float_array, sizeof(DArray_FLOAT));
			break;	
		}
		case DOUBLE: {
			memcpy(arr, &generic_double_array, sizeof(DArray_DOUBLE));
			break;	
		}
		case SIZET: {
			memcpy(arr, &generic_sizet_array, sizeof(DArray_SIZET));
			break;	
		}
	}
	_darray_reserve(arr, reserve_size);
	return arr;

	error:
	return NULL;
}

bool _darray_reserve(DArray *arr, size_t n) {
	check(n > arr->capacity, "reserved size smaller than capacity");
	size_t size = 1024;
	while (size < n) size <<= 1;
	void *tmp_ptr = realloc(arr->content, size * arr->element_size);
	check(NULL != tmp_ptr, "Out of memory");
	memset(tmp_ptr, 0, size * arr->element_size);
	arr->content = tmp_ptr;
	arr->capacity = size;
	return true;

	error: 
	return false;
}

bool _darray_expand(DArray *arr)
{
	// if (arr->length + 1 > arr->capacity) {
		void *ptr = NULL;
		size_t n = (arr->capacity) << 1;
		ptr = realloc(arr->content, n * arr->element_size);
		check(NULL != ptr, "Out of memory");
		// printf("expand from %zu to %zu \n", arr->length, n);
		arr->content = ptr;
		arr->capacity = n;
	// }
	return true;

	error:
	return false;
}

bool darray_destory(DArray *arr) {
	check(NULL != arr && NULL != arr->content, "Attemp to free invaild mem!");
	free(arr->content);
	free(arr);
	// memset(arr, 0, sizeof(DArray));
	return true;

	error:
	return false;
}

void darray_swap(DArray *arr, size_t idx1, size_t idx2) {

	assert(idx1 < arr->length && idx2 < arr->length);
	if (idx1 == idx2) return;
	unsigned char *vl, *vr, tmp;
	size_t size_count = arr->element_size;
	vl = ((unsigned char *)(arr->content) + idx1 * size_count);
	vr = ((unsigned char *)(arr->content) + idx2 * size_count);
	while (size_count--) {
		tmp = *vl;
		*vl = *vr;
		*vr = tmp;
		vl++;
		vr++;
	}
}

void _darray_vec_push(DArray *arr, const void * src, size_t n) {
	// size_t i = arr->length, j = 0;
	// for (; i < arr->length + n * arr->element_size; i++, j++) {
	// 	*((char *)arr->content + i) = *((char *)src + j);
	// }
	memcpy((char *)arr->content + arr->element_size * arr->length, 
		src, 
		n * arr->element_size);
	arr->length += n;
}
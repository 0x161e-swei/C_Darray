#include "darray.h"

DArray *darray_create(size_t reserve_size, size_t element_size) {
	DArray *arr = malloc(sizeof(DArray));
	if (NULL == arr) {
		log_err("Out of memory");
		return NULL;
	}
	arr->capacity = 0;
	arr->length = 0;
	arr->element_size = element_size;
	arr->content = NULL;
	_darray_reserve(arr, reserve_size);
	return arr;
}

bool _darray_reserve(DArray *arr, size_t n) {
	if (n <= arr->capacity) {
		return false;
	}
	size_t size = 1024;
	while (size < n) size <<= 1;
	void *tmp_ptr = realloc(arr->content, size * arr->element_size);
	if (NULL == tmp_ptr) {
		log_err("Out of memory");
		return false;
	}
	arr->content = tmp_ptr;
	arr->capacity = size;
}

bool _darray_expand(DArray *arr)
{
	if (arr->length + 1 > arr->capacity) {
		void *ptr = NULL;
		int n = (arr->capacity == 0)? 1024: (arr->capacity) << 1;
		ptr = realloc(arr->content, n * element_size);
		if (NULL == ptr) return false;
		arr->content = ptr;
		arr->capacity = n;
	}
	return true;
}

void *_darray_get(DArray *arr, size_t index) {
	check(index < arr->length, "Attempt to get invalid data");

}

void *_darray_set(DArray *arr, size_t index) {
	check(index < arr->length, "Attempt to set invalid data");
}
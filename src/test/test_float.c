#include "darray.h"
#include <stdio.h>


// int foo(double *val) {
// 	printf("value %lf ", *val);
// 	return (int)*val;
// }

int main(){
	// printf("hello world\nsize one %zu, size two %zu, %zu\n", sizeof(DArray), sizeof(DArray_INT), sizeof(DArray_SIZET));
	
	printf("%zu \n", sizeof(size_t));	

	DataType dtype = FLOAT;
	DArray *arr_float = darray_create(1024, dtype);
	
	for (size_t i = 0; i < 10000000; i++) {
		float v = i;
		// darray_push(arr_float, v);
		assert(NULL != arr_float);
		assert(NULL != arr_float->content);
		_darray_expand(arr_float);
		arr_float->set(arr_float, arr_float->length, &v);
		(arr_float->length)++;
	}

	// PDataType t = arr_float->get(arr_float, 10);m

	for (size_t j = 0; j < 10000000; j++) {
		PDataType res;
		darray_get(arr_float, j, res);
		// if (j > 170 && j < 180)
		// 	printf("get index %zu: %f \n", j, *res.pfloat);	
	}

	_darray_destory(arr_float);

	// dtype = INT;
	// DArray *arr_int = darray_create(1024, dtype);
	
	// for (size_t i = 0; i < 10000000; i++) {
	// 	int v = 12 * i - 123456;
	// 	darray_push(arr_int, v);
	// }

	// // PDataType t = arr_float->get(arr_float, 10);m

	// for (size_t j = 0; j < 10000000; j++) {
	// 	PDataType res;
	// 	darray_get(arr_int, j, res);
	// 	/*if (j > 170 && j < 180)
	// 		printf*/("get index %zu: %d \n", j, *res.pint);
	// }

	// _darray_destory(arr_int);



	return 0;		
}

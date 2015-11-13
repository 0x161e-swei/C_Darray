#include "darray.h"
#include <stdio.h>
#include <time.h>

// int foo(double *val) {
// 	printf("value %lf ", *val);
// 	return (int)*val;
// }

int src[10000];
DArray *arr_int;
PDataType pres;
void darray_foo_set() {

	for (size_t i = 0; i < 10000; i++) {	
		// if (arr_int->length + 1 > arr_int->capacity) {
		// 	_darray_expand(arr_int);
		// }
		// arr_int->set(arr_int, arr_int->length, &v);
		// arr_int->length++;
		darray_vec_push(arr_int, src, 10000);
		
	}
	darray_clear(arr_int);

}

long darray_foo_get() {
	long sum_long = 0;
	for (size_t i = 0; i < 10000000; i++) {
		arr_int->get(arr_int, i, &pres);
		sum_long += *(pres.pint);
	}
	return sum_long;
}

int main(){

	DataType dtype = INT;
	
	arr_int = darray_create(1024, dtype);	

	for (size_t k = 0; k < 10000; k++) {
		src[k] = k - 1;
	}

	clock_t start, end, sum = 0;

	for (int j = 0; j < 100; j++) {
		start = clock();	
		darray_foo_set();
		end = clock();
		sum += end - start;
	}
	
	long sum_long = 0;
	
	for (size_t i = 0; i < 100; i++){
		sum_long = darray_foo_get();
		// for (size_t k = 0; k < 100000000; k++) {
		// 	// darray_get(arr_int, k * 100 + k, pres);
		// 	arr_int->get(arr_int, k, &pres);
		// 	sum_long += *(pres.pint);
		// }
	}
		
	printf("%ld\n", sum_long);
	
	return 0;		
}

#include "darray.h"
#include <stdio.h>
#include <time.h>
#define TESTQ 1000000

int *src;
DArray *arr_int;
int vec_size = 0;
long sum_long = 0;
PDataType pres;
int pre_arr[TESTQ];

void darray_foo_set_vec() {
	int i = 0;
	for (; i < TESTQ / vec_size; i++) {	
		darray_vec_push(arr_int, src, vec_size);
	}
}

void darray_foo_set() {
	int i = 0;
	for (; i < TESTQ; i++) {
		darray_push(arr_int, src[0]);
	}
	// darray_clear(arr_int);
}

void foo_mem_cpy(int* arr, const void *src, size_t vec_size) {
	memcpy(arr, src, vec_size * sizeof(int));
}

void foo_set_vec() {
	int i = 0;
	for (; i < TESTQ / vec_size; i++) {
		foo_mem_cpy(pre_arr, src, vec_size);
	}
}

void foo_set() {
	int i = 0;
	for (; i < TESTQ; i++) {
		pre_arr[i] = src[0];
	}
}

void darray_foo_get() {
	sum_long = 0;
	int i = 0;
	for (; i < TESTQ; i++) {
		arr_int->get(arr_int, i, &pres);
		sum_long += *(pres.pint);
	}
}

void darray_foo_radom_get() {
	sum_long = 0;
	int i = 0, x = 0;
	for (; i < TESTQ; i++) {
		x = rand() % TESTQ;
		arr_int->get(arr_int, x, &pres);
		sum_long += *(pres.pint);
	}
}

void foo_get() {
	sum_long = 0;
	int i = 0;
	for (; i < TESTQ; i++) {
		sum_long += pre_arr[i];
	}
}

void foo_radom_get() {
	sum_long = 0;
	int i = 0, x;
	for (; i < TESTQ; i++) {
		x = rand() % TESTQ;
		sum_long += pre_arr[x];
	}
}

int main(){

	DataType dtype = INT;
	
	scanf("%d", &vec_size);
	
	
	clock_t start, end, sum = 0;
	srand((unsigned int)time(NULL));
	if (vec_size > 0) {
		src = malloc(vec_size * sizeof(int));
		for (int k = 0; k < vec_size; k++) {
			src[k] = k - 1;
		}
		for (int j = 0; j < 1000; j++) {
			arr_int = darray_create(1024, dtype);
			start = clock();	
			darray_foo_set_vec();
			end = clock();
			sum += end - start;
			darray_destory(arr_int);
		}	
		printf("set %lf\n", (double) sum / CLOCKS_PER_SEC);
		
		arr_int = darray_create(1024, dtype);
		darray_foo_set_vec();
		sum = 0;
		for (size_t i = 0; i < 1000; i++){
			start = clock();	
			darray_foo_get();
			end = clock();
			sum += end - start;
		}
		printf("get %lf\n", (double) sum / CLOCKS_PER_SEC);
	}
	else if (vec_size == 0 ){
		src = malloc(sizeof(int));
		*src = 123456;
		for (int j = 0; j < 1000; j++) {
			arr_int = darray_create(1024, dtype);
			start = clock();	
			darray_foo_set();
			end = clock();
			sum += end - start;
			darray_destory(arr_int);
		}
		printf("set %lf\n", (double) sum / CLOCKS_PER_SEC);

		arr_int = darray_create(1024, dtype);
		darray_foo_set();
		sum = 0;
		for (size_t i = 0; i < 1000; i++){
			start = clock();	
			darray_foo_get();
			end = clock();
			sum += end - start;
		}
		printf("get %lf\n", (double) sum / CLOCKS_PER_SEC);
	}
	/*else if (vec_size == -1) {
		src = malloc(sizeof(int));
		*src = 123456;
		for (int j = 0; j < 1000; j++) {
			start = clock();	
			foo_set();
			end = clock();
			sum += end - start;
		}
		printf("set %lf\n", (double) sum / CLOCKS_PER_SEC);
		foo_set();
		sum = 0;
		for (size_t i = 0; i < 1000; i++){
			start = clock();	
			foo_get();
			end = clock();
			sum += end - start;
		}
		printf("get %lf\n", (double) sum / CLOCKS_PER_SEC);
	}*/
	else {
		vec_size = -vec_size;
		src = malloc(vec_size * sizeof(int));
		for (int k = 0; k < vec_size; k++) {
			src[k] = k - 1;
		}
		for (int j = 0; j < 1000; j++) {
			start = clock();	
			foo_set_vec();
			end = clock();
			sum += end - start;
		}	
		printf("set %lf\n", (double) sum / CLOCKS_PER_SEC);
		
		sum = 0;
		for (size_t i = 0; i < 1000; i++){
			start = clock();	
			foo_get();
			end = clock();
			sum += end - start;
		}
		printf("get %lf\n", (double) sum / CLOCKS_PER_SEC);
	}
	
	
	
	
		
	// printf("%ld\n", sum_long);
	
	return 0;		
}

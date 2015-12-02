# C_Darray
Dynamic array implemented in C

### Create a new array with INT

``` c
DataType dtype = INT;
DArray *arr_int = NULL;
arr_int = darray_create(1024, dtype);
```
### Destory the array

``` c
darray_destory(arr_int);
```

### Push value(s)

#### one at a time
``` c
int v = 123;
darray_push(arr_int, v);
```

#### vectorized push
``` c
int src[] = {1, 2, 3, 4, 5};
int vec_size = 5;
darray_vec_push(arr_int, src, vec_size);
```


### Get by index
``` c
int index = 10;
PDataType pres;j
arr_int->get(arr_int, index, &pres);
printf("%d\n", *(pres.pint));

```



### DateType and PDataType are defined as:
``` c
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

```



### Generic and specific type array are defined as: 

``` c
#define _darray_type_declare(T) \
	struct _darray_struct_##T { \
		const size_t element_size; \
		size_t capacity; \
		size_t length; \
		T *content; \
		void (* const get)(DArray *, size_t, PDataType *); \
		void (* const set)(DArray *, size_t, T *); \
	}\


typedef struct _d_array DArray;
struct _d_array {
	/* data */
	const size_t element_size;
	size_t capacity;
	size_t length;
	void *content;		
	void (* const get)(DArray *, size_t, PDataType *);
	void (* const set)(DArray *, size_t, void *);
};

typedef _darray_type_declare(char)		DArray_CHAR;
typedef _darray_type_declare(int)		DArray_INT;
typedef _darray_type_declare(long)		DArray_LONG;
typedef _darray_type_declare(float)		DArray_FLOAT;
typedef _darray_type_declare(double)	DArray_DOUBLE;
typedef _darray_type_declare(size_t)	DArray_SIZET;

```

# C & CPP

## Arrays

### Kinds of array

1. Fixed Number Array

   

2. Variable-length Array
	Allocate memory and length when running, not when compiling
	
3. Unknown Size Array
	`int num_array[] = {1,2,3}`

### Pass the array as argument

The array is actually called by an address like pointer. So when pass an array as argument, you only know the first position of the array and you don't know the length.
`int num[4] = ...`
Thus, you have to pass two arguments.
`

### Element accessing

When you copy array to another array, you have to copy the value each for each.
```cpp
int array1[4] = {9,8,7,6};
int array2[4];
array2 = array1;//wrong
for (int i = 0; i < 4; i++){
array2[i] = array1[i];//right
}
```

When you write a value to an index that hasn't been allocated an index. Compile yes, Running yes, Result Correct. BUT you may occupy other programs' memories.
This is called Index Out of Bound

```cpp
int num[5];
    for (int i = -1;i <=6; i++){
        num[i] = i*i;
        cout << num[i] << endl;
    }
```

### Multidimensinal Arrays

**Not Recommended**
```cpp
int mat[2][3] = {{...},{...}};
```
When passing an argument:
`void init(float mat[][3], size_t rows, size_t clos)`

### const Arrays

Because you don't want to edit the value of the pointer the you passed.(e.g in a funtion)

It will cause a COMPILE ERROR

## String

### Array-style strings

Initializing without assigning, unassigned will be initialized `int 0`.
```cpp
char rabbit[16] = {1,2};// Initializing without assigning, unassigned will be initialized 0
```
`strlen` output the length of a string, no matter how long it is.

Adding  `'\0'`
equals using `0` directly
```cpp
char name[10] = {'Y', 'u', '\0', 'S', '.', '0'};
cout << strlen(name) << endl;
```
The output is 2.
> A small trick: adding '+' in cout will print the int form of char string

### String Manipulation and Examination

`strcpy` `strncpy`
`strcat`
`strcmp`
## Struct

To align data, the empty bytes will be padded.

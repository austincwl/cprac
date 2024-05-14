# Fundamentals of C

Notes on Problem Solving and Program Design in C by Jeri R. Hanly and Elliot B. Koffman

## Overview of C

* 2 parts: proprocessor directives and the pain function
    - Proprocessor directives: commands that give instructions to the C preprocessor, whose job it is to modity the text of a C program *before* it's compiled.
        * begins with a `#` ex: `#include <stdio.h>` and `#define KMS_PER_MILE 1.609`
        * `#define` is used for 'constant variables' and macros, what this actually does is replace the defined word with its value during compile

* Operators
    - `&` is the 'address-of' operator, tells you the adress of a variable ex: `&variable` tells you the location of `variable`
    - `%` is the remainder operator
    - type asking ex: `int n = (int)(9*0.5);`
        * easy rounding: `int n = (int)(doubleVar + 0.5)
    - `''` for char
    - `""` for a string literal

* stdio.h
    - `printf();` printing
    - `scanf();` reading from console
    - `printf("string %f", variable);` replaced %f with the value of the variable. 
        * `%d` = int
        * `%c` = char
        * `%f` = double (printf)
        * `%lf` = float (scanf)
    - `scanf("%lf", &variable);` stored entered double into memory location (pointer or memory reference(shown))
        * need to pass in a pointer for this as otherwise the function would only know the current value of that variable, not where to store the input
    
* Error Types
    - syntax
    - Run-time: errors found during execution, crashes
    - logic: programs runs fine but doesn't get required outcome
    
## Chapter 3: Top-Down Design with Functions

void function declaration: 
```C
void draw_circle(void){
    /* draw circle */
    return;
}
```

Can declare function prototypes before main functions, while functiion definition goies after.
 - this allows the compiler to know the function exists, while not having to have all of them at the top of the file
```C
void draw_circle(void);
void main(void){
    draw_circle();
}
void draw_circle(void){
    /* draw circle */
    return;
}
```

## Chapter 4: Selection Structures: If and Switch Statements

If statement structure:
```C
if(statement){
    //
}
else if(statement){
    //
}
else{
    //
}
```

Switch case statement structure:
```C
switch(varLetter){
    case 'A':
    case 'a':
        printf("Excellent\n");
    case 'B':
    case 'b':{
        printf("Good\n");
        printf("Do better\n");
    }
    default:
        printf("invalid");
}
```

## Chapter 5: Repetition and Loop Statements
- same for and while loops as C++
- do while executes 1 loop before evaluating condition
```C
do{
   //
}while(condition)
```
 
 ## Chapter 6: Pointers and Modular Programming
 
 ### 6.1 Pointers and the Indirection Operator

Declare with pointer type, so the compiler knows what it's pointing to. example below shows the creation of an integer pointer
```C
int num = 25;
int *nump
nump = &num;
```
Notice how the pointer *points to a location created by a variable declaration*. You should not create a pointer that points to nothing unless it is being used to change out references to other pointers.

Applying the unary operator `*` follows the pointer, returning the value stored in the location specified by the pointer
```C
*nump = 35;
num = 35;
```
The two statements above are equivalent.

Pointer to a file:
```C
FILE *inp   //pointer to input file
FILE *outp  //pointer to output file

inp = fopen("input.txt","r");
outp = fopen("output.txt","w");

fscanf(inp, "%lf",&num);
fprintf(outp,"%.2f\n",num); //the 0.2 specifies the precision
fclose(inp);
fclose(outp);
```

### 6.2 Functions with Output Parameters

In the statement below, the pointer input parmaters are used as a way to return 3 values, even though functions in C can only return 1 value.
```C
void separate(double num, char *signp, int *wholep, double *fracp);

void main(void){
    double value = 12.7;
    char sn;
    int whl;
    double fr;
    separate(value, &sn, &whl, &fr);
}

void separate(double num, char *signp, int *wholep, double *fracp){
    double magnitude;

    if(num<0)
        *signp = '-';
    else if(num==0)
        *signp = ' ';
    else
        *signp = '+';
    
    magnitude = fabs(num);
    *wholep = floor(magnitude);
    *fracp = magnitude - *wholep;
    return;
}
```

### 6.5 Formal Output Parameters as actual Arguments

```C
void scan_fraction(int *nump, int *demonp)
    char slash;
    int status;
    status = scanf(%d %c%d", nump, &slash, denomp);
}
```
- `scanf()` uses memory address to store inputs from terminal

### 6.7 Debugging and Testing

* *Unit Testing:* tests smallest piece, i.e. a single function
* *Integration Testing:* tests interactions between functions, sometimes using *stubs*, which replace a function with one that imitates its function for testing purposes
* *System Testing:* tests the whole program in the context it will be used
* *Acceptance Testing:* shows the program meets functional requirements

## Chapter 7: Array Pointers

* declare an empty array of size 8: `double x[8];`
    - x is the address of the initial array element
    - x's type is a pointer to a double
* reference an element of an array using `[]`: `x[0] = 2.3;`
* size can be ommitted from a fully initialized array: `int odds[] = {3,5,7,9};`
    - works the same way for strings: `char letters[] = "letters";`
* use memory reference to input to array from `scanf()`
```C
for(int i = 0; i < 3; i++){
    scanf("%lf",&x[i]);
}
```
* to pass into function parameter, need to include size since the arrays are simply pointers
```C
fill_array(int list[], int list_length){}
//the below two lines are equivalent (but one is easier to read, really no need to do it the long way:
fill_array(x,5); 
fill_array(&x[0],5); //[0] dereferences it, & references it again
```

* **C does not allow return values to be arrays**, need to use array address/pointer as an input parameter
* can use `const` to describe input parameters that won't be changed in the function
```C
void add_arrays(const double arr1[]; const double arr2[], double arrsum[], const int n){
    /* add arrays*/
    //output goes into arrsum
    return;
}
```

* can use an array for a *stack* by keepin track of the location (index) of the last element and the max size
    - push (add to top of stack)
    - pop (remove from top of stack)
    
### 7.6 Searching and Sorting

- can search and array w/ a simple for loop
- selection sort is fairly intuitive but inefficient:
    1. find smallest element, place at 0
    2. find next smallest element, place at 1... etc

### 7.7 Parallel Arrays and Enumerator Types

Enumarated Types:
- can create data types using `typedef`
- ANSI C allows you to associate a numeric code with each category
    * ex: expense types:
    ```C
    typedef enum
        {rent, utilities, food} //compiled as rent=0, utilities = 1, etc.
    expense_t;
    ```
    example use case:
    ```C
    expense_t expense_kind = 0;
    switch(expense_kind):
        case rent:
            //this will catch since rent = 0
            break;
    ```

### 7.8 Multidimensional Arrays

- arrays can be 2 or more dimensions
- initialize a 3x3 array of char: `char tictac[3][3];
```
        col
    _____________
row |   |   |   |
    _____________
    |   |   |   | <- tictac[1][2]
    _____________
    |   |   |   |
    _____________
```
- when initializing multidimensional arrays, the 1st dimension, number of rows, can be omitted (pointer to single space): `char tictac[][3];`
- can fully initialize:
```C
char tictac[3][3] = {
                        {'','',''},
                        {'','',''},
                        {'','',''}
                    };
```
- ANSI C requires support for multidimensional arrays up to 6 dimensions

## Chapter 8: Strings

- can initilize an array of string (2d array) since a string is an array of chars
```C
char count[3][5] = {"One","Two","Three"};
//         ^  ^-max length of strings
//         ^-number of strings
```
- in `printf()` and `scanf()`, can  specify placeholder length to maintain spacing (right justified by default): `printf("1: %10s\n",value);`
- can include a `-` to left-justify: `printf("1: %-10s\n",value);`
- input to str[80] can be 79 char long to leave room for `\0` (end of string null character)

### 8.2 Standard Library string.h
- because string is an arrray, cannot change it wholly after initialization:
- instead, use standard library string.h
```C
char one_str[20];
one_str = "Test String"; //DOES NOT WORK
strcpy(one_str, "Test String"); //DOES WORK, uses string.h
```
- use `strlen(const *char[])` to find string length, this will count length up to (and not after) null character `\0`

### 8.3 Longer Strings: Concatenation and Whole-Line Input

-`strcat()` and `strcpy()` have intellegece to prevent overflow
-`stdio`'s `fgets()` has max string length input parameter, unlike `gets()` 

### 8.4 String Comparison

- (str1 < str2) tests if str1's address is less than str2's
- `strcmp()` is used for comparison's instead, returns int
    * -1 = <
    * 0 = equals
    * 1 = >
    - thrill < throw
    - energy < force
    - joy < joyous
    
### 8.5 Array of Pointers

- an array of strings is an array of pointers
- when sorting this array of strings, you can instead sort the pointers, this allows for creating a sortest list of pointers while maintaining the original order
    * uses less storage
    * faster than copying (moving, swapping, etc)
    * change in string is reflected in all copies of pointer lists
    
### 8.6 Character Operations

- character functions in `ctype.h`
- `getchar()` takes no arguments and returns the char entered in the terminal
- `getc(inp)` returns char from file pointer
- `ctype.h` contains functions for determining character type:
    * isalpha
    * isdigit
    * islower/isupper
    * ispunct
    * isspace
    * toupper/tolower
    
### 8.7 String <-> Number Conversions

- `sprintf(s, "%d", variable)` stores the character array in s (ex. `char s[100];`)
- `sscanf()` works same as `sprintf()`, takes input from initial string
    * can use these for error (memory overflow) checking
- when building functions that create string, include the output as a parameter to prevent overflow

## Chapter 9: Recursion

- generally, a recursive solution is less efficient than an iterative one, but lets us solve things simply that would otherwise be complex
- ex. count number of times `char ch` is in `string *str`
```C
int count(char ch, const char *str){
    int ans;
    if(str[0] == '\0')
        ans = 0;
    else
        if(ch == str[0])
            ans = 1 + count(ch, &str[1]);
        else
            ans = count(ch, &str[1]);
    return ans;
}
```

## Chapter 10: Structure and Union Types
 
- defining data type for each category of structred objects
- ex: planet type
```C
#define STRSIZ 10
typedef struct {
    char name[STRSIZ];
    double diameter;
    int moons;
    double orbit_time, rotation_time;
} planet_t

planet_t blank_planet = {"",0,0,0,0};
planet_t empty_planet;
```
- reference components of a structure using the "direct component selection operator", a period `.`: `blank_planet.moons = 16;`
- a new copy can be made using the assignment operator: `empty_planet = blank_planet;
- struct components can be structs
- struct components can be recursive: ex: linked list struct pointers
```C
//typedef struct
typedef struct node1_s{
    int num,
    struct *node1_s next;
} node1_t

//struct with no type
struct node2_s{
    int num,
    struct *node2_s next;
}

//to initialize a node with a typedef:
node1_t newNode;
//to initialize a node without a typedef:
struct node2_s newNode;
//to create a typedef for a struct without a typedef:
typedef struct node2_s node2_t;
```
- can use structs and input and output parameters for functions: `void print_planet(planet_t planet);`

- `.` takes precidence ofer * and &, takes care to `scanf()` directly into struct component
```C
int scan_planet(planet_t *planetp){
    int result = scanf(%s%lf%d%lf%lf,
                        (*plnp).name, //string array, needs a pointer
                        &(*plnp).diameter, //struct value input, needs address of struct component
                        &(*plnp).moons,
                        &(*plnp).orbit_time,
                        &(*plnp).rotation_time);
    return result;
}
```
- C provides the indirect component selection operator to make this easier to read/type: `->`
```C
int scan_planet(planet_t *planetp){
    int result = scanf(%s%lf%d%lf%lf,
                        plnp->name, //string array, needs a pointer
                        &plnp->diameter, //struct value input, needs address of struct component
                        &plnp->moons,
                        &plnp->orbit_time,
                        &plnp->rotation_time);
    return result;
}
```
- C allows for structs to be returned from functions

### 10.5 Arrays of Structures

declare same as normal arrays: `planet_t planets[MAX_PLANETS];`

*unions* define a structure that has *1* of the listed parameters, allowing for different types of the same struct:

in the example below, the hair_t will have *either* the wears_wig property, *or* the color property
```C
typedef union {
    int wears_wig;
    char color[20];
} hair_t

typedef struct {
    int bald,
    hair_t hair;
} hair_info_t
```
Example using a union:
```C
if(hair_info_t.bald)
    if(hair_info_t.wears_wig)
        printf("wig\n");
else
    //print hair_info_t.hair.color
```

## Chapter 11 Text and Binary File Pointers

declare and open: (text file)
```C
FILE *infilep, *outfilep;
infilep = fopen("data.txt","r");
infilep = fopen("results.txt","w");
```
when writing to a binary file, include the size of that data type: 
```C
fwrite(&i, sizeof(int), 1, binaryp);
```
In the above example:
- &i is the address of first memory cell whose contents are to be copied to the file
- sizeof(int) is the number of bytes to be copied
- 1 is the number of values to write
- binaryp is the file pointer `"wb"` for write binary

`fwrite()` and `fread()` also take 4 arguments
1. address of the first memory cell to fill
2. size of 1 value
3. max number of elements to copy from the file into memory
4. file pointer to `"rb"` file

## Chapter 12 Programming in the Large

Include own file with `include "file.h"`, file.cpp will also be included if it includes file.h

5 Variable Prefixes:
1. `auto`: a local variable or formal parameters that are automatically allocated and deallocated on the stack, this is what's used by default
1. `extern`: Functions prototyped in external .h file need 'extern' prefix to mark that it will be defined later, but function prototypes in .h files are external by default so it's redundant, unless you're doing an inline declaration:
    ```C
    extern inline int add1(int x){return x+1;}
    ```
2. `global`: scope extends to the end of the file unless redeclared for that block
3. `static`: remains between calls if inside a functioon, sometimes used for programms with small run-time stacks for large arrays
4. `register`: same function as 'auto', but designates the memory cell will be access more often than most, to be placed inside the CPU if possible. ex. index variable of a large array
    ```C
    static double matrix[50][40];
    register int row,col;
    ```

Program exit function: `exit()` from `stdlib.g` terminates the program, usefull for logic errors. `exit(1)` imples a fail, `exit(0)` implies no fail

Conditional Compilation:
```C
#define VARIABLE_1 12
#if defined(VARIABLE_1)
    /* the code here will be compiled*/
#endif
#if defined(VARIABLE_2)
    /* the code here will NOT be compiled*/
#endif
```

Program input arguments:
- can use input arguments in main() when running the program from the command line:
- the input arguments include the name of the compiled program
    - zsh: `prog opt1 opt2`
    ```C
    void main(int argc /*input argument count*/, char *argv[] /*input argument vector*/){}
    ```
    In this example, the formmal paramters of main would have these values:
    - zsh: `prog  input.txt output.txt`
        - argc = 3
        - argv[0] = "prog"
        - argv[1] = "input.txt"
        - argv[2] = "output.txt"
        - argv[3] = ""
        
### 12.8 Macros with Parameters

Like `#define` works with contants by replacing the name with the value at compile time, the same can be done with a "function". This takes up more memory than a typical function call, since each instance is replaced with the entire function syntax. It is most useful for 1-liners for readability
ex:
```C
define LABEL_PRINT(label,num) printf("%s = %d",(label),(num))

//called as:
LABEL_PRINT(label,num);
//compiled as:
printf("%s = %d",(label),(num));
```
Use parenthesis since unlike a function, it will not return the result first
```C
#define squ1(n) n*n
#define squ2(n) ((n)*(n))

int num = 16/squ1(2);
//above will compile as:
int num = 16/4*4; //which equals 16, not the inteneded 16/4 = 2

int num = 16/squ2(2);
//above will compile as:
int num = 16/((2)*(2)); //which equals 4, as intended
```
You can define multi-line marcos by ending every line except for the last with a backslash
```C
#define square(n) \
    ((n)*(n))
```

## Chapter 13: Pointers and Dynamic Data Structures
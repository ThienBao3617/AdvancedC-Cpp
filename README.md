# **LESSON 1: COMPILER AND MACRO**

## A. COMPILER        
***How to make a program for computer?***   
***->Step 1***: Write the source codes (.c) and header files (.h).   
***->Step 2***: Pre-process the source codes according to
the preprocessor directives. The preprocessor directives
begin with a hash sign (#), such as #include and #define.
They indicate that certain manipulations (such as including
another file or replacement of symbols) are to be performed
BEFORE compilation.   
***->Step 3***: Compile the pre-processed source codes into object
codes (.obj, .o).   
***->Step 4***: Link the compiled object codes with other object
codes and the library object codes (.lib, .a)to produce the
executable code (.exe).  
***->Step 5***: Load the executable code into computer memory.  
***->Step 6***: Run the executable code.   
![alt text](assets/flow%20chart.png)

## B. MACRO   
So MACRO is a word used to refer to the information processed in the preprocessor. Divided into 3 main groups:    
    - Header or Library files: #include  
    - Replace macro_name by macro_value before compile to the .bin file: #define, #undef   
    - Conditional compilation directives: #if, #elif, #else, #ifdef, #ifndef   

***Example 1:***   
#if condition_1   
TODO 1;  
#elif condition_1   
TODO 2;   
#else   
TODO 3;   
#endif  
***=>explaination***: If "condition_1" is true, then TODO 1 is built. If condition_2 is true, then TODO 2 is selected to build. If conditions_1 and 2 are both false, then TODO 3 is selected for build.


***Example 2:***    
#ifdef macro  
TODO 1;   
#else  
TODO 2;   
#endif   
***=>explaination***: If the macro is already defined by #define macro, then TODO 1 is selected to build. If not defined, TODO 2 is selected to build.

***Example 3:***   
#ifndef macro  
TODO 1;   
#else  
TODO 2;   
#endif   
***=>explaination***: In the opposite way compare to #ifdef. If the macro is not defined, then TODO 1 is selected to build. If already defined, TODO 2 is selected to build.

***Code example:***   

    #include <stdio.h>      
    typedef enum
    {
        GPIOA,
        GPIOB,
        GPIOC
    } Ports;
    
    typedef enum{
        PIN1,
        PIN2,
        PIN3,
        PIN4,
        PIN5,
        PIN6,
        PIN7,
    } Pins;

    typedef enum
    {
        HIGH,
        LOW
    } Status;

    #define STM32 0
    #define ATMEGA 
    #define PIC 2
    
    #define MCU STM32
    
    #if MCU == STM32
    void daoTrangThaiDen(Ports port, Pins pin, Status status)
    {
        if (status == HIGH)
        {
            HAL_GPIO_WritePin(port, pin, LOW);
        }
        else
        {
            HAL_GPIO_WritePin(port, pin, HIGH);
        }  
    }

    #elif MCU == ATMEGA 
    void daoTrangThaiDen(Pins pin, Status status)
    {
        if (status == HIGH)
        {
            digitalWrite(pin, LOW);
        }
        else
        {
            digitalWrite(pin, HIGH);
        }  
    }

    #endif
    void delay(int ms){}
    
    int main()
    {
        while(1)
        {
            daoTrangThaiDen(GPIOA,13,HIGH);
            delay(1000);
        }

    return 0;
    }


# **LESSON 2: STDARG AND ASSERT**

## A. STDARG
***Concept***    
The stdarg.h header file in C allows functions to accept a variable number of arguments. It provides macros and a type (va_list) for accessing and manipulating these arguments. 

📝 ***Key Features of stdarg.h***  
**va_list**: A type that represents a list of arguments.  
**va_start(ap, last_named_arg)**: Initializes a va_list object to point to the first unnamed argument after last_named_arg.   
**va_arg(ap, type)**: Retrieves the next argument from the va_list and converts it to the specified type.   
**va_end(ap)**: Cleans up the va_list object.

***Example***  

    #include <stdio.h>  
    #include <stdarg.h>               
    /* print all args one at a time until a negative argument is seen;
    all args are assumed to be of int type */

    void printargs(int arg1, ...)  
    {  
        va_list ap;  
        int i;
        va_start(ap, arg1);   
        for (i = arg1; i >= 0; i = va_arg(ap, int))  
        printf("%d ", i);  
        va_end(ap);  
        putchar('\n');  
    }

    int main(void)  
    {  
        printargs(5, 2, 14, 84, 97, 15, -1, 48, -1);  
        printargs(84, 51, -1, 3);  
        printargs(-1);  
        printargs(1, -1);  
        return 0;  
    }

**Output**

    5 2 14 84 97 15  
    84 51

    1


## B. ASSERT
***Concept***  
- Asserts are used in programs if the developer wishes to assert or make assumptions.  
- It takes an expression for the parameter in the function. The parameter is evaluated.   
- If the value returned after evaluation of the expression is 0 or FALSE, it returns the expression along with the file name and line of execution as an error.  
- If the errors occur, the program calls the abort() function. The assert function does not do anything if the expression is evaluated TRUE.

***Syntax***  

        void assert( int expression);  
        
***Example***  

    #include <assert.h>
    #include <stdio.h>
    int main()
    {
        int a;
        char str[50];
            
        printf("Nhap mot gia tri nguyen: \n");
        scanf("%d", &a);
        assert(a >= 10);
        printf("Gia tri nguyen vua nhap la %d\n", a);
            
        printf("Nhap mot chuoi: ");
        scanf("%s", &str);
        assert(str != NULL);
        printf("Chuoi vua nhap la: %s\n", str);
            
        return(0);
    }

    
**Output 1**

![alt text](assets/output.png)

**Output 2**

![alt text](assets/output2.png)


# **LESSON 3: POINTER**

## A. Pointer  
***Concept***  
In the C programming language, a pointer is a variable that contains the memory address of another variable. The use of the pointer helps us to perform operations on memory in a more flexible way. 

***How to declare:***  

    int *ptr;  // a pointer to int type
    char *ptr_char;  // a pointer to char type
    float *ptr_float;  // a pointer to float type

***Get the address of a variable and access the value:***

    int x = 10;
    int *ptr_x = &x;  // ptr_x now contains address of x
    int y = *ptr_x;  // y equals to the value of x

***The size of the pointer depends on the computer architecture and compiler:***

    #include <stdio.h>

    int main() 
    {
        int *ptr;
        printf("Size of pointer: %d bytes\n", sizeof(ptr));
        return 0;
    }

***Example***

    #include <stdio.h>
    void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    int main()
    {
        int a = 10, b = 20;
        swap(&a, &b);

        printf("value a is: %d\n", a);
        printf("value b is: %d\n", b);

        return 0;
    }

## B. Void Pointer
***Concept***  
Void pointers are often used to point to any address without knowing the data type of the value at that address.

***Syntax***

    void *ptr_void;

***Example***

    #include <stdio.h>
    #include <stdlib.h>

    int sum(int a, int b)
    {
        return a+b;
    }

    int main() 
    {
    
        char array[] = "Hello";
        int value = 5;
        double test = 15.7;
        char letter = 'A';
    
        void *ptr = &value;
        printf("value is: %d\n", *(int*)(ptr));

        ptr = &test;
        printf("value is: %f\n", *(double*)(ptr));

        ptr = &letter;
        printf("value is: %c\n", *(char*)(ptr));

        ptr = sum;
        printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));

        void *ptr1[] = {&value, &test, &letter , sum, array};

        printf("value: %d\n", *(int*)ptr1[0]);

        printf("value: %c\n", *((char*)ptr1[4]+1));

        return 0;
    }

## C. Function Pointer
***Concept***  
A pointer to function is a variable that holds the address of a function. That is, it points to the area of memory that contains the machine code of the function defined in the program.

***Syntax***

    <return_type> (*<name_of_pointer>)( <data_type_of_parameters> );

***Example***

    #include <stdio.h>

    void sum(int a, int b)
    {
        printf("Sum of %d and %d is: %d\n",a,b, a+b);
    }

    void subtract(int a, int b)
    {
        printf("Subtract of %d by %d is: %d \n",a,b, a-b);
    }

    void multiple(int a, int b)
    {
        printf("Multiple of %d and %d is: %d \n",a,b, a*b );
    }

    void divide(int a, int b)
    {
        if (b == 0)
        {
            printf("Mau so phai khac 0\n");
            return;
        }
        printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
    }

    void calculator(void (*ptr)(int, int), int a, int b)
    {
        printf("Program calculate: \n");
        ptr(a,b);
    }


    int main()
    {
        // Method 1: Use the Calculator function,then replace the address of the function to calculate for the function pointer
        calculator(sum,5,2);
        calculator(subtract,5,2);
        calculator(multiple,5,2);
        calculator(divide,5,2);

        // Method 2: create an array containing function pointers for each function separately
        void (*ptr[])(int, int) = {sum, divide, multiple};
        ptr[0](5,6);

        return 0;
    }

**Output**

    Program calculate: 
        Sum of 5 and 2 is: 7
        Subtract of 5 by 2 is: 3 
        Multiple of 5 and 2 is: 10 
        5 divided by 2 is: 2.500000 

## D. Pointer to Constant
***Concept***  
A way of defining a pointer cannot change the value at the address it points to through a dereference, but the value at that address can change.

***Syntax***

    int const *ptr_const; 
    const int *ptr_const;

***Example***

    #include <stdio.h>
    #include <stdlib.h>

    int main() 
    {
        
        int value = 5;
        int const *ptr_const = &value;

        //*ptr_const = 7; // wrong
        //ptr_const++; // right
        
        printf("value: %d\n", *ptr_const);

        value = 9;
        printf("value: %d\n", *ptr_const);

        return 0;
    }

## E. Constant Pointer
***Concept***  
Defines a pointer whose value points to (address) cannot be changed. It means, when this pointer is initialized, it will not be able to point to another address.

***Syntax***

    int *const const_ptr = &value;

***Example***

    #include <stdio.h>
    #include <stdlib.h>


    int main() 
    {
        
        int value = 5;
        int test = 15;
        int *const const_ptr = &value;

        printf("value: %d\n", *const_ptr);

        *const_ptr = 7;
        printf("value: %d\n", *const_ptr);

        //const_ptr = &test; // wrong
        
        return 0;
    }

## F. Pointer to Pointer
***Concept***  
Pointer to Pointer is a data type in a programming language that allows you to store the address of a pointer. Pointer to pointer provides a new pointing rank, allowing you to change the value of the original pointer. This rank can be useful in many situations, especially when you work with functions that need to change the value of the pointer.

***Example***

    #include <stdio.h>

    int main() 
    {
        int value = 42;
        int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

        int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

        /*
            **ptr2 = &ptr1
            ptr2 = &ptr1;
            *ptr2 = ptr1 = &value;
            **ptr2 = *ptr1 = value
        */

        printf("address of value: %p\n", &value);
        printf("value of ptr1: %p\n", ptr1);

        printf("address of ptr1: %p\n", &ptr1);
        printf("value of ptr2: %p\n", ptr2);

        printf("dereference ptr2 first time: %p\n", *ptr2);

        printf("dereference ptr2 second time: %d\n", **ptr2);

        return 0;
    }

## G. NULL Pointer
***Concept***  
- A null pointer is a pointer that does not point to any specific object or memory area. In the C programming language, a pointer can be assigned a NULL value to represent the null state.

- Using a null pointer is often useful to check if a pointer has been initialized and points to a valid memory area. Avoiding dereferencing (using the value that the pointer points to) a null pointer is important to avoid program errors.

***Example***

    #include <stdio.h>

    int main() 
    {
        int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000

        if (ptr == NULL) 
        {
            printf("Pointer is NULL\n");
        } 
        else 
        {
            printf("Pointer is not NULL\n");
        }

        int score_game = 5;
        if (ptr == NULL)
        {
            ptr = &score_game;
            *ptr = 30;
            ptr = NULL;
        }
        

        return 0;
    }

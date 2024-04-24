#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *error_message;

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == (x)) printf("%s\n", error_message);
#define THROW(x, ERROR_CODE) {error_message = #ERROR_CODE; longjmp(buf, (x));}

double divide(int a, int b) 
{
    if (b == 0) 
    {
        THROW (1, ERROR: Divide by 0!!!);
    } 
    if(a * b <= 0)
    {
        THROW(2, ERROR: Another error has occured!!!);
    }
    
    return (double) a / b;
}

int main() 
{
    int a = 36; int b = 17;
    TRY printf("Result of %d / %d = %.2f\n", a, b, divide(a, b));
    CATCH (exception_code); 
    return 0;
}
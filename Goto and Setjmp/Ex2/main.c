#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code; 
char *error_message;
enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x) 
#define THROW(x, ERROR_CODE) do {error_message = #ERROR_CODE; longjmp(buf, x);} while(0) 

void readFile() 
{
    printf("Reading file...\n");
    THROW(FILE_ERROR, READ ERROR: FILE NOT EXIST!);
}
    
void networkOperation() 
{
    printf("Operating network...\n");
    THROW(NETWORK_ERROR, OPERATE ERROR: NETWORK NOT EXIST!);
}
    
void calculateData() 
{
    printf("Caculating data...\n");
    THROW(CALCULATION_ERROR, CACULATE ERROR: DATA NOT EXIST!);
}

int main() 
{
    TRY 
    {
        readFile();
        networkOperation();
        calculateData();
    } 
    CATCH(FILE_ERROR) 
    {
        printf("%s\n", error_message);
    } 
    CATCH(NETWORK_ERROR) 
    {
        printf("%s\n", error_message);
    }
    CATCH(CALCULATION_ERROR) 
    {
        printf("%s\n", error_message);
    }
}

    
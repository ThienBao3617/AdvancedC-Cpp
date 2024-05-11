#include <stdio.h>

#define LED1 1 << 0 // 0001
#define LED2 1 << 1 // 0010
#define LED3 1 << 2 // 0100
#define LED4 1 << 3 // 1000


void enableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT |= LED;
}

void disableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT &= ~LED;
}


int main() {
    unsigned int GPIO_PORT = 0; // suppose this is a control variable of GPIO port

    // turn on led 1 and led 3
    enableLED(&GPIO_PORT, LED1 | LED3);
    if (GPIO_PORT & LED1 ) printf("LED 1 is on\n");
    else printf("LED 1 is off\n");

    if (GPIO_PORT & LED2 ) printf("LED 2 is on\n");
    else printf("LED 2 is off\n");

    if (GPIO_PORT & LED3 ) printf("LED 3 is on\n");
    else printf("LED 3 is off\n");
    
    if (GPIO_PORT & LED4 ) printf("LED 4 is on\n");
    else printf("LED 4 is off\n");
    
    printf("\n");
    
    // turn off led 1 and turn on led 3
    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    if (GPIO_PORT & LED1 ) printf("LED 1 is on\n");
    else printf("LED 1 is off\n");

    if (GPIO_PORT & LED2 ) printf("LED 2 is on\n");
    else printf("LED 2 is off\n");

    if (GPIO_PORT & LED3 ) printf("LED 3 is on\n");
    else printf("LED 3 is off\n");
    
    if (GPIO_PORT & LED4 ) printf("LED 4 is on\n");
    else printf("LED 4 is off\n");
    
    printf("\n");

    // turn on led 4
    enableLED(&GPIO_PORT, LED4);
    
    if (GPIO_PORT & LED1 ) printf("LED 1 is on\n");
    else printf("LED 1 is off\n");

    if (GPIO_PORT & LED2 ) printf("LED 2 is on\n");
    else printf("LED 2 is off\n");

    if (GPIO_PORT & LED3 ) printf("LED 3 is on\n");
    else printf("LED 3 is off\n");
    
    if (GPIO_PORT & LED4 ) printf("LED 4 is on\n");
    else printf("LED 4 is off\n");
    
    return 0;
}



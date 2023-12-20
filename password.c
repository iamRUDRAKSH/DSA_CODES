#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Program to generate a random 4 digit password
int main() {
    int upper = 9999, lower = 1000;
    int number, password;

    srand(time(NULL));

    number = rand();

    if(number % 3 == 0)
       password = (number % (2500 - 1000 + 1)) + 1000;
    else if(number % 5 == 0)
        password = (number % (5000 - 2500 +1)) + 2500;
    else if(number % 7 == 0)
        password = (number % (7500 - 5000 + 1)) + 5000;
    else 
        password = (number % (9999 - 7500 + 1)) + 7500;

    printf("Suggested password : %d\n", password);               
    return 0; 
}
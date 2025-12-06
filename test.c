// Sample program to test lexical analyzer
 
#include <stdio.h>
#define PI 3.14
 
int main() {
    // Variable declarations
    int a = 10, b = 20;
    float c = 15.5, area;
    char grade = 'A';
    const int LIMIT = 100;
 
    // Arithmetic operations
    area = a  b + (int)c / 2 - 5;
 
    // Relational & logical operators
    if ((a < b) && (c >= 10.0)) {
        printf("a is less than b and c is valid\n");
    } else if (a == b || c != 15.5) {
        printf("Alternate condition met\n");
    } else {
        printf("No conditions met\n");
    }
 
    // Loop test
    for (int i = 0; i < 5; i++) {
        area += i;
    }
 
    // While loop test
    while (a < LIMIT) {
        a++;
    }
 
    // Do-while loop
    do {
        b--;
    } while (b > 10);
 
    // Switch-case
    switch (grade) {
        case 'A':
            printf("Excellent\n");
            break;
        case 'B':
            printf("Good\n");
            break;
        default:
            printf("Invalid grade\n");
    }
 
    // Function call
    printResult(area);
 
    return 0;
}
 
void printResult(float value) {
    printf("Final Area: %f\n", value);
}
 
 
#include <stdio.h>
int  main()
{
    int num=102;
    float a = 11.5F;
    printf("helloprintf hello hi");
    printf["hello "];
    printf "helloprintf ];
    int array[5];
    {
 
        'a';
            'a;
 
            {
            }
  int num=0x23456k,num = 01283,num   =    0b123;
    int value = 12112,i=0123,i=0b101010,i=0x121abcde;
    char = 'tb';
    num %n;
            printf("Invalid grade\n");
    num >>= 1;
    );
    num++;
}

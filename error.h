#define ERROR_H 

int interr(char word[]); // for checking errors on identifier eg: int 1varible_name;
int hexcheck(char word[]); // for checking errors on hexadecimal
int bincheck(char word[]); // for checking errors on binary
int floatcheck(char word[]); // for checking errors on float numbers
int octcheck(char word[]); // for checking errors on octal numbers


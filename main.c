#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int binary_to_decimal(int binary);
int square_root(int number, int roots);
int to_decimal(int number, int base);
int decimal_to(int number, int base);
int hexa_to_decimal(char number[]);
/*
    SAYAR WIN HTUT DSA UNIT-3 CONVERSATION (all in one)
*/
int main()
{
    decimal_to(8284, 16);
    int first_system, second_system;
    printf("Choose first system 1.binary, 2.decimal, 3.octal, 4.hexadecimal: ");
    scanf("%d", &first_system);
    printf("Choose second system 1.binary, 2.decimal, 3.octal, 4.hexadecimal: ");
    scanf("%d", &second_system);
    change(first_system, second_system);
    return 0;
}
int change(int first, int second){
    int number,decimal;
    if(first == 1 || first == 2 || first == 3){
        printf("enter your number: ");
        scanf("%d", &number);
    }
    if(first == second){
        printf("result is %d", number);
        return 3;
    }
    if(first == 1){
       decimal = to_decimal(number, 2);
       if(second == 2){
            printf("result is %d", decimal);
       }else if(second == 3){
            decimal_to(decimal, 8);
       }else if(second == 4){
            decimal_to(decimal, 16);
       }
    }else if(first == 2){
        if(second == 1){
            decimal_to(number, 2);
        }else if(second == 3){
            decimal_to(number, 8);
        }else if(second == 4){
            decimal_to(number, 16);
        }
    }else if(first == 3){
        decimal = to_decimal(number, 8);
        if(second == 1){
            decimal_to(decimal, 2);
        }else if(second == 2){
            printf("result is %d", decimal);
        }else if(second == 4){
            decimal_to(decimal, 16);
        }
    }else if(first == 4){
        char hexa[100];
        printf("Enter your number: ");
        scanf("%s", &hexa);
        decimal = hexa_to_decimal(hexa);
        if(second == 1){
            decimal_to(decimal, 2);
        }else if(second == 2){
            printf("result is %d", decimal);
        }else if(second == 3){
            decimal_to(decimal, 8);
        }
    }
}
int to_decimal(int number, int base){
    int length=0, i=0, decimal= 0, reminder, power;
    while(number !=0){
        reminder = number % 10;
        if(reminder >= base){
            number = 0;
            printf("valid number\n");
            return number;
        }
        decimal = decimal + (reminder * square_root(base, i));
        number = number / 10;
        i++;
    }
    if(number == 0){
        return -1;
    }else{
        return decimal;
    }
}
int decimal_to(int number, int base){
    char result[200];
    int reminder,i=0,x=0;
    while(number != 0){
        reminder = number % base;
        number = number /base;
        result[i] = reminder;
        i++;
    }
    printf("result value is ");
    for(x=i-1;x>=0;x--){
        if(result[x] > 9){
            printf("%c", result[x] + 55);
        }else{
            printf("%d", result[x]);
        }
    }
    printf("\n");
    return 2;
}
int hexa_to_decimal(char number[]){
    int reminder = 0,decimal = 0,length=0, i=0;
    while(number[length] != 0){
        length++;
    }
    while(length !=0 ){
        if(number[i] >= '0' && number[i] <= '9'){
            decimal += (number[i] - 48) * square_root(16, length - 1);
        }else if(number[i] >= 'A' && number[i] <= 'F'){
            decimal += (number[i] - 55) * square_root(16, length - 1);
        }else if(number[i] >= 'a' && number[i] <='f'){
            decimal += (number[i] - 87) * square_root(16, length - 1);
        }
        i++;
        length--;
    }
    return decimal;
}
int square_root(int number, int roots){
    int result=number;
    if(roots == 0){
        return 1;
    }
    for(int i=1;i<roots;i++){
        result *= number; // 0=2 * 2, 4 += 2*2 = 8
    }
    return result;
}

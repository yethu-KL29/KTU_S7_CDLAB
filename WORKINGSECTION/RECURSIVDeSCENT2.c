#include <stdio.h>
#include <string.h>
#include <ctype.h>

char inp[10];

void E();
void T();
void Eprime();
void Tprime();
void F();
int i = 0;
int main(){

    i = 0;
   
    printf("Enter an arithmetic expression   :  "); // Eg: a+a*a
    gets(inp);
    E();
    if (strlen(inp) == i )
        printf("\nAccepted..!!!\n");
    else
        printf("\nRejected..!!!\n");

    return 0;
}

void E()
{
    T();
    Eprime();
}
void Eprime(){
    if(inp[i]=='+'){
        i++;
        T();
        Eprime();
    }
}
void T(){
    F();
    Tprime();
}


void Tprime()
{
    if (inp[i] == '*')
    {   i++;
        F();
        Tprime();
    }
}


void F(){
    if (isalnum(inp[i])){
        i++;

    }
    else if(inp[i]=='('){
        i++;
        E();
         if (inp[i] == ')')
            i++;
        
        
    }
   
   
}

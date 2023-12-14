#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char a[20],stk[50];
int c, i = 0 , j = 0 ,z;
void check();
int main(){

    printf("enter the input string\n");
    scanf("%s",a);

    c = strlen(a);

    for (i=0,j=0;j<c;i++,j++){
        if(a[j]=='i' && a[j+1]=='d'){
            stk[i]=a[j];
            stk[i+1]=a[j+1];
            stk[i+2]='\0';
            a[j]=a[j+1]=' ';
            printf("\n$%s\t%s$\t%sid",stk,a,"SHIFT");
            check();
        }
        else{
            stk[i]=a[j];
            a[j]=' ';
            stk[i+1]='\0';
            printf("\n$%s\t%s$\t%sid",stk,a,"SHIFT");
            check();

        }
    }

    

    
}


void check(){
    for(z=0;z<c;z++){
        if(stk[z]=='i'&&stk[z+1]=='d'){
            stk[z]='E';
            stk[z+1]='\0';
            j++;
            printf("\n$%s\t%s$\t%sid",stk,a,"REDUCE");
        }
        
    }
    for(z=0;z<c;z++){
        if(stk[z]=='E'&&stk[z+1]=='*' && stk[z]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            i=i-2;
            printf("\n$%s\t%s$\t%sid",stk,a,"REDUCE");
        }
        
    }
    for(z=0;z<c;z++){
        if(stk[z]=='('&&stk[z+1]=='*' && stk[z]==')'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            i=i-2;
            printf("\n$%s\t%s$\t%sid",stk,a,"REDUCE");
        }
        
    }
     for(z=0;z<c;z++){
        if(stk[z]=='E'&&stk[z+1]=='+' && stk[z]=='E'){
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            i=i-2;
            printf("\n$%s\t%s$\t%sid",stk,a,"REDUCE");
        }
        
    }
}
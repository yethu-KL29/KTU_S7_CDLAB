%token A B 






%%
stmt : s B 
{
    printf("Valid\n");
    exit(0);
}
;

s : A s
  | A
;
%%



int yyerror(char *msg)
{
    printf("Invalid String\n");
    exit(0);
}

int main()
{
    printf("Enter the String:\n");
    yyparse();
    return 0;
}

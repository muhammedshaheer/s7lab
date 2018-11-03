#include<stdio.h>
#include<ctype.h>

char stack[20];
int top = -1;
 
void push(char x)
{
        stack[++top] = x;
}
 
int pop()
{
        return stack[top--];
}
 
int main(int argc, char *exp[])
{
        char *e;
        char n1,n2,n3,num;
        int counts = 0;
        e = exp[1];
        while(*e != '\0')
        {
                if(! ( *e == '+' || *e == '-' || *e == '*' || *e == '/' ))
                        push(*e);
                else
                {
                        n1 = pop();
                        n2 = pop();
                        switch(*e)
                        {
                                case '+':
                                {
                                		printf("%c = %c + %c\n", 'I'+counts, n2, n1);
                    					break;
                                }
                                case '-':
                                {
                                        printf("%c = %c - %c\n", 'I'+counts, n2, n1);
                                        break;
                                }
                                case '*':
                                {
                                        printf("%c = %c * %c\n", 'I'+counts, n2, n1);
                                        break;
                                }
                                case '/':
                                {
                                        printf("%c = %c / %c\n", 'I'+counts, n2, n1);
                                        break;
                                }
                        }
                        push('I' + counts);
                        counts = counts + 1;
                }
                e++;
        }
        return 0;
 
}

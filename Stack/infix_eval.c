#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define cls system("cls");
int nums[50], tn = -1, to = -1;
char op[49];
void pushnum(int n)
{
nums[++tn] = n;
}
void pushop(char ch)
{
op[++to] = ch;
}
int popnum()
{
return nums[tn--];
}
char popop()
{
return op[to--];
}
int infpre(int numbers[50], char op[49])
{
int x, y;
char opa;
x = popnum();
y = popnum();
opa = popop();
switch (opa)
{
case '+':
return x + y;
case '-':
return y - x;
case '*':
return x * y;
case '/':
if (x == 0)
{
printf("\n\nCannot Divide by 0");
exit(1);
}
else
{
return y / x;
}
}
return 0;
}
int oper(char ch)
{
return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int preced(char chp)
{
switch (chp)
{
case '^':
return 3;
case '/':
case '*':
return 2;
case '+':
case '-':
return 1;
}
return -1;
}
int ans(char exp[100])
{
int i, num, res, r;
char c;
for (i = 0; exp[i] != '\0'; i++)
{
c = exp[i];
if (isdigit(c) != 0)
{
num = 0;
while (isdigit(c))
{
num *= 10;
num += (c - '0');
i++;
if (i < strlen(exp))
c = exp[i];
else
break;
}
i--;
pushnum(num);
}
else if (c == '(')
{
pushop(c);
}
else if (c == ')')
{
while (op[to] != '(')
{
r = infpre(nums, op);
pushnum(r);
}
popop();
}
else if (oper(c))
{
while (to != -1 && preced(c) <= preced(op[to]))
{
res = infpre(nums, op);
pushnum(res);
}
pushop(c);
}
}
while (to != -1)
{
res = infpre(nums, op);
pushnum(res);
}
return popnum();
}
int main()
{
char exp[50];
printf("Enter the infix: ");
fflush(stdin);
gets(exp);
printf("%d", ans(exp));
return EXIT_SUCCESS;
}
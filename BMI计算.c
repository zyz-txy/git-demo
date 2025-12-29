#include <stdio.h>
char evaBMI(double w,double h)
{
    if(w<0||h<0)
        return 'E';
    double b = w/h/h;
    if(b<18.5)
        return 'S';
    if(b>=18.5&&b<=24.0)
        return 'N';
    if(b<=24.0&&b<28.0)
        return 'O';
    if(b>=28)
        return 'F';
}
int main()
{
    double w,h;
    scanf("%lf%lf",&w,&h);
    char c = evaBMI(w,h);
    printf("%c",c);
    return 0;
}

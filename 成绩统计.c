//输入一堆0~100之间的成绩，以-1结束输入，求去掉一个最高分和一个最低分后的平均分，结果保留两位小数。
#include <math.h>
#include <stdio.h>
int main()
{
    double n;
    double sum = 0;
    double max = 0.0;
    double min = 100.0;
    int cnt = 0;
    while(1)
    {
        scanf("%lf",&n);
        if(fabs(n+1.0)<1e-6)
            break;
        if(n<0.0||n>100.0)
            continue;
        if(n>=max)
            max = n;
        if(n<=min)
            min = n;
        sum += n;
        cnt++;
    }
    double ave = (sum-min-max)/(cnt-2);
    printf("%.2f\n",ave);
    return 0;
}

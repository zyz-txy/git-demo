#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int ReadLine(char *s,FILE *fp,int n)
{
    int i = 0;
    int ch = 0;

    if(s==NULL||fp==NULL||n<1)
        return 0;
    else{
        rewind(fp);
        while(n!=1&&ch!=EOF)
        {
            ch=fgetc(fp);
            if(ch=='\n')
                n--;
        }
    }
    while((ch=fgetc(fp))!=EOF&&ch!='\n'&&i<200){
        if((ch<='a'&&ch<='z')||(ch==' '))
        {
            s[i++]=ch;
        }
    }
    s[i]='\0';
    return i;
}

int CountLine(FILE *fp ,int n)
{
    int alpha[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    char str[200]={0};
    int len,i,keys=0;

    if(fp==NULL||n<1)
        return 0;
    ReadLine(str,fp,n);
    len = strlen(str);

    if(len==0)
        return 0;
    for(i =0;i<len;i++)
    {
        if(str[i]>='a'&&str[i]<='z')
            keys+=alpha[str[i]-'a'];
        else
            keys++;
    }
    return keys;
}

int main()
{
    FILE *fp = NULL;
    int a,b ,i;
    fp = fopen("test.dic","r");
    if(fp==NULL){
        puts("Cannot Open Input File.\n");
        exit(0);
    }else{
        scanf("%d%d",&a,&b);
        for(i=a;i<b;i++)
        {
            printf("%d\n",CountLine(fp,i));
        }
        fclose(fp);
    }
    return 0;
}
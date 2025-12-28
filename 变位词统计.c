#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 255

int countAnagrams(const char *, const char *); /* 统计变位词个数 */
int areAnagrams(const char *, const char *); /* 变位词判断 */

/* 辅助函数 */
int read_line(char *, int); /* 读入不超过指定长度的字符串 */
void lowcase(char *); /* 将字符串变为小写 */

int main()
{
    char text[STR_LEN + 1] = {'\0'};
    char word[STR_LEN + 1] = {'\0'};
    int cnt = 0;

    read_line(text, STR_LEN);
    read_line(word, STR_LEN);

    cnt = countAnagrams(text, word);

    printf("The text is \"%s\".\n", text);
    printf("The word is \"%s\".\n", word);
    printf("The count of anagrams is %d.\n", cnt);

    return 0;
}

/* 函数实现 */
/* 读入一行不超过指定长度的字符串 */
int read_line(char *str, int n)
{
    int ch, i = 0;

    /* 读入字符，直到遇到换行符 */
    while ((ch = getchar()) != '\n' && ch != '\r' && ch!=EOF)
    {
        if(i < n) /* 最大字符数 */ 
        { str[i++] = ch; }
    }
    str[i] = '\0'; /* 添加空字符'\0' */ 
    return i; /* 返回读入的字符数 */ 
}
int countAnagrams(const char *a, const char *b)
{
    int cnt = 0;
    char temp1[STR_LEN+1] = {'\0'};
    int len2 = strlen(b);
    int len1 = strlen(a);
    char *temp2;
    char *temp3;
    temp3 = (char*)malloc((len2+1)*sizeof(char));
    if(temp3==NULL)
        return 0;
    temp2 = (char*)malloc((len2+1)*sizeof(char));
    if(temp2==NULL)
        return 0;
    strcpy(temp1,a);
    strcpy(temp2,b);
    lowcase(temp1);
    lowcase(temp2);
    for(int i=0;i<=len1-len2;)
    {
        strncpy(temp3,temp1+i,len2);
        temp3[len2]='\0';
        if(areAnagrams(temp2,temp3))
        {
            cnt++;
            i+=len2;
        }
        else
            i++;
    }
    free(temp2);
    free(temp3);
    return cnt;

}
int areAnagrams(const char *a, const char *b)//判断是否互为变位数
{
    int i=0;
    int s[27]={0};
    int w[27]={0};
    int len1 = strlen(a);
    int len2 = strlen(b);
    if(len1!=len2)
        return 0;
    for(i = 0;i<len1;i++)
    {
        if(a[i]<'a'||a[i]>'z')return 0;
        if(b[i]<'a'||a[i]>'z')return 0;
    }
    for(i = 0;i<len1;i++)
    {
        s[a[i]-'a']++;
    }
    for(i = 0;i<len2;i++)
    {
        w[b[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(s[i]!=w[i])
            return 0;
    }
    return 1;
}
void lowcase(char *s)
{
    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            s[i] +=32;
    }
}


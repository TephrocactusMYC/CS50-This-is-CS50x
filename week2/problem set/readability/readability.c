#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    string input=get_string("Text: ");
    int letters=count_letters(input);
    int words=count_words(input);
    int sentences=count_sentences(input);
    //printf("%i,%i,%i",letters,words,sentences);
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
int count_letters(string text)
{
    int sum=0;
    for(int i=0;i<strlen(text);i++)
    {
        if(('a'<=text[i] && text[i]<='z')||('A'<=text[i] && text[i]<='Z'))
        sum+=1;
    }
    return sum;
}
int count_words(string text)
{
    int sum=0;
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]==' ')
        sum+=1;
    }
    return sum+1;
}
int count_sentences(string text)
{
    int sum=0;
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]=='.' || text[i]=='!' || text[i]=='?')
        sum+=1;
    }
    return sum;
}
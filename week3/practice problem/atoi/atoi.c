#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int num=0;
    // TODO
    if(input[0]=='\0')
    {
        return num;
    }
    else
    {
        int length = strlen(input) - 1;
        int lastByte = input[length] - '0';
        input[length] = '\0';
        num = convert(input);
        return num * 10 + lastByte;
    }

}
//这程序怎么导入了这么多没用的库，太6了
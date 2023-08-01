// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <string.h>
#include <cs50.h>
#include <stdio.h>
string replace(string a);
int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    string result = replace(argv[1]);

    printf("%s\n", result);
    return 0;
}


string replace(string a) {
    string result=a;
    int length = strlen(a);

    for (int i=0;i<length;i++)
    {
        switch (a[i]) {
            case 'a':
            case 'A':
                result[i] = '6';
                break;
            case 'e':
            case 'E':
                result[i] = '3';
                break;
            case 'i':
            case 'I':
                result[i] = '1';
                break;
            case 'o':
            case 'O':
                result[i] = '0';
                break;
            case 'u':
            case 'U':
                result[i] = 'u';
                break;
        }
    }
    return result;
}
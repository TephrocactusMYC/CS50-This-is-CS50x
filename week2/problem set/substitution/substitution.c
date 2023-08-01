#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
string casear(string plaintext,string key)
{
    string result=plaintext;
    for (int i=0;i<strlen(plaintext);i++)
    {
        if(islower(plaintext[i]))
        {
           result[i]=tolower(key[(int)plaintext[i]-97]);
        }
        else if(isupper(plaintext[i])){
            result[i]=toupper(key[(int)plaintext[i]-65]);
        }
        else
        {
            continue;
        }
    }
    return result;
}
int main(int argc, string argv[])
{
    if (argc < 2 || argc >= 3) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key)!= 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (key[i] == key[j]) {
                printf("Key must not contain duplicate characters.\n");
                return 1;
            }
        }
    }

    // Check for invalid characters
    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    string plaintext=get_string("plaintext: ");
    string ciphertext=casear(plaintext,key);
    printf("ciphertext: %s\n",ciphertext);
}
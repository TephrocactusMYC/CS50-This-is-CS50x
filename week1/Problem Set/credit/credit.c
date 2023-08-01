#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit = get_long("Number: ");
    int length = 0;
    int checksum =0;
    int tmp;
    while (credit > 0)
    {
        length+=1;
        if(length%2==1)
        {
            checksum+=credit%10;
        }
        else
        {
            checksum+=((credit%10)<<1)/10+((credit%10)<<1)%10;
        }
        credit/=10;
        if(credit>=10&& credit<100)
        {
            tmp=credit;
        }
    }
    if(checksum%10==0)
    {
        if ((tmp==34 || tmp==37) && length==15)
        {
            printf("AMEX\n");
        }
        else
        {
            if ((tmp==51 || tmp==52|| tmp==53|| tmp==54|| tmp==55) && length==16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                if (tmp/10==4 && (length==16 || length==13))
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
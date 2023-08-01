# TODO
from cs50 import get_int
def main():
    height=0
    while(height<1 or height>8):

        height=get_int("Height: ")

    for i in range(1, height+1):
        for  j in range(1, height+1):
            if (j <= height - i):
                print(" ",end='');
            else:
                print("#",end='');
        print("  ",end='');
        for j in range(1,i+1):
            print("#",end='');
        print("\n",end='');


main()
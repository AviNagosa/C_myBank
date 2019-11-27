#include "myBank.h"

int main()
{
    printf("Transacion type?: ");
    char ch = getchar();
    while(getchar()!='\n');
    printf("\nYou Choose : %c \n",ch);

    while(ch != 'E')
    {

        if(ch == 'O')openAccount();
        else if(ch =='B')Balance();
        else if(ch == 'D')Deposit();
        else if(ch =='W')Withdrawal();
        else if(ch =='C')closeAccount();
        else if(ch =='I')interestRate();
        else if(ch =='P')printOpenAccount();
           
        else printf("\nThis transacion is not exist, try again\n");

        printf("Transacion type?: ");
        ch = getchar();
        while(getchar()!='\n');
        printf("\nYou Choose : %c \n",ch);
    }
    closeAll();

    return 0;
}


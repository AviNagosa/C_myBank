#include "myBank.h"

//global integer who count how much open bank account there is
int countAccount = 0;  


//create new account if there any close account
void openAccount()
{
     //if there place for new bank account,create and initial first deposit.
     if(countAccount < 50)
     {
           printf("Initial deposit?: ");
           bankAccounts[countAccount][0] = 1;   //change the account to open 
           
           double num = 0;
           while(scanf("%lf",&num)!=1)
           {
               printf("valid input, try again : ");
               while(getchar()!='\n');
           }
           while(getchar()!='\n');     
           
           //initial the deposit 
           bankAccounts[countAccount][1] = num;
           printf("Your account number is : %d \n",countAccount+901);
           printf("deposit : %.2lf\n",bankAccounts[countAccount][1]);
           //move to the next emptey account
           countAccount++;
     }
     else printf("Sorry, there is no more place in this bank"); 
}

void Balance()
{

     int AccountNumber = ifAccountOpen();

     if(AccountNumber!=0)
     {
         if(AccountNumber==901)AccountNumber=0;
         printf("The balance in account number %d is %.2lf\n",AccountNumber+901,bankAccounts[AccountNumber][1]);
     }
     
}

int ifAccountOpen()
{ 

     int AccountNumber = 0,flag = 1;
     printf("Account number?: ");
     scanf("%d",&AccountNumber);
     while(getchar()!='\n');
     while(flag)
     {
          if(AccountNumber>900 && AccountNumber< 951)
          {
             if(bankAccounts[AccountNumber-901][0]==1)
             {
                 printf("Hello, this account is open\n"); 
                 if(AccountNumber==901) return 901;
                 return AccountNumber-901;
             } 
             else
             {
                 printf("This account is close !!!\n");
                 return 0;
             }
          }
          else
          {
              printf("Valid input!!! the range is between 901 to 950, try again.\n");
              printf("Account number?: ");
              scanf("%d",&AccountNumber);
              while(getchar()!='\n');
          }
     }
     return 0;

}


void Deposit()
{

     double totalSum = 0 , amount = 0;
     int AccountNumber = ifAccountOpen();
     if(AccountNumber!=0)
     {
           if(AccountNumber==901)AccountNumber=0;
           printf("Amount?: ");        
           while(scanf("%lf",&amount)!=1)
           {
               printf("valid input, try again : ");
               while(getchar()!='\n');
           }
           while(getchar()!='\n');     
           
           totalSum = amount + bankAccounts[AccountNumber][1];
           bankAccounts[AccountNumber][1] = totalSum;

           printf("Total sum after deposit : %.2lf\n",bankAccounts[AccountNumber][1]);
     }
     
}

void Withdrawal()
{

     double amount = 0;
     int AccountNumber = ifAccountOpen();
     if(AccountNumber!=0)
     {
         if(AccountNumber==901)AccountNumber=0;
         printf("Amount?: ");        
         while(scanf("%lf",&amount)!=1)
         {
             printf("valid input, try again : ");
             while(getchar()!='\n');
         }
         while(getchar()!='\n');    
         if(bankAccounts[AccountNumber][1]>=amount)
         {
              bankAccounts[AccountNumber][1] = bankAccounts[AccountNumber][1] - amount;
              printf("Total sum after withdrawal : %0.2lf\n",bankAccounts[AccountNumber][1]);
         }
         else printf("You don't have enough money!!\n");
     }    

}

void closeAccount()
{

     int AccountNumber = ifAccountOpen();

     if(AccountNumber!=0)
     {
         if(AccountNumber==901)AccountNumber=0;
         bankAccounts[AccountNumber][1] = 0;
         bankAccounts[AccountNumber][0] = 0;
         printf("Your account is closed!!");
         countAccount--;
     }
     
}

void interestRate()
{
     double interestRate = 0;
     printf("interest_rate?: ");        
     while(scanf("%lf",&interestRate)!=1)
     {
           printf("valid input, try again : ");
           while(getchar()!='\n');
     }
     while(getchar()!='\n');  
     for(int i = 0 ; i < row ; i++){
         if(bankAccounts[i][0]==1)bankAccounts[i][1] = (bankAccounts[0][1])*(1.0+(interestRate/100.0)); 
     }
}

void printOpenAccount()
{
    for(int i = 0 ; i < row ; i++){
         if(bankAccounts[i][0]==1)
         {
            printf("Balance : %0.2lf \nAccount number : %d \n\n" ,bankAccounts[i][1],i+901);
         }
    }
}


void closeAll()
{
     for(int i = 0 ; i < row ; i++){
         if(bankAccounts[i][0]==1)
         {
              bankAccounts[i][0] = 0;
              bankAccounts[i][1] = 0;
         }
    }

     for(int i = 0 ; i < row ; i++){
       for(int j = 0 ; j < cow ; j ++){
             printf("%.2lf ",bankAccounts[i][j]);
       }
       printf("\n");
    }
}





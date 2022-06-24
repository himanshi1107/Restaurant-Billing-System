#include<stdio.h>
#include<stdlib.h>

int loop=1, loop2=1, total=0;
int sQty=0, dQty=0, tQty=0, daQty=0;

void rupeeNotes(int amount)
{
    int tot;
    tot = amount / 2000;

    printf("There are: ");

    if (tot != 0)
    {
        printf("\n%d Note(s) of 2000\n", tot);
    }
    amount = amount - (tot * 2000);

    tot = amount / 500;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 500\n", tot);
    }
    amount = amount - (tot * 500);

    tot = amount / 100;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 100\n", tot);
    }
    amount = amount - (tot * 100);

    tot = amount / 50;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 50\n", tot);
    }
    amount = amount - (tot * 50);

    tot = amount / 20;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 20\n", tot);
    }
    amount = amount - (tot * 20);

    tot = amount / 10;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 10\n", tot);
    }
    amount = amount - (tot * 10);

    tot = amount / 5;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 5\n", tot);
    }
    amount = amount - (tot * 5);

    tot = amount / 2;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 2\n", tot);
    }
    amount = amount - (tot * 2);

    tot = amount / 1;

    if (tot != 0)
    {
        printf("\n%d Note(s) of 1\n", tot);
    }
   
}

void table()
{
    printf("\n***** Your Bill *****\n");
    printf("\n\nSr.\t|\t Item\t|\t Amount  \t|  Quantity\t|\t Total");
    printf("\n---------------------------------------------------------------------------------\n");
    if(sQty != 0)
        printf("1.\t|\t Samosa\t|\t Rs.20/-\t|\t %d\t|\t %d \n",sQty, sQty*20);
    if(dQty != 0)
        printf("2.\t|\t Dosa  \t|\t Rs.40/-\t|\t %d\t|\t %d \n",dQty, dQty*40);
    if(tQty != 0)
        printf("3.\t|\t Tea   \t|\t Rs.10/-\t|\t %d\t|\t %d \n",tQty, tQty*10);
    if(daQty != 0)
        printf("4.\t|\t Dabeli\t|\t Rs.25/-\t|\t %d\t|\t %d \n",daQty, daQty*25);
    printf("\n-------------------------------------------------------------------------------------\n");

}

void getMoney()
{
    int amt=0;

    printf("\nEnter your cash : ");
    scanf("%d",&amt);
    rupeeNotes(amt);
    
    if(amt<total){
        total = total - amt;
        printf("\nI need %d Rs more.\n",total);
        rupeeNotes(total);
    }
    else{
        amt = amt - total;
        if(amt>0){
            printf("\nReturn Rs.%d coin\n",amt);   
            rupeeNotes(amt);
        }
        loop2=0;
    }
    if(total==0){
        loop2=0;
    }
    
}
void billing(int price, int qty)
{
    total += price*qty;
}

int quantity(int index)
{
    int plates=0;
    switch(index)
    {
        case 1:
        case 2:
        case 4:
            printf("\nOKAY...How many Plates ?\n");
        break;
        case 3:
             printf("\nOKAY...How many Cups ?\n");
        break;
    }
    scanf("%d",&plates);
     printf("\nOkay...Anything Else ?\n");
    return plates; //return plates qty to getorder function which give item qty 
}

void getOrder()
{
    int cp=0;
    int choice=0;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Samosa\n");
            cp = quantity(1);
            sQty = sQty + cp;
            billing(20,cp);
        break;
        case 2:
            printf("Dosa\n");
            cp = quantity(2);
            dQty = dQty + cp;
            billing(40,cp);
        break;
        case 3:
            printf("Tea\n");
            cp = quantity(3);
            tQty = tQty + cp;
             billing(10,cp);
        break;
        case 4:
            printf("Dabeli\n");
            cp = quantity(4);
            daQty = daQty + cp;
            billing(25,cp);
        break;
        case 0:
            loop=0; // stop looping
            table();
            printf("\n\t\t Total Amount : Rs.%d\n",total);
            while(loop2){
                getMoney();
            }
            printf("\nT H A N K   Y O U !\n\n");
        break;
        default:
            printf("Sorry, You are not order\n");
    }
}

void menu()
{
    printf("\n :: MENU ::\n");
    printf("\n----------------------------------------\n");
    printf("1. | Samosa\t|\tRs.20/- \n");
    printf("2. | Dosa  \t|\tRs.40/- \n");
    printf("3. | Tea   \t|\tRs.10/- \n");
    printf("4. | Dabeli\t|\tRs.25/- \n");
    printf("0. | Exit\n");

    printf("\nEnter your choice : ");
    getOrder();
}


int main()
{
    printf("\n***** Welcome to Asterisc Hotel *****\n");

    while(loop){
        menu();
    }


    return 0;
}
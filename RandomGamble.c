//This program simulates gambling.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand (time(NULL));
    int m=1, sum=0, x=0;
    printf("Welcome to the Random Gambling bot!\n\n");

    //the user gets a random amount of starting cash in the interval [20; 40]
    printf(".beg\n");
    sum = (rand()%21)+20;
    printf("The user is out of money, so he gets %d coins.\n\n", sum);

    //the amount of gambling iterations
    for (int i=0; i<1000; ++i){
        //the program utilizes two gambling mechanics - "fliping" and "dicing"
        //".flip X" takes X and simulates a coin flip, returning either 0 or 2X.
        //".dice X" takes X and simulates a dice roll, returning either 0 or 6X.
        //there is a 50% chance for either a flip or a dice to happen
        //the amount of coins gambled is random.
        if(rand()%2 == 0){

        //if X amount of money gambled equals to how much money the user has in total,
        //"X" changes to "all"
            if((x = (rand()%sum)+1) == sum)
                printf(".flip all\n");
            else
                printf(".flip %d\n", x);
            if (rand()%2 == 0){
                printf("The user Lost %d coins, and now has %d coins.\n\n", x, sum-x);
                sum-=x;
                if(sum==0){
                    printf(".beg\n");
                    sum = (rand()%21)+20;
                    printf("The user is out of money, so he gets %d coins\n\n", sum);
                }
            }else{
                printf("The user won %d coins, and now has ", x);
                sum+=x;
                printf("%d coins.\n\n", sum);
            }
        }else{
            if((x = (rand()%sum)+1) == sum)
                printf(".dice all\n");
            else
                printf(".dice %d\n", x);
            if(rand()%5!=0){
                printf("The user Rolled a Dice and Lost %d coins, and now has %d coins.\n\n", x, sum-x);
                sum-=x;
                if(sum==0){
                    printf(".beg\n");
                    sum = (rand()%21)+20;
                    printf("The user is out of money, so he gets %d coins\n\n", sum);
                }
            }else{
                printf("The user Rolled a Dice and Won %d coins, and now has ", x*6);
                sum+=(x*5);
                printf("%d coins.\n\n", sum);
            }
        }
    }
    return 0;
}

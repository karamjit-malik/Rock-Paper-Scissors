#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rps(char player , char computer, int player_count, int computer_count, int count);
int main()
{
    int player_count , computer_count;
    player_count = 0;
    computer_count = 0;
    char player, computer;
    int number;
    srand(time(0));
    number = rand()%100 + 1;
    if (number<33)
    {
       computer = 'r';
    }
    else if (number>33 && number<66)
    {
        computer = 'p';
    }
    else
    {
        computer = 's';
    }
    printf("Enter 'r' for rock , 'p' for paper and 's' for scissors : ");
    scanf("%c", &player);
    int result = rps(player,computer,player_count,computer_count,3);
    if (player_count == 3)
    {
        printf("The game is won by the player\n");
    }
    else if (computer_count == 3)
    {
        printf("The game is won by the player\n");
    }
    return 0;
}

int rps(char player, char computer, int player_count, int computer_count, int count)
{ 
    if (count==0)
    {
       return 0;
    }
    // Cases for non equal responses  
    if (player == 'r' && computer == 'p')
    {
        computer_count += 1;
        printf("Computer wins as you chose %d and computer chosse %d\n", player , computer);
        return -1;
    }
   else if (player == 'p' && computer == 'r')
    {
        player_count += 1;
        printf("Player wins as you chose %d and computer chosse %d\n", player , computer);
        return 1;
    }
    if (player == 'r' && computer == 's')
    {
        player_count += 1;
        printf("Player wins as you chose %d and computer chosse %d\n", player , computer);
        return 1;
    }
    else if (player == 's' && computer == 'r')
    {
        computer_count += 1;
        printf("Computer wins as you chose %d and computer chosse %d\n", player , computer);
        return -1;
    }
    if (player == 's' && computer == 'p')
    {
        player_count += 1;
        printf("Player wins as you chose %d and computer chosse %d\n", player , computer);
        return 1;
    }
    else if (player == 'p' && computer == 's')
    {
        computer_count += 1;
        printf("Computer wins as you chose %d and computer chosse %d \n", player , computer);
        return -1;
    }

    // Cases for equal responses
    if(player == computer)
    {
        printf("Game is a draw\n");
        return 0;
    }
    rps(player, computer, player_count, computer_count, count-1);
}
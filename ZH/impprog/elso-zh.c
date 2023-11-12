//A kod nagyon ossze-vissza van. Bocsanat, de panikolok es fogalmam sincs semmirol.

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define ROW 10
#define COL 20
#define SNAKE_ROW 9
#define SNAKE_COL 2

//Main functions
void init_field(char arr[ROW][COL], int apples);
void init_snake(char arr[SNAKE_ROW][SNAKE_COL]);
void print_game(char field[ROW][COL], char snake[SNAKE_ROW][SNAKE_COL]);
void update_snake(char field[ROW][COL], char snake[SNAKE_ROW][SNAKE_COL], char input);

//Helper functions
int get_snake_headX(char arr[ROW][COL]);
int get_snake_headY(char arr[ROW][COL]);
void hand_to_work(char destination[ROW][COL], char from[ROW][COL]);
bool self_collision(char arr[ROW][COL]);
bool apple_eaten(char arr[ROW][COL]);

int main()
{
    struct Game{
        char field[ROW][COL];
        int appleNumber;
    }g;

    char snake[SNAKE_ROW][SNAKE_COL];
    char work[ROW][COL];

    init_field(g.field, 10);
    hand_to_work(work, g.field);
    print_game(work, snake);
    init_snake(snake);

    return 0;
}

//MAIN FUNCTIONS
void init_field(char arr[ROW][COL], int apples)
{
    srand(time(NULL));
    int x=0;

    for (int i = 0; i < ROW; i++)
    {
        
        for (int j = 0; j < COL; j++)
        {
            int random = rand()%15;
            if(random == 5 && x < apples){
                arr[i][j] = 'a';
                x++;
            }
            else 
                arr[i][j] = ' ';
        }
    }  
}

void init_snake(char arr[SNAKE_ROW][SNAKE_COL])
{
    arr[0][0] = '8';
    arr[0][1] = '8';
    for(int i = 1; i < SNAKE_ROW; i++)
    {
        for(int j = 0; j < SNAKE_COL; j++)
        {
            arr[i][j] = '0';
        }
    }
}

void print_game(char field[ROW][COL], char snake[SNAKE_ROW][SNAKE_COL])
{

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {   
            printf("%c", field[i][j]);

        }
        printf("\n");
    }

}

void update_snake(char field[ROW][COL], char snake[SNAKE_ROW][SNAKE_COL], char input)
{
    if(input == 'w')
    {
        snake[-1][0] = '8';
        snake[-1][1] = '8';
        for(int i = 0; i < SNAKE_ROW; i++)
        {
            for(int j = 0; j < SNAKE_COL; j++)
            {
                snake[i][j] = '0';
            }
        }
    }

    if(get_snake_headX(field) == -1 || get_snake_headY(field) == -1)
    {
        printf("-1");
        return 100;
    }
    if(self_collision(field))
    {
        printf("2");
        return 100;
    }


    if(get_snake_headX(field) > -1 && get_snake_headY(field) > -1 && !self_collision(field))
    {
        if(apple_eaten(field))
            printf("1");
        else
            printf("0");
    }

}

//HELPER FUCNTIONS
int get_snake_headX(char arr[ROW][COL])
{
    int posX=0;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {   
            if(arr[i][j] == '8')
            {
                posX = i;
            }
        }
    }
    return posX;
}

int get_snake_headY(char arr[ROW][COL])
{
    int posY=0;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {   
            if(arr[i][j] == '8')
            {
                posY = j;
            }
        }
    }
    return posY;
}

void hand_to_work(char destination[ROW][COL], char from[ROW][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            destination[i][j] = from[i][j];
        }
    }
}

bool self_collision(char arr[ROW][COL])
{
    bool hit = false;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {   
            if(arr[get_snake_headX(arr)][get_snake_headY(arr)] == '0')
            {
                hit = true;
            }
        }
    }
    return hit;
}

bool apple_eaten(char arr[ROW][COL])
{
    bool eaten = false;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {   
            if(arr[get_snake_headX(arr)][get_snake_headY(arr)] == 'a')
            {
                eaten = true;
            }
        }
    }
    return eaten;
}

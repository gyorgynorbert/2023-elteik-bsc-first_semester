#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10
#define SHIPTYPES 4

struct Play{
    char table[ROW][COL]; // play table
    int numberOfShips[SHIPTYPES];
}game;

void init();
void print_table();
void submit(char rowPos, int colPos, int shipSize, char direction);

int convert_rowPos(char rowPos);
bool checkCorner(char rowPos, int colPos, int shipSize, char direction);

int main(){

    init();
    submit('A', 1, 3, '|'); submit('I', 3, 2, '_'); submit('I', 3, 3, '_'); submit('F', 6, 5, '|'); submit('F', 7, 5, '|');
    submit('A', 1, 2, '_'); submit('I', 4, 4, '|'); submit('C', 3, 4, '_'); submit('G', 9, 3, '_'); submit('B', 5, 3, '_');
    submit('I', 7, 3, '|'); submit('J', 7, 2, '|'); submit('J', 7, 1, '|');
    print_table();


    return 0;
}

void init(){
    // Emptying the game table
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            game.table[i][j] = 'x';

    //Emptying the numberOfShips
    for (int i = 0; i < SHIPTYPES; i++)
        game.numberOfShips[i] = 0;
}

void print_table(){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%c", game.table[i][j]);
        }
    printf("\n");
    }    
}

void submit(char rowPos, int colPos, int shipSize, char direction){
    if (convert_rowPos(rowPos) > 10 || colPos > 10 || shipSize > 6 || !(direction == '_' || direction == '|')){
        printf("Incorrect parameters!\n");
        return;
    }

    if (!checkCorner(rowPos, colPos, shipSize, direction)){
        printf("The ship exceeds limits!\n");
        return;
    }

    int actualRow = convert_rowPos(rowPos); int actualCol = colPos - 1;
    printf("%d, %d, %d \n", actualRow, actualCol, shipSize);

    if (direction == '|'){
        
        for (int i = actualRow; i <= shipSize; i++){
            game.table[i][actualCol] = '1';
        }
    }

    if (direction == '_'){
        printf("XYZ\n");
        for (int i = actualCol; i <= shipSize; i++)
            game.table[actualRow][i] = 'O';
    
    }

    
}


int convert_rowPos(char rowPos){
    switch (rowPos)
    {
        case 'A': return 0;
            break;
        case 'B': return 1;
            break;
        case 'C': return 2;
            break;
        case 'D': return 3;
            break;
        case 'E': return 4;
            break;
        case 'F': return 5;
            break;
        case 'G': return 6;
            break;
        case 'H': return 7;
            break;
        case 'I': return 8;
            break;
        case 'J': return 9;
            break;
        default: return -1;
            break;
    }
    return -1;
}

bool checkCorner(char rowPos, int colPos, int shipSize, char direction){
    int actualPos = convert_rowPos(rowPos);
    switch (shipSize)
    {
    case 2:
        if ((colPos < 9 && direction == '_') || (actualPos < 9 && direction == '|'))
            return true;
        break;
    case 3:
        if ((colPos < 8 && direction == '_') || (actualPos < 8 && direction == '|'))
            return true;
        break;
    case 4: 
        if ((colPos < 7 && direction == '_') || (actualPos < 7 && direction == '|'))
            return true;
        break;
    case 5: 
        if ((colPos < 6 && direction == '_') || (actualPos < 6 && direction == '|'))
            return true;
        break;
    default: return false;
        break;
    }
    return false;
    //ki kell cserelni: kezdo pozi index + meret nagyobb-e, mint tomb max index
}

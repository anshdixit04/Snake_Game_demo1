/* Assignment four
 ///////////////////
 * studen email- adixit7466@conestogac.on.ca
 * student id: 8847466
 * Author: Ansh dixit & Abdul khan
 * Date: october 6,2022
 * course: EECE-71020 
 * professor: Mr. Waleed Qadir Khan
 */


//"preprocessor directives" 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

// predefined dimensions of the play area. this is where our snake will move and eat its food.
#define board_size_x 30
#define board_size_y 30

//pre defined global variables
// these variables are defined in order to post food on both x&y, gameover and score.
int gameOver = 0, x, y, foodX, foodY, score;
int i,j,k;
int s;
int totalTail;
//length for the snake
int headX[100], headY[100];

// this functions will call out the food in the playarea.
void Setup(){
    srand(time(NULL));
    x = board_size_x/2;
    y = board_size_y/2;
    score = 0;

    Start:
    foodX = 1 + rand() % board_size_y;
    foodY = 1+ rand() % board_size_x;

    if(foodX <= 0||foodY <= 0||foodX == x||foodY == y||foodX>board_size_x||foodY>board_size_y){
        return ;
    }
}
/* this function will call out the playground area and the snake body. basically it is used 
to make a sketch of playground and the characters which are used for making a snake body.
*/
 
void Draw(){
	//screen will clear everytime the program runs.
    system("cls");
	
	// for loop is used in order to make the edges of the playground. 
    for(i = 0; i<board_size_x;i++){
        for( j = 0; j<board_size_y; j++){
            if(i == 0||j == 0||i == board_size_y-1|| j == board_size_x-1){
              printf("%c",35);
	
            }
            // this conditional statement is used to make the head of snake.
            else if(i == x&&j == y){
                printf("O");
            } 
            // this statement makes the food for the snake inside the playarea.
			else if(foodX == i && foodY == j){
                printf("$");
            } 
			else{
				/* this statement is used for making the tail of the snake everytime 
				when food is eaten 
				*/
                int print = 0;
                for( k = 0; k <totalTail; k++){
                    if(headX[k] == i&& headY[k] == j){
                        printf("*");
                        print = 1;
                    }
                }
                if(print == 0){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    // score will be updated when the snake grows after eating food.
    printf("Score: %d", score);

}
// this function will implement the directions for the snake.
void Input(){

    if(kbhit()){
        switch(getch()){
        case 'w':
            s= 1;
            break;
        case 's':
            s = 2;
            break;
        case 'a':
            s = 3;
            break;
        case 'd':
            s = 4;
            break;
    }
    }
}

/* this function calls out the logic behind the movement of snake and the productiom 
of food inside the playground area */
void Logic(){
    int prevX = headX[0];
    int prevY = headY[0];
    int prev2X, prev2Y;
    headX[0] = x;
    headY[0] = y;
    for ( i = 1; i < totalTail; i++)
    {
        prev2X = headX[i];
        prev2Y = headY[i];
        headX[i] = prevX;
        headY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(s){
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
        default:
            break;
    }
    if(s == 1||s==2){Sleep(25);}

    for(i = 0; i <totalTail; i++){
        if(headX[i] == x && headY[i] == y){
            gameOver = 1;
        }
	}

    if(x > board_size_y-1||y>board_size_x-1||x<0||y<0){
        gameOver = 1;
    }

    if(x == foodX && y == foodY){
        score += 1;
        totalTail++;
        start2:
        foodX = rand() % 29;
        foodY = rand() % 29;

        if(foodX <= 0||foodY <= 0||foodX == x||foodY == y||foodX>board_size_x||foodY>board_size_y){
            return ;
        }
    }
}

// this is the main function.
// here the program will be executed by calling out the functions in the main function.
int main()
{
    Setup();

    while(gameOver != 1){
        Draw();
        Logic();
        Input();
        Sleep(10);
    }
    return 0;
}

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ball { 
    float y; 
    float speed;
    float gravity;
    int is_moving;
} Ball; 

void update_ball(Ball* newball);
void print(int a, int b, float y);

int main(int argc, char const *argv[])
{
    Ball* newball = (Ball*)malloc(sizeof(Ball));

    if(!newball) return 1;

    newball->is_moving = 1;
    newball->speed = 0;
    newball->gravity = 9.8;
    newball->y = 5.0;

    printf("\n\n");

    while (newball->is_moving) {
        system("cls");
        update_ball(newball);
        print(16,48, newball->y);
        Sleep(10);
    }

    free(newball);
    return 0;
}

void update_ball(Ball* newball) {
    newball->speed = newball->speed - newball->gravity * 0.02;
    newball->y = newball->y + newball->speed * 0.02;

    if (newball->y <= 0) { 
        newball->y = 0; 
        newball->speed = newball->speed * -0.5;

        if(newball->speed > -0.1 && newball->speed < 0.10) {
            newball->speed = 0;
            newball->is_moving = 0;
        }
    }

    printf("Y: %.2f  Speed: %.2f\n", newball->y, newball->speed);
}

void print(int a, int b, float y) {
    int half = ceil(b / 2);
    
    for(int i = a; i >= 0; i--) {
        for(int j = b; j >= 0; j--) {

            if (j == half && i == ceil(y) + 1) { 
                printf("@");

                continue;
            }

            if(i == 0 || j == 0 || i == a || j == b) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        
        printf("\n");
   }
}
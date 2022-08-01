#include "stdio.h"
#define MAX_PLATE 10
#define MAX_COLUMN 3

//globe var
int n;
char src, tmp, dst, gamesrc, gamedst;
int Z[MAX_COLUMN][MAX_PLATE];
int top[MAX_COLUMN] = { -1,-1,-1 };

//Function Declaration
void GetImport();
void Zprint();
int GameImport();
void GameHanoi();
int Zmove();
void ClearArr(char *arr, int length);

int main()
{
    int i;

    GetImport();//input parameter

    switch (src) {//fill array
        case'A':
            for (i = 0; i < n; i++)
                Z[0][i] = n - i;
            top[0] = n - 1;
            break;
        case'B':
            for (i = 0; i < n; i++)
                Z[1][i] = n - i;
            top[1] = n - 1;
            break;
        case'C':
            for (i = 0; i < n; i++)
                Z[2][i] = n - i;
            top[2] = n - 1;
            break;
    }
    Zprint();
    GameHanoi();
}

void GetImport()
{
    char keys[128];
    while (1) {
        printf("Please enter the number of floors of Hanoi (1-10)\n");
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "1") == 0) {
            n = 1;
        }
        else if (strcmp(keys, "2") == 0) {
            n = 2;
        }
        else if (strcmp(keys, "3") == 0) {
            n = 3;
        }
        else if (strcmp(keys, "4") == 0) {
            n = 4;
        }
        else if (strcmp(keys, "5") == 0) {
            n = 5;
        }
        else if (strcmp(keys, "6") == 0) {
            n = 6;
        }
        else if (strcmp(keys, "7") == 0) {
            n = 7;
        }
        else if (strcmp(keys, "8") == 0) {
            n = 8;
        }
        else if (strcmp(keys, "9") == 0) {
            n = 9;
        }
        else if (strcmp(keys, "10") == 0) {
            n = 10;
        }
        else {
            n = 0;
            printf("Invalid Input, Please enter again\n");
        }
        if (n >= 1 && n <= 10)
            break;
    }
    while (1) {
        printf("Please enter the source column (A-C)\n");
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "a") == 0) {
            src = 'A';
        }
        else if (strcmp(keys, "A") == 0) {
            src = 'A';
        }
        else if (strcmp(keys, "b") == 0) {
            src = 'B';
        }
        else if (strcmp(keys, "B") == 0) {
            src = 'B';
        }
        else if (strcmp(keys, "c") == 0) {
            src = 'C';
        }
        else if (strcmp(keys, "C") == 0) {
            src = 'C';
        }
        else {
            src = '0';
            printf("Invalid Input, Please enter again\n");
        }
        if (src == 'A' || src == 'B' || src == 'C')
            break;
    }
    while (1) {
        printf("Please enter the target column (A-C)\n");
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "a") == 0) {
            dst = 'A';
        }
        else if (strcmp(keys, "A") == 0) {
            dst = 'A';
        }
        else if (strcmp(keys, "b") == 0) {
            dst = 'B';
        }
        else if (strcmp(keys, "B") == 0) {
            dst = 'B';
        }
        else if (strcmp(keys, "c") == 0) {
            dst = 'C';
        }
        else if (strcmp(keys, "C") == 0) {
            dst = 'C';
        }
        else {
            dst = '0';
            printf("Invalid Input, Please enter again\n");
            continue;
        }
        if (dst == 'A' || dst == 'B' || dst == 'C')
            if (src == dst)
                printf("Source column must be different form target column\n");
            else
                break;
    }
    if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
        tmp = 'C';
    else if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
        tmp = 'B';
    else
        tmp = 'A';
}

void Zprint()
{
    int i;
    printf("A:");
    for (i = 0; i < 10; i++)
        if (i <= top[0])
            printf("  %2d", Z[0][i]);
        else
            printf("   ");
    printf("\n");
    printf("B:");
    for (i = 0; i < 10; i++)
        if (i <= top[1])
            printf("  %2d", Z[1][i]);
        else
            printf("   ");
    printf("\n");
    printf("C:");
    for (i = 0; i < 10; i++)
        if (i <= top[2])
            printf("  %2d", Z[2][i]);
        else
            printf("    ");
    printf("\n");
}

int GameImport()
{
    int numsrc, numdst;
    char s[2];
    char keys[128];
    while (1) {
        printf("please enter move column(example:AC=the disk at top of A move to C, Q=exit):\n");
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "AB") == 0) {
            s[0] = 'A';
            s[1] = 'B';
        }
        else if (strcmp(keys, "AC") == 0) {
            s[0] = 'A';
            s[1] = 'C';
        }
        else if (strcmp(keys, "BC") == 0) {
            s[0] = 'B';
            s[1] = 'C';
        }
        else if (strcmp(keys, "BA") == 0) {
            s[0] = 'B';
            s[1] = 'A';
        }
        else if (strcmp(keys, "CA") == 0) {
            s[0] = 'C';
            s[1] = 'A';
        }
        else if (strcmp(keys, "CB") == 0) {
            s[0] = 'C';
            s[1] = 'B';
        }
        else if (strcmp(keys, "Q") == 0) {
            s[0] = 'Q';
            s[1] = '\0';
        }
        else {
            s[0] = '\0';
            s[1] = '\0';
            printf("Invalid Input, Please enter again\n");
            continue;
        }
        if (s[0] == 'Q' && s[1] == '\0')
            return 0;//exit
        //deal with input error
        numsrc = (int)(s[0] - 'A');
        numdst = (int)(s[1] - 'A');
        if (top[numsrc] == -1)
            printf("Source column is empty! Please enter again\n");
        else if (top[numdst] != -1 && (Z[numsrc][top[numsrc]] > Z[numdst][top[numdst]]))
            printf("Biger disk can not cover smaller disk! Please enter again\n");
        else {
            //correct input
            gamesrc = s[0];
            gamedst = s[1];
            return 1;//game continue
        }
    }
}

int Zmove()
{
    int temp = 0;
    switch (gamesrc) {
        case'A':
            temp = Z[0][top[0]];
            top[0]--;
            break;
        case'B':
            temp = Z[1][top[1]];
            top[1]--;
            break;
        case'C':
            temp = Z[2][top[2]];
            top[2]--;
            break;
    }
    switch (gamedst) {
        case'A':
            top[0]++;
            Z[0][top[0]] = temp;
            break;
        case'B':
            top[1]++;
            Z[1][top[1]] = temp;
            break;
        case'C':
            top[2]++;
            Z[2][top[2]] = temp;
            break;

    }
    return temp;
}

void GameHanoi()
{
    int step = 1;
    int Loop = 1;
    while (Loop) {
        if (!GameImport()) {
            printf("game exit\n");
            break;
        }
        printf(("Step %4d (%2d)#: %c-->%c\n"), step++, Z[(int)(gamesrc - 'A')][top[(int)(gamesrc - 'A')]], gamesrc, gamedst);
        Zmove();
        Zprint();
        //game win
        if (top[(int)(dst - 'A')] == n - 1) {
            printf("You win!\n");
            break;
        }
    }
}

void ClearArr(char *arr, int length)
{
    int i;
    for (i = 0; i < length; i++)
        arr[i] = 0;
}




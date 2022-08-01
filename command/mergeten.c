#include "stdio.h"

//game data
#define MAX_ROW 8
#define MIN_ROW 5
#define MAX_COL 10
#define MIN_COL 5
#define MAX_TARGET 20
#define MIN_TARGET 5

//globe var
//-------------game board----------------
int row=5;		//game row
int col=5;		//game col
int target=5;		//game target
int Barray[MAX_ROW][MAX_COL];	//board array
int Mark[MAX_ROW][MAX_COL];		//mark array
int MaxValue=0;
int score=0;
int inputx, inputy;
//----------------Stack------------------
int list[MAX_ROW * MAX_COL][2]; //Stack array
int index = -1;  //Stack ptr
int Spx=0, Spy=0;  //Stack Pop

//function defination
//----------------Stack------------------
int IsEmpty();
void Push(const int x, const int y);
void Pop();
void StackClear();
//-------------game board----------------
void GetInput();
void CreateBoard();
int non_re_Find(const int x, const int y);
int GameOver();
void ClearMark();
void PrintBoard();
void PrintMark();
void GetInput_Find();
char GetInput_Merge(int x, int y);
int Merge(const int x, const int y);
void DropDown();
void Fill();
int IsWin();
//-----------other function--------------
void ClearArr(char* arr, int length);
unsigned int _seed2 = 0xDEADBEEF; //set rand seed

void srand(unsigned int seed) {
    _seed2 = seed;
}

int rand() {
    unsigned int next = _seed2;
    unsigned int result;

    next *= 1103515245;
    next += 12345;
    result = (unsigned int)(next / 65536) % 2048;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int)(next / 65536) % 1024;

    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int)(next / 65536) % 1024;

    _seed2 = next;

    return result;
}

int main()
{
    int x, y;
    int loop = 1;
    char choice;
    int tscore;
    GetInput();
    CreateBoard();
    printf("\n");

    while (loop) {
        ClearMark();
        printf("current array:\n");
        PrintBoard();
        printf("\n");
        GetInput_Find();
        x = inputx;
        y = inputy;
        if (non_re_Find(x, y)) {
            printf("\n");
            printf("Mark Array:\n");
            PrintMark();
            printf("\n");
            PrintBoard();
            printf("\n");

            choice = GetInput_Merge(x, y);
            printf("\n");
            switch (choice) {
                case'Y':
                    printf("merged array:\n");
                    tscore = Merge(x, y);
                    PrintBoard();
                    printf("\n");
                    printf("You get %d points! Total score:%d ,Target:%d\n", tscore, score, target);
                    DropDown();
                    Fill();
                    printf("filled array:\n");
                    PrintBoard();
                    printf("\n");
                    if (IsWin()) {
                        printf("You Win! But you still can pursuit higer score!\n");
                    }
                    printf("\n\n");
                    break;
                case'N':
                    printf("\n");
                    break;
                case'Q':
                    loop = 0;
                    break;
                default:
                    break;
            }
        }
        else
            printf("There are no same value around there,Please input again!\n");
        if (GameOver()) {
            printf("No value can be merged,Game over!\n");
            loop = 0;
        }
    }

    return 0;
}

int IsEmpty()
{
    if (index == -1)
        return 1;
    else
        return 0;
}

void Push(const int x, const int y)
{
    index++;
    list[index][0] = x;
    list[index][1] = y;
}

void Pop()
{
    Spx = list[index][0];
    Spy = list[index][1];
    index--;
}

void StackClear()
{
    index = -1;
}

void GetInput()
{
    char keys[128];
    while (1) {
        printf("Please enter game row(5-8):\n");;
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "5") == 0) {
            row = 5;
        }
        else if (strcmp(keys, "6") == 0) {
            row = 6;
        }
        else if (strcmp(keys, "7") == 0) {
            row = 7;
        }
        else if (strcmp(keys, "8") == 0) {
            row = 8;
        }
        else {
            row = 0;
            printf("Invalid Input, Please enter again\n");
        }
        if (row >= MIN_ROW && row <= MAX_ROW)
            break;
    }
    while (1) {
        printf("Please enter game col(5-10):\n");
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "5") == 0) {
            col = 5;
        }
        else if (strcmp(keys, "6") == 0) {
            col = 6;
        }
        else if (strcmp(keys, "7") == 0) {
            col = 7;
        }
        else if (strcmp(keys, "8") == 0) {
            col = 8;
        }
        else if (strcmp(keys, "9") == 0) {
            col = 9;
        }
        else if (strcmp(keys, "10") == 0) {
            col = 10;
        }
        else {
            col = 0;
            printf("Invalid Input, Please enter again\n");
        }
        if (col >= MIN_COL && col <= MAX_COL)
            break;
    }
    while (1) {
        printf("Please enter game target(5-20):\n");
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "5") == 0) {
            target = 5;
        }
        else if (strcmp(keys, "6") == 0) {
            target = 6;
        }
        else if (strcmp(keys, "7") == 0) {
            target = 7;
        }
        else if (strcmp(keys, "8") == 0) {
            target = 8;
        }
        else if (strcmp(keys, "9") == 0) {
            target = 9;
        }
        else if (strcmp(keys, "10") == 0) {
            target = 10;
        }
        else if (strcmp(keys, "11") == 0) {
            target = 11;
        }
        else if (strcmp(keys, "12") == 0) {
            target = 12;
        }
        else if (strcmp(keys, "13") == 0) {
            target = 13;
        }
        else if (strcmp(keys, "14") == 0) {
            target = 14;
        }
        else if (strcmp(keys, "15") == 0) {
            target = 15;
        }
        else if (strcmp(keys, "16") == 0) {
            target = 16;
        }
        else if (strcmp(keys, "17") == 0) {
            target = 17;
        }
        else if (strcmp(keys, "18") == 0) {
            target = 18;
        }
        else if (strcmp(keys, "19") == 0) {
            target = 19;
        }
        else if (strcmp(keys, "20") == 0) {
            target = 20;
        }
        else {
            target = 0;
            printf("Invalid Input, Please enter again\n");
        }
        if (target >= MIN_TARGET && target <= MAX_TARGET) {
            break;
        }
    }
}

void CreateBoard()
{
    int i, j;
    while (1) {
        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++) {
                Barray[i][j] = rand() % 3 + 1;
                Mark[i][j] = 0;
                if (MaxValue < Barray[i][j])
                    MaxValue = Barray[i][j];
            }
        if (!GameOver()) {
            return;
        }
    }
}

int non_re_Find(const int x, const int y)
{
    int tx, ty, temp;
    int num = 0;
    StackClear();
    Mark[x][y] = 1;
    Push(x, y);
    while (!IsEmpty()) {
        Pop();
        tx = Spx;
        ty = Spy;
        temp = Barray[tx][ty];
        if (tx + 1 < row && temp == Barray[tx + 1][ty] && !Mark[tx + 1][ty]) {
            num++;
            Push(tx + 1, ty);
            Mark[tx + 1][ty] = 1;
        }
        if (tx - 1 >= 0 && temp == Barray[tx - 1][ty] && !Mark[tx - 1][ty]) {
            num++;
            Push(tx - 1, ty);
            Mark[tx - 1][ty] = 1;
        }
        if (ty + 1 < col && temp == Barray[tx][ty + 1] && !Mark[tx][ty + 1]) {
            num++;
            Push(tx, ty + 1);
            Mark[tx][ty + 1] = 1;
        }
        if (ty - 1 >= 0 && temp == Barray[tx][ty - 1] && !Mark[tx][ty - 1]) {
            num++;
            Push(tx, ty - 1);
            Mark[tx][ty - 1] = 1;
        }
    }

    if (!num) {
        Mark[x][y] = 0;
        return 0;
    }
    else
        return num + 1;
}

int GameOver()
{
    int i, j;
    int temp;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++) {
            temp = Barray[i][j];
            if ((i + 1 < row && temp == Barray[i + 1][j])
                || (i - 1 >= 0 && temp == Barray[i - 1][j])
                || (j + 1 < col && temp == Barray[i][j + 1])
                || (j - 1 > 0 && temp == Barray[i][j - 1])) {
                return 0;
            }
        }
    return 1;
}

void ClearMark()
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            Mark[i][j] = 0;
}

void PrintMark()
{
    int i, j;
    printf("  | ");
    for (j = 0; j < col; j++) {
        printf("%2d ", j);
    }
    printf("\n--+-");
    for (j = 0; j < col; j++) {
        printf("---");
    }
    printf("\n");
    for (i = 0; i < row; i++) {
        printf("%c | ", (char)('A' + i));
        for (j = 0; j < col; j++) {
            if (Mark[i][j])
                printf(" * ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}

void PrintBoard()
{
    int i, j;
    printf("  | ");
    for (j = 0; j < col; j++) {
        printf("%2d ",j);
    }
    printf("\n--+-");
    for (j = 0; j < col; j++) {
        printf("---");
    }
    printf("\n");
    for (i = 0; i < row; i++) {
        printf("%c | ", (char)('A' + i));
        for (j = 0; j < col; j++) {
            if (Barray[i][j] < 10)
                printf(" ");
            printf("%d ", Barray[i][j]);
        }
        printf("\n");
    }
}

char GetInput_Merge(int x, int y)
{
    char keys[128];
    char c;
    printf("Please confirm whether to merge them to %c %d (Y/N/Q)", (char)('A' + x), y);

    while (1) {
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (strcmp(keys, "Y") == 0) {
            c = 'Y';
        }
        else if (strcmp(keys, "N") == 0) {
            c = 'N';
        }
        else if (strcmp(keys, "Q") == 0) {
            c = 'Q';
        }
        else {
            printf("Invalid Input, Please enter again\n");
        }
        if (c == 'Y' || c == 'N' || c == 'Q') {
            break;
        }
    }
    return c;
}

void GetInput_Find()
{
    char s[3];
    char keys[128];
    printf("Please enter the matrix coordinates in the form of letters+numbers [example: c2]\n ");

    while (1) {
        ClearArr(keys, 128);
        int r = read(0, keys, 128);
        if (keys[0] >= 'a' && keys[0] <= 'z')
            keys[0] = keys[0] - 'a' + 'A';
        if (keys[0] >= 'A' && keys[0] < 'A' + row && keys[1] >= '0' && keys[1] < '0' + col) {
            inputx = (int)(keys[0] - 'A');
            inputy = (int)(keys[1] - '0');
            break;
        }
        else {
            printf("Invalid Input, Please enter again\n");
        }
    }
}

int Merge(const int x, const int y)
{
    int value = Barray[x][y];
    int num = 1;
    int i, j;
    Barray[x][y]++;
    if (Barray[x][y] > MaxValue)//修改最大值
        MaxValue = Barray[x][y];

    Mark[x][y] = 0;//根节点标记清空
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (Mark[i][j] && (i != x || j != y)) {
                //若已经标记且不是根节点,清零
                Barray[i][j] = 0;
                num++;
            }
    score += (num * value * 3);
    //返回本次所得分数
    return num * value * 3;
}

void DropDown()
{
    int i, j;
    int k;
    for (i = row - 2; i >= 0; i--)//从倒数第二行往上搜索
        for (j = 0; j < col; j++) {
            if (Barray[i][j] != 0 && Barray[i + 1][j] == 0) {
                //若当前节点不为0且下方为0，则找到最底层后下落
                for (k = i + 1; k < row && Barray[k][j] == 0; k++)
                    ;
                Barray[k - 1][j] = Barray[i][j];
                Barray[i][j] = 0;
                Mark[k - 1][j] = 0;
                Mark[i][j] = 1;
            }
        }
}

void Fill()
{
    int i, j;
    int temp;
    //分情况填充
    if (MaxValue >= 2 && MaxValue <= 3) {
        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++)
                if (Barray[i][j] == 0)
                    Barray[i][j] = rand() % 3 + 1;
    }
    else if (MaxValue == 4) {
        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++)
                if (Barray[i][j] == 0) {
                    temp = rand() % 10;
                    if (temp < 9)
                        Barray[i][j] = rand() % 3 + 1;
                    else
                        Barray[i][j] = 4;
                }
    }
    else if (MaxValue == 5) {
        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++)
                if (Barray[i][j] == 0) {
                    temp = rand() % 100;
                    if (temp < 75)
                        Barray[i][j] = rand() % 3 + 1;
                    else if (temp >= 75 && temp < 90)
                        Barray[i][j] = 4;
                    else
                        Barray[i][j] = 5;
                }
    }
    else if (MaxValue == 6) {
        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++)
                if (Barray[i][j] == 0) {
                    temp = rand() % 100;
                    if (temp < 80)
                        Barray[i][j] = rand() % 4 + 1;
                    else if (temp >= 80 && temp < 95)
                        Barray[i][j] = 5;
                    else
                        Barray[i][j] = 6;
                }
    }
    else {
        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++)
                if (Barray[i][j] == 0) {
                    temp = rand() % 100;
                    if (temp < 80)
                        Barray[i][j] = rand() % (MaxValue - 3) + 1;
                    else if (temp >= 80 && temp < 90)
                        Barray[i][j] = MaxValue - 2;
                    else if (temp >= 90 && temp < 95)
                        Barray[i][j] = MaxValue - 1;
                    else
                        Barray[i][j] = MaxValue;
                }
    }
}

int IsWin()
{
    if (MaxValue >= target)
        return 1;
    else
        return 0;
}

void ClearArr(char* arr, int length)
{
    int i;
    for (i = 0; i < length; i++)
        arr[i] = 0;
}



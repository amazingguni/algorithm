#include <iostream>
#include <string.h>

#define SWITCH_SIZE 10
#define MAX_SWITCH_CLOCK_SIZE 5
#define CLOCK_SIZE 16
#define NOT_USED -1
#define MAX 10000

using namespace std;

int switchClock[SWITCH_SIZE][MAX_SWITCH_CLOCK_SIZE] = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}};
int switchClockCnt[SWITCH_SIZE] = {3, 4, 4, 5, 5, 4, 3, 5, 5, 5};
int testcase = 0;

int initialClock[CLOCK_SIZE];
int changedClock[CLOCK_SIZE];

void printClock(int* arr);
int isMatched();

int run(){
    int currentAnswer = MAX;
    int num;
    for(int i = 0; i< CLOCK_SIZE; i++){
        cin >> num;
        initialClock[i] = (num / 3) % 4;
    }
    int switchCnt;
    int currentSwitchCnt;
    
    for (unsigned long status = 0; status < 1ul << 20; status++ ){
        memset(changedClock, 0, sizeof(int) * CLOCK_SIZE);
        switchCnt = 0;
        unsigned long current = status;
        for(int i = 0; i < SWITCH_SIZE; i++){
            if (current == 0) break;
            currentSwitchCnt = current % 4;
            for (int j = 0; j < switchClockCnt[i]; j++) {
                changedClock[switchClock[i][j]] += currentSwitchCnt;
            }
            switchCnt += currentSwitchCnt;
            current /= 4;
        }
        if(isMatched()  && switchCnt < currentAnswer){
            currentAnswer = switchCnt;
        }
    }    
    if(currentAnswer == MAX)
        return -1;
    return currentAnswer;
}

int isMatched(){
    for(int i = 0; i < CLOCK_SIZE ; i++){
        if((initialClock[i] + changedClock[i])%4 != 0){
            return 0;
        }
    }
    return 1;
}
void printClock(int* arr){
    for(int i=0; i< CLOCK_SIZE; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cin >> testcase;
    for (int tc = 0; tc < testcase; tc++)
    {
        cout << run() << endl;
    }

    return 0;
}
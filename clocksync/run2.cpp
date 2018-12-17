#include <iostream>
#include <string.h>

#define SWITCH_SIZE 10
#define MAX_SWITCH_CLOCK_SIZE 5
#define CLOCK_SIZE 16
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

int clocks[CLOCK_SIZE];

bool areAligned(){
    for(int i = 0 ; i< CLOCK_SIZE; i++){
        if (clocks[i] % 12) return false;
    }
    return true;
}
int min(int a, int b){
    return a < b ? a : b;
}

void push(int swtch){
    for(int i = 0 ; i < switchClockCnt[swtch]; i++){
        clocks[switchClock[swtch][i]] += 3;
        clocks[switchClock[swtch][i]] %= 12;
    }
}
int solve(int currentSwitch){
    if (currentSwitch == SWITCH_SIZE) 
        return areAligned() ? 0: MAX;

    int ret = MAX;
    for(int cnt = 0; cnt < 4; cnt++){
        ret = min(ret, cnt + solve(currentSwitch + 1));
        push (currentSwitch);
    }
    return ret;
}

int main()
{
    cin >> testcase;
    for (int tc = 0; tc < testcase; tc++)
    {
        for(int i = 0 ; i < CLOCK_SIZE; i++){
            cin >> clocks[i];
        }
        int result = solve(0);
        result = result != MAX? result: -1;
        
        cout << result << endl;
    }

    return 0;
}
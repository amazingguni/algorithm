#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int testcase = 0;
int num_student = 0;
int num_pair = 0;

int pairs[50][2];
int status[11];

int isFull(){
    for (int i = 0 ; i < num_student; i++){
        if (!status[i]) return 0;
    }
    return 1;
}

void print(){
    for (int i = 0 ; i < num_student; i++){
        cout << status[i] << " ";
    }
    cout<<endl;
}

int run(int pair_inx, int count){
    if(isFull()) return 1;
    // print();
    int result = 0;
    for(int i = pair_inx; i < num_pair; i++){
        if(status[pairs[i][0]] == 1 | status[pairs[i][1]] == 1  )
            continue;
        status[pairs[i][0]] = 1;
        status[pairs[i][1]] = 1;  
        // cout<<"selected : " << i << endl;
        result += run(i + 1, count+1);
        status[pairs[i][0]] = 0;
        status[pairs[i][1]] = 0;  
    }
    return result;
}

int main(){
    cin >> testcase;
    for (int tc = 0; tc < testcase; tc++){

        memset(status, 0, sizeof(int) * 11);
        cin >> num_student >> num_pair;
        for(int i = 0 ; i < num_pair; i++ ){
            cin >>pairs[i][0] >> pairs[i][1];
        }
        cout<<run(0, 0)<<endl;
    }
    
    return 0;
}
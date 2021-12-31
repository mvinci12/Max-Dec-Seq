#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

void MaxDecSeq(int* nums, int len){

    int lds[len];
    int maxnum;
    for (int i = 0; i < len; i++){      //fills lds with 1s
        lds[i] = 1;
    }

    for (int i = 1; i < len; i++){
        for (int j = 0; j < i; j++){
            if (nums[i] < nums[j]){         //with each corresponding index from lds to nums, it adds 1 for each time an element has a greater element before it
                lds[i] += 1;
            }
        }
    }

    maxnum = *max_element(lds,lds+len);         //takes the max element from lds -> the number with the most bigger numbers before it
    int index;
    for (int i = 0; i < len; i++){              //gets the index of the max value in lds
        if (lds[i] == maxnum){
            index = i;
            break;
        }
    }

    vector<int>sequence;        //answer
    int x = 1;  //check for repeats in lds
    int y = nums[index]; //check for repeats in num
    sequence.push_back(nums[index]);        //going from right to left
    for (int i = index-1; i > 0; --i){
        if ( lds[i] >= lds[i-1] && lds[i] != x && y != nums[i] && sequence[sequence.size()-1] < nums[i] ){    //decreasing lds values get added and checks for repeats
            x = lds[i];
            y = nums[i];
            sequence.push_back(nums[i]);
        }
    }
    if (lds[0] > sequence[sequence.size()-1]){
        sequence.push_back(nums[0]);    //checking for first element because for loop doesnt reach
    }

    for (int i = sequence.size()-1; i >= 0; --i){       //prints sequence
        cout << sequence[i] << " ";
    }
    cout << endl;

    
}
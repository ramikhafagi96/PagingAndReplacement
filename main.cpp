//
// Created by rami96 on 4/5/19.
//
#include <iostream>
#include "./ReplacementPolicies/FIFO_Int.h"
#include "./ReplacementPolicies/LRU_Int.h"
#include "./ReplacementPolicies/CLOCK_Int.h"
int main(void)
{
    vector<int> pages;
    int capacity = 0,page,size=0;
    scanf("%d",&capacity);
    string replacementPolicy;
    cin >> replacementPolicy;
    while(page != -1){
        scanf("%d",&page);
        if(page == -1) break;
        size++;
        pages.push_back(page);
    }
    pages.resize(size);
    if(replacementPolicy.compare("FIFO") == 0)
        FIFO_ReplacementPolicy(pages,capacity);

    else if(replacementPolicy.compare("LRU") == 0){
        LRU_ReplacementPolicy(pages,capacity);
    }

    else if(replacementPolicy.compare("CLOCK") == 0){
        CLOCK_ReplacementPolicy(pages,capacity);
    }
}

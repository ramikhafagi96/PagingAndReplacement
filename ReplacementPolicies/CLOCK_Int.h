//
// Created by rami96 on 4/5/19.
//

#ifndef PAGEREPLACEMENT_CLOCK_IMT_H
#define PAGEREPLACEMENT_CLOCK_IMT_H

#include "../ImportantIncludes.h"
bool checkForPage(int page,vector<int> &frames, vector<bool> &reference_bitTable,int capacity,int &page_fault);
int replaceVictim(int page,vector<int> &frames, vector<bool> &reference_bitTable,int capacity,int clockHand);
void CLOCK_ReplacementPolicy(vector<int> pages,int capacity);
#endif //PAGEREPLACEMENT_CLOCK_IMT_H

//
// Created by rami96 on 4/5/19.
//
#include "CLOCK_Int.h"
bool checkForPage(int page,vector<int> &frames, vector<bool> &reference_bitTable,int capacity,int &page_fault)

{
    int i;
    int flag_empty =0;
    for(i = 0; i < capacity; i++)
    {

        if(frames[i] == page)
        {
            reference_bitTable[i] = true;
            printf("%02d     ",page);

            for(int j=0 ; j<frames.size() ; j++){
                if(frames[j] != -1)
                    printf("%02d ",frames[j]);
            }
            printf("\n");
            return true;
        }
    }

    for(int i=0 ; i<capacity ; i++){
        if(frames[i]==-1){
            printf("%02d     ",page);
            flag_empty = 1;
            break;
        }
    }
    if(flag_empty == 0){
        printf("%02d F   ",page);
        page_fault++;
    }
    return false;

}

int replaceVictim(int page,vector<int> &frames,
                  vector<bool> &reference_bitTable,int capacity,int clockHand)
{
    while(true)
    {

        if(!reference_bitTable[clockHand])
        {

            frames[clockHand] = page;

            for(int j=0 ; j<frames.size() ; j++){
                if(frames[j] != -1)
                    printf("%02d ",frames[j]);
            }
            printf("\n");
            reference_bitTable[clockHand] = true;
            return (clockHand+1)%capacity;
        }
        reference_bitTable[clockHand] = false;

        clockHand = (clockHand+1)%capacity;
    }
}

void CLOCK_ReplacementPolicy(vector<int> pages,int capacity){
    printf("Replacement Policy = CLOCK\n"
           "-------------------------------------\n");
    printf("Page   Content of Frames\n"
           "----   -----------------\n");

    int clockHand,page_faults;
    clockHand = 0;
    page_faults = 0;
    vector<int> frames(capacity,-1);
    vector<bool> reference_bitTable(capacity, false);


    for(int i = 0; i<pages.size(); i++)
    {

        if(!checkForPage(pages[i],frames,reference_bitTable,capacity,page_faults))
        {
            clockHand = replaceVictim(pages[i],frames,
                                      reference_bitTable,capacity,clockHand);
        }

    }
    printf("-------------------------------------\n"
           "Number of page faults = %d\n",page_faults);
}
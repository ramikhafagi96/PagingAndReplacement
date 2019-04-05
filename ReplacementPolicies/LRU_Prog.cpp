//
// Created by rami96 on 4/5/19.
//
#include "LRU_Int.h"
void LRU_ReplacementPolicy(vector<int> pages,int capacity){
    printf("Replacement Policy = LRU\n"
           "-------------------------------------\n");
    printf("Page   Content of Frames\n"
           "----   -----------------\n");
    vector<int> s;
    int found=0,index=0;

    map<int, int> indexes;

    int page_faults = 0;
    for (int i=0; i<pages.size(); i++)
    {
        if (s.size() < capacity)
        {

            for(int j=0 ; j<s.size() ; j++)
            {
                if(s[j] == pages[i])
                    found=1;
            }
            if(found==0){
                s.push_back(pages[i]);
                printf("%02d     ",pages[i]);
                for(int j=0 ; j<s.size() ; j++){
                    printf("%02d ",s[j]);
                }
                printf("\n");
            }
            else{
                printf("%02d     ",pages[i]);

                for(int j=0 ; j<s.size() ; j++){
                    printf("%02d ",s[j]);
                }
                printf("\n");
            }

            indexes[pages[i]] = i;
            found=0;
        }

        else
        {

            for(int j=0 ; j<s.size() ; j++)
            {
                if(s[j] == pages[i])
                    found=1;
            }
            if(found==0){
                int lru = INT_MAX,val;
                for(int j=0 ; j<s.size() ; j++){
                    if(indexes[s[j]] < lru){
                        lru = indexes[s[j]];
                        val = s[j];
                    }
                }
                for(int j=0 ; j<s.size() ; j++)
                {
                    if(s[j] == val)
                    {
                        index = j;
                        break;
                    }
                }
                s[index] = pages[i];
                printf("%02d F   ",pages[i]);
                for(int j=0 ; j<s.size() ; j++){
                    printf("%02d ",s[j]);
                }
                printf("\n");
                page_faults++;

            }
            else{
                printf("%02d     ",pages[i]);

                for(int j=0 ; j<s.size() ; j++){
                    printf("%02d ",s[j]);
                }
                printf("\n");
            }
            found = 0;
            indexes[pages[i]] = i;
        }
    }

    printf("-------------------------------------\n"
           "Number of page faults = %d\n",page_faults);
}
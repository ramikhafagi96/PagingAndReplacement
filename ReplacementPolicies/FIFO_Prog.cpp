//
// Created by rami96 on 4/5/19.
//
#include "FIFO_Int.h"
void FIFO_ReplacementPolicy(vector<int> pages,int capacity){
    printf("Replacement Policy = FIFO\n"
           "-------------------------------------\n");
    printf("Page   Content of Frames\n"
           "----   -----------------\n");

    vector<int> s;
    int found=0,index=0;
    queue<int> queue1;

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
                queue1.push(pages[i]);
            }
            else{
                printf("%02d     ",pages[i]);

                for(int j=0 ; j<s.size() ; j++){
                    printf("%02d ",s[j]);
                }
                printf("\n");
            }
            found = 0;
        }

        else
        {

            for(int j=0 ; j<s.size() ; j++)
            {
                if(s[j] == pages[i])
                    found=1;
            }
            if(found == 0)
            {
                int val = queue1.front();

                queue1.pop();
                for(int j=0 ; j<s.size() ; j++)
                {
                    if(s[j] == val)
                    {
                        index = j;
                        break;
                    }
                }
                s[index] = pages[i];

                queue1.push(pages[i]);
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

        }
    }
    printf("-------------------------------------\n"
           "Number of page faults = %d\n",page_faults);
}

#ifndef DYNAMICSEARCHING_H
#define DYNAMICSEARCHING_H 

#include<iostream>
#include<cstdlib>
#include<cmath>

class SearchSet
{
    std::string id = "noID";

    static int compare(const void* a, const void* b)
    {
        const int* x = (int*)a;
        const int* y = (int*)b;
        if(*x > *y) return 1;
        if(*x < *y) return -1;
        return 0;
    }

    public:
    SearchSet(std::string id){this->id = id;}
    SearchSet(){}

    // returns the id of SearchSet object
    std::string getID(){return this->id;}

    // returns the Index if found.
    // returns -1 if not found.
    template<typename lstype>
    int linearSearch(lstype item, lstype seq[], int seq_size)
    {
        int i;
        for(i = 0; i<seq_size; ++i)
        {lstype val = seq[i]; if(val == item) return i;} // found

        return -1; // not found
    }

    // used to linear search between a specific idx
    // returns the Index if found.
    // returns -1 if not found.
    template<typename lstype>
    int linearSearch(lstype item, lstype seq[], int start_idx, int end_idx)
    {
        for(int i = start_idx; i <= end_idx; ++i)
        {if(item == seq[i]) return i;} // found
        return -1; // not found
    }


    // returns Index if found, else -1
    // requirement : sorted iterable
    template<typename bstype>
    int binarySearch(bstype item, bstype seq[], int low, int high)
    {
        if(low == high)
        {
            if(item == seq[low]) return low;
            else return -1;
        }
        int mid = (low + high)/2;
        if(item == seq[mid]) return mid;
    
        if(item > seq[mid]) low = mid+1;
        else high = mid-1;

        return binarySearch(item, seq, low, high);
    }

    // uses Jump Search algorithm to search items
    // requires a sorted sequence
    // returns, 
    // Index : if found, 
    // -1 : if not found
    template<typename jstype>
    int jumpSearch(jstype item, jstype seq[], int size)
    {
        int jump_size = sqrt(size);
        int no_of_jumps = size/jump_size;
        int rem = size % jump_size;
        int i = 0;
        int idx;
        while(i <= no_of_jumps)
        {
            idx = i*jump_size;
            if(seq[idx] == item) return idx;
            if(seq[idx] > item) break;
            ++i;
        }
        if(i <= no_of_jumps) for(int j = (i-1)*jump_size; j < i*jump_size; ++j) if(item == seq[j]) return j;
        
        --i;
        for(int j = i*jump_size; j < size; ++j) if(item == seq[j]) return j;

        return -1;
    }
};
#endif
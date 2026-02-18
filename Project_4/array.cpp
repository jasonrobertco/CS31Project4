#include "array.h"
#include <string>

using namespace std;


int countOccurrences(const string a[], int n, string target)
{
    //error if no elements to check
    if (n < 0)
    return -1;

    //set up a match to return
    int count = 0;
    //simple loop to count only if matching
    for (int i = 0; i < n; i++){
        //if match add to count
        if(a[i] == target)
        count++;
    }

    //final return matches
    return count;
}


int locateOccurrence(const string a[], int n, string target)
{
    //error if no elements to check
    if (n < 0)
    return -1;
    
    //iterate thru array
    for (int i = 0; i < n; i++){
        //if match immediately return current index and end function
        if(a[i] == target)
        return i;
    }
    
    //no match
    return -1;
}


int locateMin(const string a[], int n)
{
    //n is number of words to compare
    //error if no elements to check
    if (n <= 0)
    return -1;
    int small = 0; 

    //iterate thru array
    for (int i = 1; i < n; i++){
        //c++ uses lexicographic order internally to compare
        if (a[i] < a[small])
        //if new small index found set small index
            small = i;
    }

    //return smallest index
    return small;
}


int eliminateDuplicates(string a[], int n)
{
    //error if no elements to check
    if (n < 0)
    return -1;
    //nothing to check
    if (n == 0)
    return 0;

    //retained since 0 is checked we can assume one unique char
    int r = 1;
    for (int i = 1; i < n; i++){
        //if we find a new char
        if (a[i] != a[i-1]){
            //write it to the next "unique spot" at index r
            a[r] = a[i];
            //increment r so that we can edit next element of array;
            r++;
        }
    }
    return r;
}


bool contains(const string a1[], int n1, const string a2[], int n2)
{
    
    return false;
}


int divide(string a[], int n, string divider)
{
    return -1;
}


int moveToBack(string a[], int n, int pos)
{
    return -1;
}


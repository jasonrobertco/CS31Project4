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
    //error if no elements to check
    if (n1 < 0 || n2 < 0)
    return false;
    if (n1 < n2)
    return false;
    if (n2 == 0)
    return true;

    int j = 0;
    //iterate thru array
    for (int i = 0; i < n1 && j < n2; i++){
        //increment FORWARD thru i, if j is found then increment next j find
        //ONLY MOVES FORWARD
        if (a1[i] == a2[j]){
            j++;
        }
    }
    //if matches properly
    if(j == n2)
    return true;
    //else return false
    return false;
}

// j is the end of the left section
// i leads j

// j grows left and i scans and if an element is found j grows to contain it
// i keeps going right regardless
int divide(string a[], int n, string divider)
{
    //error if no elements to check
    if (n < 0)
    return -1;

    //boundary
    int j = 0;

    for (int i = 0; i < n; i++){
        //if a is less than divider
        if (a[i] < divider){
            //temp swaps a[i] with a[j]
            //move to the left section 
            string temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            // i is on the right of j
            // >= divider pushed right
            j++;
        }
    }
    return j;
}


int moveToBack(string a[], int n, int pos)
{
    //error if no elements to check
    if (n <= 0 || pos < 0 || pos >= n)
    return -1;
    string temp = a[pos];
    for (int i = pos; i < n-1; i++){
        a[i] = a[i+1];
    }
    a[n-1] = temp;
    //spec says return position
    return pos;
}


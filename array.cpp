/*
405941013
Jason Co

The biggest challeges I faced were the constraints for not create new arrays or 
simply writing pseduocode to find methods wihtin bounds on how each funciton should work

especially for divide, I had trouble figuring out where to actually section it.
I found that the array should be build sort of like a slider that mobes
by incrementing, we could move the divider and basically say ok based on the current elments that we have checked,
they should be sorted into < and >= the divisor string
once that was accomplished, we could move this slider/divider over as we icnremented and added new elements.
This allowed us to not delete teh array ut to rewtite it in itself which I had trouble doing


similarly I had trouble with contains
I initially didn't understand that subsequences were sued so as a result I was having some trouble with the loops
and determining if I waws going about it right. understanding the rpoblem fully allowed me to write. abetter solution
since were onyl checking the a1 stirng once and goign from left to right, were able to move in order form left to righ in the 2nd string as well

this means that the array could be done in one opass and we could say ok we found this element, now lets icnrement a2 to 
check a1 for the nex telmenet
*/

#include "array.h"
#include <string>

using namespace std;

/*
used a for loop to pass over and count if they are matching
a counter is incremented and returned
*/
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

/*
used a for loop to iterature through and return the match index when found and stop the loop

*/
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

/*
used a for loop and logic to comapre with a temp variable small
this small stores the "smallest word"
each word in the array is compared to this smallest word to see if its smaller
at the end return the smallest word that was found
*/

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

/*
rewriting the array based on retained r
we are finding unique elments so we are able to rewrite over non unique elements

we are keeping a separate counter r that defines not only unique lements but also serves as a way
to tell the array what value to overwrite when there is a duplicate

using a for loop, iterates over the whole arary and seraches for non matches to write over, matches do not do anything

we only need to return the number of unique elements and the eliminated duplicate array so we are not modifying the og size of the array
*/

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

/*
• Why contains correctly determines subsequence membership.

we scan a1 from left to right without moving backward
a2 is moved only when a match is found
this makes sure that a2 appears in the order in a1

-> returns true when a2 is a subsequence of a1


*/


/*

Any edge cases that required special handling

we are dealding with multiple arguments two of which are arrays

these arrays need to have a non negative number of elements

it can be 0 because technically the 0 case is found if both are blank

because we are finding a2 in its order in a1, a2 can be less than or equal to a1
but not greater than because the principle of suvsequence

*/

/*
uses a for loop to nomrally increment through a1 left to right 
contains uses counter j in order to increment through the 2nd array a2

j is onyl icnremented when a succesful match is found

we only care about the true case and every other case is false

inthe true case the consecutive order allows j to be incremented while passign through i 
while they are both left to right

so if the correct number of j matches match the elements of n2, then we can return true


*/
bool contains(const string a1[], int n1, const string a2[], int n2)
{
    //error if no elements to check
    if (n1 < 0 || n2 < 0)
    return false;
    if (n2 == 0)
    return true;
    if (n1 < n2)
    return false;
    

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



/*
The condition that is true for each iteration of your loop in divide

the condition that is true is that

all elements 0 to j-1 < divier
all elements j to i-1 >= divider

i+ has NOT been seen yet
the current i has not been seen yet


for divide we "build" the array by checking
the left eleemts are < divider
as i moves, j the boundary is built

if a less than is found, j moves over to make space for it

all greater thans maintain their space and j only moves when ncessary

*/
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

/*
stores the variable to be moved to the back
uses a for loop starts from the index of the position
we make it equal to the next element

for the last element we make it equal to the temp variable
*/
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


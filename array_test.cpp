#include "array.h"
#include <string>
#include <cassert>

using namespace std;

int main()
{
        string fruit[5] = {"apple", "banana", "apple", "cherry", "apple"};
        /// counts 3 occurences of apple 5 elements checked
        assert(countOccurrences(fruit, 5, "apple") == 3);
        //counts 0 occurences of pear 5 elements checjed
        assert(countOccurrences(fruit, 5, "pear") == 0);
        //is invalid cause cannot check -1 elements return -1
        assert(countOccurrences(fruit, -1, "apple") == -1);
        // testing n = 0 case should be valid counts - elements of apple
        assert(countOccurrences(fruit, 0, "apple") == 0);


        string pets[5] = {"cat", "dog", "bird", "dog", "fish"};
        // finds first occurence of dog should be at 1 in 5 elements
        assert(locateOccurrence(pets, 5, "dog") == 1);
        // finds first occurence of fish should be at 4 in 5 elements
        assert(locateOccurrence(pets, 5, "fish") == 4);
        // should not be able to find cow returns -1
        assert(locateOccurrence(pets, 5, "cow") == -1);
        //testing -1 case should be invalid cannot search -1 elements
        assert(locateOccurrence(pets, -1, "puppyyyyy") == -1);

        string icao[5] = {"delta", "alpha", "charlie", "alpha", "echo"};
        // returns the alpha smallest
        assert(locateMin(icao, 5) == 1);  // first "alpha"
        //single elements returns itself 0
        assert(locateMin(icao, 1) == 0);
        //invalid cases
        assert(locateMin(icao, 0) == -1);
        //invalid as well
        assert(locateMin(icao, -1) == -1);

        string letters1[7] = {"a", "a", "b", "b", "b", "c", "c"};
        int r = eliminateDuplicates(letters1, 7);
        // retained elemenets should be 3
        assert(r == 3);
        // we check all 3 elements to see if it is a b c in that order
        assert(letters1[0] == "a");
        assert(letters1[1] == "b");
        assert(letters1[2] == "c");

        //testing for single
        string singletest[1] = {"a"};
        //single is unchanged
        assert(eliminateDuplicates(singletest, 1) == 1);
        //invalid cause -1 is not acceptable
        assert(eliminateDuplicates(singletest, -1) == -1);


        //testing for empty caes
        string empty[1];
        
        string a1[6] = {"a", "b", "c", "d", "e", "f"};
        string a2[3] = {"b", "d", "f"};

        //b d f does appear so it should be true
        assert(contains(a1, 6, a2, 3) == true);
        // an empty sub is true
        assert(contains(a1, 6, empty, 0) == true);
        //invalid n1 is false
        assert(contains(a1, -1, a2, 3) == false);
        //wrong order d is not found because we move a1 left to right so sohuld be false
        string a3[3] = {"b", "f", "d"};
        assert(contains(a1, 6, a3, 3) == false);

        string moreFruit[6] = {"mango", "apple", "pear", "banana", "grape", "kiwi"};
        //divide sohuld divide by mango
        int pos = divide(moreFruit, 6, "mango");
	assert(pos == 4);

        //all elemenets left
        string letters2[3] = {"a", "b", "c"};
        assert(divide(letters2, 3, "z") == 3);


        //divide test parition
        assert(pos >= 0 && pos <= 6);

        // Check LEFT everything before pos must be < divider ("mango")
        for (int i = 0; i < pos; i++)
        assert(moreFruit[i] < "mango");
        // Check right >= mango
        for (int i = pos; i < 6; i++)
        assert(moreFruit[i] >= "mango");

        //move index 2 to end
        //c get spushed to end
        string letters3[5] = {"a", "b", "c", "d", "e"};
        assert(moveToBack(letters3, 5, 2) == 2);
        assert(letters3[4] == "c");
        assert(letters3[0] == "a");
        assert(letters3[1] == "b");
        assert(letters3[2] == "d");
        assert(letters3[3] == "e");
        //other cases invalid shoudl return -1
        assert(moveToBack(letters3, 5, -1) == -1);
        assert(moveToBack(letters3, 5, 5) == -1);
        assert(moveToBack(letters3, 0, 0) == -1);


    return 0;
}


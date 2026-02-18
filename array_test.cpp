#include "array.h"
#include <string>
#include <cassert>

using namespace std;

int main()
{
        string fruit[5] = {"apple", "banana", "apple", "cherry", "apple"};
        assert(countOccurrences(fruit, 5, "apple") == 3);
        assert(countOccurrences(fruit, 5, "pear") == 0);
        assert(countOccurrences(fruit, -1, "apple") == -1);

        string pets[5] = {"cat", "dog", "bird", "dog", "fish"};
        assert(locateOccurrence(pets, 5, "dog") == 1);
        assert(locateOccurrence(pets, 5, "fish") == 4);
        assert(locateOccurrence(pets, 5, "cow") == -1);

        string icao[5] = {"delta", "alpha", "charlie", "alpha", "echo"};
        assert(locateMin(icao, 5) == 1);  // first "alpha"
        assert(locateMin(icao, 1) == 0);

        string letters1[7] = {"a", "a", "b", "b", "b", "c", "c"};
        int r = eliminateDuplicates(letters1, 7);
        assert(r == 3);
        assert(letters1[0] == "a");
        assert(letters1[1] == "b");
        assert(letters1[2] == "c");

        string a1[6] = {"a", "b", "c", "d", "e", "f"};
        string a2[3] = {"b", "d", "f"};
        assert(contains(a1, 6, a2, 3) == true);

        string a3[3] = {"b", "f", "d"};
        assert(contains(a1, 6, a3, 3) == false);

        string moreFruit[6] = {"mango", "apple", "pear", "banana", "grape", "kiwi"};
        int pos = divide(moreFruit, 6, "mango");
	assert(pos == 4);

        string letters2[3] = {"a", "b", "c"};
        assert(divide(letters2, 3, "z") == 3);

        string letters3[5] = {"a", "b", "c", "d", "e"};
        assert(moveToBack(letters3, 5, 2) == 2);
        assert(letters3[4] == "c");
        assert(letters3[0] == "a");
        assert(letters3[1] == "b");
        assert(letters3[2] == "d");
        assert(letters3[3] == "e");


    return 0;
}


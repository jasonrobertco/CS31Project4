#ifndef ARRAY_H
#define ARRAY_H

#include <string>
using namespace std;

int countOccurrences(const string a[], int n, string target);

int locateOccurrence(const string a[], int n, string target);

int locateMin(const string a[], int n);

int eliminateDuplicates(string a[], int n);

bool contains(const string a1[], int n1, const string a2[], int n2);

int divide(string a[], int n, string divider);

int moveToBack(string a[], int n, int pos);

#endif


// Question 33: Write a program to print the count of duplicate characters in a  string.

// Source: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// Approach 1: Using hashing
T.C: O(n), where n = length of the string passed
S.C: O(NO_OF_CHARS)

#include <iostream>
using namespace std;
# define NO_OF_CHARS 256
 
class gfg
{
    public :
     
    /* Fills count array with
    frequency of characters */
    void fillCharCounts(char *str, int *count)
    {
        int i;
        for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
    }
 
    /* Print duplicates present
    in the passed string */
    void printDups(char *str)
    {
         
        // Create an array of size 256 and fill
        // count of every character in it
        int *count = (int *)calloc(NO_OF_CHARS,
                                      sizeof(int));
        fillCharCounts(str, count);
 
        // Print characters having count more than 0
        int i;
        for (i = 0; i < NO_OF_CHARS; i++)
        if(count[i] > 1)
            printf("%c, count = %d \n", i, count[i]);
 
        free(count);
    }
};
 
/* Driver code*/
int main()
{
    gfg g ;
    char str[] = "test string";
    g.printDups(str);
    //getchar();
    return 0;
}

// Approach 2: Using Maps(best Approach)
The approach is the same as discussed in Method 1, but, using a map to store the count.
T.C: O(N*log(N)), where N = length of the string passed and it generally takes O(log(N)) time for an element insertion in a map. 
S.C: O(K), where K = size of the map (0<=K<=input_string_length).

#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }
 
    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
/* Driver code*/
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}

// Aprroach 3: Using Unordered Map(best Approach)
T.C: O(N), where N = length of the string passed and it takes O(1) time to insert and access any element in an unordered map
S.C: O(K), where K = size of the map (0<=K<=input_string_length).

#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;  //increase the count of characters by 1
    }
  
    for (auto it : count) {   //iterating through the unordered map
        if (it.second > 1)   //if the count of characters is greater then 1 then duplicate found
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
/* Driver code*/
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}

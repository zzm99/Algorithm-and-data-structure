// string hashTable[21];
// int hashTableSize = 21;

// void insert(string s)
// {
//     //Compute the index using the hash function1
//     int index = hashFunc1(s);
//     int indexH = hashFunc2(s);
//     //Search for an unused slot and if the index exceeds the hashTableSize roll back
//     while(hashTable[index] != "")
//         index = (index + indexH) % hashTableSize;
//     hashTable[index] = s;
// }

// void search(string s)
// {
//     //Compute the index using the hash function
//     int index = hashFunc1(s);
//     int indexH = hashFunc2(s);
//      //Search for an unused slot and if the index exceeds the hashTableSize roll back
//     while(hashTable[index] != s and hashTable[index] != "")
//         index = (index + indexH) % hashTableSize;
//     //Is the element present in the hash table
//     if(hashTable[index] == s)
//         cout << s << " is found!" << endl;
//     else
//         cout << s << " is not found!" << endl;
// }

// First hash function is typically hash1(key) = key % TABLE_SIZE

// A popular second hash function is : hash2(key) = PRIME – (key % PRIME) where PRIME is a prime smaller than the TABLE_SIZE.

// A good second Hash function is:

// It must never evaluate to zero
// Must make sure that all cells can be probed

// CPP program to implement double hashing 
#include <bits/stdc++.h> 
using namespace std; 
  
// Hash table size 
#define TABLE_SIZE 13 
  
// Used in second hash function. 
#define PRIME 7 
  
class DoubleHash 
{ 
    // Pointer to an array containing buckets 
    int *hashTable; 
    int curr_size; 
public: 
    // function to check if hash table is full 
    bool isFull() 
    { 
        // if hash size reaches maximum size 
        return (curr_size == TABLE_SIZE); 
    } 
  
    // function to calculate first hash 
    int hash1(int key) 
    { 
        return (key % TABLE_SIZE); 
    } 
  
    // function to calculate second hash 
    int hash2(int key) 
    { 
        return (PRIME - (key % PRIME)); 
    } 
  
    DoubleHash() 
    { 
        hashTable = new int[TABLE_SIZE]; 
        curr_size = 0; 
        for (int i=0; i<TABLE_SIZE; i++) 
            hashTable[i] = -1; 
    } 
  
    // function to insert key into hash table 
    void insertHash(int key) 
    { 
        // if hash table is full 
        if (isFull()) 
            return; 
  
        // get index from first hash 
        int index = hash1(key); 
  
        // if collision occurs 
        if (hashTable[index] != -1) 
        { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) 
            { 
                // get newIndex 
                int newIndex = (index + i * index2) % TABLE_SIZE; 
                // if no collision occurs, store 
                // the key 
                if (hashTable[newIndex] == -1) 
                { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
        // if no collision occurs 
        else
            hashTable[index] = key; 
        curr_size++; 
    } 
  
    // function to display the hash table 
    void displayHash() 
    { 
        for (int i = 0; i < TABLE_SIZE; i++) 
        { 
            if (hashTable[i] != -1) 
                cout << i << " --> " << hashTable[i] << endl; 
            else
                cout << i << endl; 
        } 
    } 
}; 
  
// Driver's code 
int main() 
{ 
    int a[] = {19, 27, 36, 10, 64}; 
    int n = sizeof(a)/sizeof(a[0]); 
  
    // inserting keys into hash table 
    DoubleHash h; 
    for (int i = 0; i < n; i++) 
        h.insertHash(a[i]); 
  
    // display the hash Table 
    h.displayHash(); 
    return 0; 
} 
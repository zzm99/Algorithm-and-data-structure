string hashTable[21];
int hashTableSize = 21;

void insert(string s)
{
    //Compute the index using the hash function
    int index = hashFunc(s);
    //Search for an unused slot and if the index will exceed the hashTableSize roll back
    int h = 1;
    while(hashTable[index] != "")
    {
        index = (index + h*h) % hashTableSize;
             h++;
    }
    hashTable[index] = s;
}

void search(string s)
{
    //Compute the index using the Hash Function
    int index = hashFunc(s);
     //Search for an unused slot and if the index will exceed the hashTableSize roll back
   int h = 1;
    while(hashTable[index] != s and hashTable[index] != "")
    {
        index = (index + h*h) % hashTableSize;
             h++;
    }
    //Is the element present in the hash table
    if(hashTable[index] == s)
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;
}
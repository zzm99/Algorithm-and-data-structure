// Hashing is a technique that is used to uniquely identify a specific object from a group of similar objects.
// In hashing, large keys are converted into small keys by using hash functions. 
// The values are then stored in a data structure called hash table. 
// The idea of hashing is to distribute entries (key/value pairs) uniformly across an array.
// Each element is assigned a key (converted key). By using that key you can access the element in O(1) time.
// Using the key, the algorithm (hash function) computes an index that suggests where an entry can be found or inserted.

// Implementing own Hash Table with Open Addressing Linear Probing in C++

// Search(k): Keep probing until slot’s key doesn’t become equal to k or an empty slot is reached.

// Delete(k): Delete operation is interesting. If we simply delete a key, then search may fail. So slots of deleted keys are marked specially as “deleted”.
// Insert can insert an item in a deleted slot, but the search doesn’t stop at a deleted slot.

// https://www.geeksforgeeks.org/hashing-set-3-open-addressing/
// https://coderworld109.blogspot.com/2018/01/basics-of-hash-tables-hash-data.html

// Assumption:
// There are no more than 20 elements in the data set.
// Hash function will return an integer from 0 to 19.
// Data set must have unique elements.


#include <bits/stdc++.h>
using namespace std;

string hashTable[21];
int hashTableSize = 21;

void insert(string s){
	int index = hashFunc(s);

	while(hashTable[index] != "")
		index = (index + 1) % hashTableSize;
	hashTable[index] = s;
}

void search(string s){
	int index = hashFunc(s);

	while(hashTable[index] != s && hashTable[index] != "")
		index = (index + 1) % hashTableSize;

	if(hashTable[index] == s)
		cout << s << " is found!" << endl;
	else 
		cout << s << " is not found!" << endl;
}


/*
#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>

class HashNode{
public:
	V value;
	K key;

	HashNode(K key, V value)
	{
		this->value = value;
		this->key = key;
	}
};

template <typename K, typename V>
class HashMap{
	HashNode<K, V> **arr; // a pointer of the array of hashnode
	int capacity; // max_size
	int size;	// cur_size
	HashNode<K, V> *dummy; // dummy node

public:
	HashMap(){
		capacity = 20;
		size = 0;
		arr = new HashNode<K, V>*[capacity];
		for(int i=0; i<capacity; i++){
			arr[i] = NULL;
		}
		//dummy node with value and key -1 
		dummy = new HashNode<K,V>(-1, -1);
	}

	int hashCode(K key){
		return key % capacity;
	}

	void insertNode(K key, V value){
		HashNode<K, V> *temp = new HashNode<K, V>(key, value);
		int hashIndex = hashCode(key); // key相等的node会覆盖前者保存
		while(arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1){
			hashIndex++;
			hashIndex %= capacity;
		}
		if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
			size++;
		arr[hashIndex] = temp;
	}

	V deleteNode(int key){
		int hashIndex = hashCode(key);
		while(arr[hashIndex] != NULL){
			if(arr[hashIndex]->key == key){
				HashNode<K, V> *temp = arr[hashIndex];
				arr[hashIndex] = dummy;
				size--;
				return temp->value;
			}
			hashIndex++;
			hashIndex %= capacity;
		}
		return NULL;
	}

	V get(int key){
		int hashIndex = hashCode(key);
		while(arr[hashIndex] != NULL){
			int counter = 0;
			if(counter++ > capacity)
				return NULL;
			if(arr[hashIndex]->key == key)
				return arr[hashIndex]->value;
			hashIndex++;
			hashIndex %= capacity;
		}
		return NULL;
	}

	int sizeofMap(){
		return size;
	}

	bool isEmpty(){
		return size == 0;
	}
	
	void display(){
		for(int i=0; i<capacity; i++){
			if(arr[i] != NULL && arr[i]->key != -1)
				cout << "key = " << arr[i]->key << " value = " << arr[i]->value << endl;	
		}
	}
};

int main() 
{ 
    HashMap<int, int> *h = new HashMap<int, int>; 
    h->insertNode(1,1); 
    h->insertNode(2,2); 
    h->insertNode(2,3); 
    h->display(); 
    cout << h->sizeofMap() <<endl; 
    cout << h->deleteNode(2) << endl; 
    cout << h->sizeofMap() <<endl; 
    cout << h->isEmpty() << endl; 
    cout << h->get(2) << endl; 
    return 0; 
} 


*/
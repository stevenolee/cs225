/**
 * @file dhhashtable.cpp
 * Implementation of the DHHashTable class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */
#include "dhhashtable.h"

using hashes::hash;
using hashes::secondary_hash;
using std::pair;


template <class K, class V>
DHHashTable<K, V>::DHHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new pair<K, V>*[size];
    should_probe = new bool[size];
    for (size_t i = 0; i < size; i++) {
        table[i] = NULL;
        should_probe[i] = false;
    }
    elems = 0;
}

template <class K, class V>
DHHashTable<K, V>::~DHHashTable()
{
    destroy();
}

template <class K, class V>
DHHashTable<K, V> const& DHHashTable<K, V>::operator=(DHHashTable const& rhs)
{
    if (this != &rhs) {
        destroy();

        copy(rhs);
    }
    return *this;
}

template <class K, class V>
DHHashTable<K, V>::DHHashTable(DHHashTable<K, V> const& other)
{
    copy(other);
}


template <class K, class V>
void DHHashTable<K, V>::destroy()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table; table = nullptr;
    delete[] should_probe; should_probe = nullptr;
}

template <class K, class V>
void DHHashTable<K, V>::copy(const DHHashTable<K, V>& other)
{
    table = new pair<K, V>*[other.size];
    should_probe = new bool[other.size];
    for (size_t i = 0; i < other.size; i++) {
        should_probe[i] = other.should_probe[i];
        if (other.table[i] == NULL)
            table[i] = NULL;
        else
            table[i] = new pair<K, V>(*(other.table[i]));
    }
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void DHHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     * @note Remember to resize the table when necessary (load factor >=
     *  0.7). **Do this check *after* increasing elems!!** Also, don't
     *  forget to mark the cell for probing with should_probe!
     */
	elems++;	
	if (shouldResize()){
		resizeTable();
	}
	int index = hash(key, size);
// can insert at first hash found
	if (table[index] == NULL){
		pair<K, V>* add = new pair<K, V>(key, value);
		table[index] = add;
		should_probe[index] = false;
		return;
	}
// rehash
	int count = 0;
	int factor = secondary_hash(key, size);
	int startingIndex = index;
// find where we can insert
	while (/*should_probe[index]*/1){
// never found
		if (startingIndex == index && count != 0){
			return;
		}
// found
		if (table[index] == NULL){
			pair<K, V>* add = new pair<K, V>(key, value);
			table[index] = add;
			should_probe[index] = false;
			return;
		}
		index = (index + secondary_hash(key, size)*count++) % size;
	}






//    (void) key;   // prevent warnings... When you implement this function, remove this line.
//    (void) value; // prevent warnings... When you implement this function, remove this line.
}

template <class K, class V>
void DHHashTable<K, V>::remove(K const& key)
{
    /**
     * @todo Implement this function
     */
/*	elems--;
	int index = findIndex(key);
	if (table[index] == NULL){
		return;
	}
	table[index] = NULL;
*/

	elems--;
	int index = hash(key, size);
	if (table[index] == NULL){
		return;
	}
	if (table[index]->first != key){
		int startingIndex = index;
		int count = 0;
		while (1){
			if (startingIndex == index && count != 0){
				return;
			}
			if (table[index] != NULL && table[index]->first == key){
				break;
			}		

			index = (index + secondary_hash(key, size)*count++) % size;
		}		
	}
	for (int i = index; i < (int)size - 1; i++){
		table[i] = table[i+1];
		should_probe[i] = should_probe[i+1];
	}
	table[(int)size - 1] = NULL;
	should_probe[(int)size - 1] = false;

}

template <class K, class V>
int DHHashTable<K, V>::findIndex(const K& key) const
{
    /**
     * @todo Implement this function
     */
/*
	int index = hash(key, size);
	if (table[index] == NULL){
		return -1;
	}
	else if (table[index]->first == key){
		return index;
	}

    return -1;
*/
	int startingIndex = hash(key, size);
	int index = startingIndex;
	int count = 0;
// stop probing when found 
	while (/*should_probe[index]*/1){
		if (startingIndex == index && count != 0){
			break;
		}
		if (table[index] != NULL && table[index]->first == key){
			return index;
		}		


		index = (index + secondary_hash(key, size)*count++) % size;
	}
    return -1;
}

template <class K, class V>
V DHHashTable<K, V>::find(K const& key) const
{
    int idx = findIndex(key);
    if (idx != -1)
        return table[idx]->second;
    return V();
}

template <class K, class V>
V& DHHashTable<K, V>::operator[](K const& key)
{
    // First, attempt to find the key and return its value by reference
    int idx = findIndex(key);
    if (idx == -1) {
        // otherwise, insert the default value and return it
        insert(key, V());
        idx = findIndex(key);
    }
    return table[idx]->second;
}

template <class K, class V>
bool DHHashTable<K, V>::keyExists(K const& key) const
{
    return findIndex(key) != -1;
}

template <class K, class V>
void DHHashTable<K, V>::clear()
{
    destroy();

    table = new pair<K, V>*[17];
    should_probe = new bool[17];
    for (size_t i = 0; i < 17; i++)
        should_probe[i] = false;
    size = 17;
    elems = 0;
}

template <class K, class V>
void DHHashTable<K, V>::resizeTable()
{
    size_t newSize = findPrime(size * 2);
    pair<K, V>** temp = new pair<K, V>*[newSize];
    delete[] should_probe;
    should_probe = new bool[newSize];
    for (size_t i = 0; i < newSize; i++) {
        temp[i] = NULL;
        should_probe[i] = false;
    }

    for (size_t slot = 0; slot < size; slot++) {
        if (table[slot] != NULL) {
            size_t h = hash(table[slot]->first, newSize);
            size_t jump = secondary_hash(table[slot]->first, newSize);
            size_t i = 0;
            size_t idx = h; 
            while (temp[idx] != NULL)
            {
                ++i;
                idx = (h + jump*i) % newSize;
            }
            temp[idx] = table[slot];
            should_probe[idx] = true;
        }
    }

    delete[] table;
    // don't delete elements since we just moved their pointers around
    table = temp;
    size = newSize;
}

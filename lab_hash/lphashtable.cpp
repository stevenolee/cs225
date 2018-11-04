/**
 * @file lphashtable.cpp
 * Implementation of the LPHashTable class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */
#include "lphashtable.h"
#include <iostream>

using hashes::hash;
using std::pair;

template <class K, class V>
LPHashTable<K, V>::LPHashTable(size_t tsize)
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
LPHashTable<K, V>::~LPHashTable()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
}

template <class K, class V>
LPHashTable<K, V> const& LPHashTable<K, V>::operator=(LPHashTable const& rhs)
{
    if (this != &rhs) {
        for (size_t i = 0; i < size; i++)
            delete table[i];
        delete[] table;
        delete[] should_probe;

        table = new pair<K, V>*[rhs.size];
        should_probe = new bool[rhs.size];
        for (size_t i = 0; i < rhs.size; i++) {
            should_probe[i] = rhs.should_probe[i];
            if (rhs.table[i] == NULL)
                table[i] = NULL;
            else
                table[i] = new pair<K, V>(*(rhs.table[i]));
        }
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
LPHashTable<K, V>::LPHashTable(LPHashTable<K, V> const& other)
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
void LPHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     * @note Remember to resize the table when necessary (load factor >= 0.7).
     * **Do this check *after* increasing elems (but before inserting)!!**
     * Also, don't forget to mark the cell for probing with should _probe!
     */
std::cout << key << ", " << value << std::endl;
	bool inserted = false;
	elems++;
	if (shouldResize()){
		resizeTable();
	}
	int index = hash(key, size);
// if able to insert
	if (should_probe[index] == false){
		pair<K, V>* add = new pair<K, V>(key, value);
		table[index] = add;
		should_probe[index] = true;
		inserted = true;
	}
// should probe
	else if (!inserted) {	
// from index to end
		for (int i = index; i < (int)size; i++){
			if (should_probe[i] == false){
				pair<K, V>* add = new pair<K, V>(key, value);
				table[i] = add;
				should_probe[i] = true;
				inserted = true;
				break;
			}
		}
	}
	else if (!inserted){
// from beginning to index
		for (int i = 0; i < index; i++){
			if (table[i] == NULL){
				pair<K, V>* add = new pair<K, V>(key, value);
				table[i] = add;
				should_probe[i] = true;
				inserted = true;
				break;
				}
			}
	}
}

template <class K, class V>
void LPHashTable<K, V>::remove(K const& key)
{
    /**
     * @todo: implement this function
     */
	elems--;
	int index = hash(key, size);
	if (table[index] == NULL){
		return;
	}
	if (table[index]->first != key){
		return;
	}
	for (int i = index; i < (int)size - 1; i++){
		table[i] = table[i+1];
		should_probe[i] = should_probe[i+1];
	}
	table[(int)size - 1] = NULL;
	should_probe[(int)size - 1] = false;
std::cout << "REMOVE THO_________________________________________: " << key << std::endl;
}

template <class K, class V>
int LPHashTable<K, V>::findIndex(const K& key) const
{
    
    /**
     * @todo Implement this function
     *
     * Be careful in determining when the key is not in the table!
     */
	int index = hash(key, size);
	if (table[index] == NULL){
		return -1;
	}
	else if (table[index]->first == key){
		return index;
	}

    return -1;
}

template <class K, class V>
V LPHashTable<K, V>::find(K const& key) const
{
    int idx = findIndex(key);
    if (idx != -1)
        return table[idx]->second;
    return V();
}

template <class K, class V>
V& LPHashTable<K, V>::operator[](K const& key)
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
bool LPHashTable<K, V>::keyExists(K const& key) const
{
    return findIndex(key) != -1;
}

template <class K, class V>
void LPHashTable<K, V>::clear()
{
    for (size_t i = 0; i < size; i++)
        delete table[i];
    delete[] table;
    delete[] should_probe;
    table = new pair<K, V>*[17];
    should_probe = new bool[17];
    for (size_t i = 0; i < 17; i++)
        should_probe[i] = false;
    size = 17;
    elems = 0;
}

template <class K, class V>
void LPHashTable<K, V>::resizeTable()
{

    /**
     * @todo Implement this function
     *
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */
	auto newSize = (int)findPrime(size*2);
    pair<K, V>** newTable = new pair<K, V>*[newSize];
    bool* newProbe = new bool[newSize];

	auto oldElems = elems;
	pair<K, V>* pointer = NULL;
	for (int i = 0; i < newSize; i++){
		newTable[i] = NULL;
		newProbe[i] = false;
	}
	for (int i = 0; i < (int)size; i++){

		bool inserted = false;
		if (table[i] == NULL){
			newTable[i] = NULL;
			continue;
		}
		K key = table[i]->first;
		V value = table[i]->second;
		int index = hash(key, newSize);
// ________________________________________________________________________________________insert begin
// if able to insert
	if (newProbe[index] == false){
		pair<K, V>* add = new pair<K, V>(key, value);
		newTable[index] = add;
		newProbe[index] = true;
		inserted = true;
	}
// should probe
	else if (!inserted) {	
// from index to end
		for (int i = index; i < (int)newSize; i++){
			if (newProbe[i] == false){
				pair<K, V>* add = new pair<K, V>(key, value);
				newTable[i] = add;
				newProbe[i] = true;
				inserted = true;
				break;
			}
		}
	}
	else if (!inserted){
// from beginning to index
		for (int i = 0; i < index; i++){
			if (newTable[i] == NULL){
				pair<K, V>* add = new pair<K, V>(key, value);
				newTable[i] = add;
				newProbe[i] = true;
				inserted = true;
				break;
				}
			}
	}

// ________________________________________________________________________________________insert end 
//		newTable[i] = table[i];
//		newProbe[i] = should_probe[i];
//		delete table[i];
std::cout << "RESIZEEEE_______" << key << ", " << value << " size: " << size << "->" << newSize << std::endl;
	}
	delete [] table;
	delete [] should_probe;
	table = newTable;
	should_probe = newProbe;
	size = newSize;
	elems = oldElems;
}

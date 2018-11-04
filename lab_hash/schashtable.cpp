/**
 * @file schashtable.cpp
 * Implementation of the SCHashTable class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */

#include "schashtable.h"
#include <iostream>
#include <vector>
using hashes::hash;
using std::list;
using std::pair;
  
template <class K, class V>
SCHashTable<K, V>::SCHashTable(size_t tsize)
{
    if (tsize <= 0)
        tsize = 17;
    size = findPrime(tsize);
    table = new list<pair<K, V>>[size];
    elems = 0;
}

template <class K, class V>
SCHashTable<K, V>::~SCHashTable()
{
    delete[] table;
}

template <class K, class V>
SCHashTable<K, V> const& SCHashTable<K, V>::
operator=(SCHashTable<K, V> const& rhs)
{
    if (this != &rhs) {
        delete[] table;
        table = new list<pair<K, V>>[rhs.size];
        for (size_t i = 0; i < rhs.size; i++)
            table[i] = rhs.table[i];
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
SCHashTable<K, V>::SCHashTable(SCHashTable<K, V> const& other)
{
    table = new list<pair<K, V>>[other.size];
    for (size_t i = 0; i < other.size; i++)
        table[i] = other.table[i];
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void SCHashTable<K, V>::insert(K const& key, V const& value)
{

    /**
     * @todo Implement this function.
     *
     */
//	list<pair<K, V>>:: iterator it = table[0].begin();
// create pair
	pair<K, V> add = pair<K, V>(key, value);
// calculate hash
	int index = hash(key, size);
// insert pair at index
	table[index].push_back(add);
	elems++;
//std::cout << add.first << " " << add.second << std::endl;
//std::cout << elems << "/" << size << std::endl << std::endl;
//std::cout << "ELEMS: " << elems << std::endl;
//std::cout << "SIZE: " << size << std::endl;
	if (shouldResize()){
//std::cout << "RESIZINGGGGGGGG__________________" << std::endl;
		resizeTable();
	}
}

template <class K, class V>
void SCHashTable<K, V>::remove(K const& key)
{
    typename list<pair<K, V>>::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the lab spec about list iterators and the
     * erase() function on std::list!
     */
	elems--;
	int index = hash(key, size);
	it = table[index].begin();
	while (it != table[index].end()){
		if (it->first == key){
			break;
		}
		it++;
	}
	table[index].erase(it);
//	for (int i = index; i < (int)size - 1; i++){
//		table[i] = table[i+1];
//	}
	

//    (void) key; // prevent warnings... When you implement this function, remove this line.
}

template <class K, class V>
V SCHashTable<K, V>::find(K const& key) const
{

    /**
     * @todo: Implement this function.
     */
	int index = hash(key, size);
	for(auto item : table[index])
	{
		if (item.first == key){
			return item.second;
		}
	}

    return V();
}

template <class K, class V>
V& SCHashTable<K, V>::operator[](K const& key)
{
    size_t idx = hash(key, size);
    typename list<pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return it->second;
    }

    // was not found, insert a default-constructed version and return it
    ++elems;
    if (shouldResize())
        resizeTable();

    idx = hash(key, size);
    pair<K, V> p(key, V());
    table[idx].push_front(p);
    return table[idx].front().second;
}

template <class K, class V>
bool SCHashTable<K, V>::keyExists(K const& key) const
{
    size_t idx = hash(key, size);
    typename list<pair<K, V>>::iterator it;
    for (it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key)
            return true;
    }
    return false;
}

template <class K, class V>
void SCHashTable<K, V>::clear()
{
    delete[] table;
    table = new list<pair<K, V>>[17];
    size = 17;
    elems = 0;
}

template <class K, class V>
void SCHashTable<K, V>::resizeTable()
{
    typename list<pair<K, V>>::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the spec about list iterators!
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */
//std::cout << "________________________FUCK_________________" << std::endl << std::endl << std::endl;
	auto oldElems = elems;
	auto newSize = findPrime(size*2);
//	SCHashTable* newTable = new SCHashTable(newSize);
    list<pair<K, V>>* newTable = new list<pair<K, V>>[newSize];
	for (int i = 0; i < (int)size; i++){
		for (auto item : table[i]){
//			newTable->insert(item.first, item.second);
			int index = hash(item.first, newSize);
//std::cout << "old size: " << (int)size << " NEW MUTHAFUCKIN SIZE: " << newSize << std::endl;
			newTable[index].push_back(item);
//std::cout << "WHAT be the INDEX:::::::::::::: " << index << std::endl<< std::endl;
//std::cout << "resize item lmfao please work " << item.first << " " << item.second << std::endl<< std::endl<< std::endl<< std::endl;
		}
	}
	delete [] table;
	table = newTable;
	size = newSize;
	elems = oldElems;
	
}

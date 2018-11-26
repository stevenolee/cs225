/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
/*
bool areAnagrams(char* one, char* two){
	int counter[256] = {0};
	int i;

	for (i = 0; one[i] && two[i]; i++){
		counter[one[i]]++;
		counter[two[i]]--;
	}

	if (one[i] || two[i]){
		return false;
	}
	
	for (i = 0; i < 256; i++){
		if (counter[i]){
			return false;
		}
	}
	return true;
}
*/

bool AnagramDict::areAnagrams(string one, string two){
	std::sort(one.begin(), one.end());
	std::sort(two.begin(), two.end());
	return one == two;
}

AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream file(filename);
    string line;
    if (file.is_open()){
        while (getline(file, line)){
			vector<string> anagrams;
			anagrams.push_back(line);
// check if an anagram for this word already exists in our map
//			vector<char> word (line.begin(), line.end());
			std::map<string, vector<string>>::iterator it = dict.find(line);
// if the word is already in our map, continue
			if (it != dict.end()){
				continue;
			}
// check entire map for anagram
			bool alreadyIn = false;
			bool foundAnagram = false;
			it = dict.begin();
			for (; it != dict.end(); it++){
//				vector<char> checker (it->first.begin(), it->first.end());
//				if (areAnagrams(checker, word)){
				if (areAnagrams(it->first, line)){
					foundAnagram = true;
// check if the word is already in the map's vector of strings at that particular location
					alreadyIn = false;
					for (const string& s : it->second){
						if (s == line){
							alreadyIn = true;
							break;
						}
					}
					if (!alreadyIn){
						vector<string> temp = it->second;	
						temp.push_back(line);
						it->second = temp;
//						it->second.push_back(line);
						break;
					}
				}
			}
			if (!foundAnagram){
				dict[line] = anagrams;
			}
		}
	}

}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
	for (const string& element : words){
		vector<string> anagrams;
		anagrams.push_back(element);
			std::map<string, vector<string>>::iterator it = dict.find(element);
// if the word is already in our map, continue
			if (it != dict.end()){
				continue;
			}
// check entire map for anagram
			bool alreadyIn = false;
			bool foundAnagram = false;
			it = dict.begin();
			for (; it != dict.end(); it++){
//				vector<char> checker (it->first.begin(), it->first.end());
//				if (areAnagrams(checker, word)){
				if (areAnagrams(it->first, element)){
					foundAnagram = true;
// check if the word is already in the map's vector of strings at that particular location
					alreadyIn = false;
					for (const string& s : it->second){
						if (s == element){
							alreadyIn = true;
							break;
						}
					}
					if (!alreadyIn){
						vector<string> temp = it->second;	
						temp.push_back(element);
						it->second = temp;
//						it->second.push_back(element);
						break;
					}
				}
			}
			if (!foundAnagram){
				dict[element] = anagrams;
			}

		dict[element] = anagrams;
	}
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
	std::map<string, vector<string>>::const_iterator mapIterator = dict.find(word);
	if (mapIterator != dict.end()){
		return mapIterator->second;
	}

    return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
	vector<vector<string>> all_anagrams;
// iterate map and add anagram (not singles)
	vector<string> current;
	std::map<string, vector<string>>::const_iterator mapIterator = dict.begin();
	for (; mapIterator != dict.end(); mapIterator++){
		current = mapIterator->second;
		if (current.size() <= 1){
			continue;
		}
		else {
			all_anagrams.push_back(current);
		}
	}


    return all_anagrams;
}

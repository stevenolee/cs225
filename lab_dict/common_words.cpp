/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */


// im currently adding up the count of a given word for all the files combined.
// i should only be getting the max that it appears in any given file.
#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        std::ptr_fun<int, int>(&std::ispunct));
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
//		vector<map<string, unsigned int>> copy = file_word_maps;
        vector<string> words = file_to_vector(filenames[i]);
   	     /* Your code goes here! */
		map<string, unsigned int>::iterator it;
		while(!words.empty()){
			string currentWord = words[words.size()-1];
			it = file_word_maps[i].find(currentWord);
// if found
			if (it != file_word_maps[i].end()){
				it->second = it->second + 1;
			}
// if not found
			else {
				file_word_maps[i].insert(std::pair<string, unsigned int>(currentWord, 1));
			}
			words.pop_back();
		}
/*

// update the global with copy
		map<string, unsigned int>::iterator mapIterator = copy[i].begin();
		for (; mapIterator != copy[i].end(); mapIterator++){
			it = file_word_maps[i].find(mapIterator->first);
// if found save the larger value
			if (it != file_word_maps[i].end()){
				if (it->second < mapIterator->second){
					it->second = mapIterator->second;
				}
			}
			else {
				file_word_maps[i].insert(std::pair<string, unsigned int>(mapIterator->first, mapIterator->second));
			}
		}
*/
    }
}

void CommonWords::init_common()
{
    /* Your code goes here! */
//	common.insert(std::pair<string, unsigned int>());

//	vector<map<string, unsigned int>>::iterator it = file_word_maps.begin();
//	for (map currentMap : *it){
	size_t size = file_word_maps.size();
	for (size_t i = 0; i < size; i++){
// iterator for each of the maps in file_word_maps
		map<string, unsigned int>::iterator mapIterator = file_word_maps[i].begin();
		for (; mapIterator != file_word_maps[i].end(); mapIterator++){
// check if the word in the map has been encountered
			auto found = common.find(mapIterator->first);
// if found in common
			if (found != file_word_maps[i].end()){
				found->second = found->second + 1;
			}
// if not found in common, add it
			else {
				common.insert(std::pair<string, unsigned int>(mapIterator->first, 1));
			}

		}
	}



}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    /* Your code goes here! */
	size_t size = file_word_maps.size();
	for (size_t i = 0; i < size; i++){
// iterator for each of the maps in file_word_maps
		map<string, unsigned int>::const_iterator mapIterator = file_word_maps[i].begin();
		for (; mapIterator != file_word_maps[i].end(); mapIterator++){
// check if the word in the map has been encountered n times
			unsigned int current = mapIterator->second;
/*
cout << common.find(mapIterator->first)->second << " " << file_word_maps.size() << endl;
			if (common.find(mapIterator->first)->second != file_word_maps.size()){
				continue;
			}
*/

			if (current >= n){
/*
// iterator common 
				bool shouldAdd = false;
				map<string, unsigned int>::const_iterator it = common.begin();
				for (; it != common.end(); it++){
// if it is a common word
					if (it->first == mapIterator->first){
						shouldAdd = true;
						break;
					}
				}
				if (shouldAdd){	
*/
					out.push_back(mapIterator->first);
	//			}
			}
		}
	}





    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}

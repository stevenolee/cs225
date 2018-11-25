/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;
    /* Your code goes here! */
    ifstream file(word_list_fname);
    string line;
	vector<string> input; 
    if (file.is_open()) {
        while (getline(file, line)) {
			input.push_back(line);
		}
	}
	if (input.size() < 3){
		return ret;
	}
	string one, two, three;
	for (unsigned long i = 0; i < input.size() - 2; i++){
		one = input[i];
		for (unsigned long j = i + 1; j < input.size() - 1; j++){
			two = input[j];
			for (unsigned long k = j + 1; k < input.size(); k++){
				three = input[k];
				if (d.homophones(one, two)){
					if (d.homophones(one, three)){
						ret.push_back(std::tuple<string, string, string>(one, two, three));
					}
				}
			}
		}
	}

    return ret;
}

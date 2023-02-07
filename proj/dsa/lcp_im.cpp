#include <unordered_map>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdbool>
#include <fstream>

using namespace std;

struct trie_word
{
	bool wordState;
	unordered_map<char, trie_word*> character;

	trie_word() {
		wordState = 0;
	}
};

void insert(trie_word* root, string str)
{

	trie_word* temp = root;
 
	for (char char_val: str)
	{
		
		if (temp -> character . find(char_val) == temp -> character . end()) {
			temp -> character[char_val] = new trie_word();
		}
 
		temp = temp -> character[char_val];
	}
 
	temp -> wordState = true;
}
 

string findLCP(vector<string> dict)
{

	trie_word* head = new trie_word();
	
	for (string s: dict) {
		insert(head, s);
	}

	string lcp;
	
	trie_word* temp = head;
 
	// Loop only if wordState = true || node has > 1 child
	while (temp && !temp -> wordState && (temp -> character.size() == 1))
	{
		// Assign iterator unordered_map
		auto i = temp -> character.begin();
 

		lcp += i -> first; // Add to current charVal
 

		temp = i -> second;
	}
 
	return lcp;
}
 
int main(int argc, char **argv)
{
	vector<string> word_l;	// Keys

	string str_Val, filename;
	fstream file;

	filename = "wordList.txt";

	file.open(filename . c_str());
	while(file >> str_Val) {
		word_l.push_back(str_Val);
	}
	cout <<std::endl<<"LCP: " << findLCP(word_l)<<"\n";
	return 0;
}

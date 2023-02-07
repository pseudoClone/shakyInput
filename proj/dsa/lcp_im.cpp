#include <unordered_map>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdbool>
#include <fstream>

#define CHAR_TO_INDEX(c) (int)c - (int)'a' // Character to index conversion from trieIntro.c

using namespace std;


// LCP Struct
struct trie_word {
	bool wordState;
	unordered_map<char, trie_word*> character;

	trie_word() {
		wordState = 0;
	}
};

// AutoComplete Node
struct trie_node {
	struct trie_node* child[26]; // Alphabets
	bool wordEnd;
};

// Autocomplete alloc Node
struct trie_node* giveMeNode()
{
	struct trie_node* p_node = new trie_node;
	p_node -> wordEnd = false;

	for(size_t i = 0; i < 26; ++i) {
		p_node -> child[i] = NULL;
	}
	return p_node;
}

// Autocomplete insert
void ins_auto(struct trie_node* root, const string key_val)
{
	struct trie_node* traverse = root;
	for (size_t lvl = 0; lvl < key_val.length(); ++lvl) {

		int index = CHAR_TO_INDEX(key_val[lvl]);
		if (!traverse -> child[index])
			traverse -> child[index] = giveMeNode();
		
		traverse = traverse -> child[index];
	}
}

bool isLeaf(struct trie_node* root)
{
	for (size_t i = 0; i < 26; ++i)
		if (root -> child[i])
			return 0;
	return 1;
}


void auto_complOP(struct trie_node* root, string currPrefix)
{
	if (root -> wordEnd)
		cout << currPrefix << endl;
 
	for (size_t i = 0; i < 26; ++i)
		if (root -> child[i]) {
			char child = 'a' + i;
			auto_complOP(root->child[i], currPrefix + child);
		}
}


int compl_ptr(struct trie_node* root, const string query)
{
	struct trie_node* traverse = root;
	for (char c : query) {
		int index = CHAR_TO_INDEX(c);
 
		if (!traverse->child[index])
			return 0;
 
		traverse = traverse->child[index];
	}
	if (isLeaf(traverse)) {
		cout << query << endl;
		return -1;
	}
	auto_complOP(traverse, query);
	return 1;
}


// LCP insert Node
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
 
// LCP search Func
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
	string choice;

	cout<<"\nAutocomplete or LCP? -> ";
	cin>>choice;

	if (choice == "One" || choice == "1"
	    ||choice == "ONE" || choice == "ONE") {
		
		vector<string> word_l;	// Keys

		string str_Val, filename;
		fstream file;
	
		filename = "wordList.txt";


		file.open(filename . c_str());
		while(file >> str_Val) {
			word_l.push_back(str_Val);
		}
		cout <<std::endl<<"LCP: " << findLCP(word_l)<<"\n";
	}
	else if(choice == "TWO" || choice == "two" || choice == "2"
		||choice == "Two") {

		struct trie_node* root = giveMeNode();
		string fileWord, fileName;
		fstream file;
		fileName = "dictionary.txt";
		file.open(fileName . c_str());
		while(file >> fileWord) {
			ins_auto(root, fileWord);
		}
		int comp = compl_ptr(root, "hel");
		if (comp == -1)
			cout << "No other strings found with this prefix\n";
 
		else if (comp == 0)
			cout << "No string found with this prefix\n";
		
		return 0;
	}
	
	
	return 0;
}

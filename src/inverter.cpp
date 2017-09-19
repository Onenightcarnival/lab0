#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <cctype>
#include <sstream>

#include "inverter.h"

using namespace std;

map<string, set<int>> invertedIndex;

string intToString(set<int> &set){
	string str;
	for(std::set<int>::iterator iter = set.begin(); iter != set.end(); iter++){
		str += to_string(*iter);
		if(iter != prev(set.end())){
			str += " ";
		}
	}
	return str;
}

string build_inverted_index(string filename){
	ifstream afile;
	afile.open(filename);
	//get files that need to open
	vector<string> strs;
	string str;
	while(getline(afile, str)){
		if(str.empty()){
			continue;
		}
		strs.push_back(str);
	}
	afile.close();
	afile.clear();
	//open all the files and store file contents
    vector<string> files;
	for(int i = 0; i < strs.size(); i++){
		afile.open(strs[i]);
		if(afile.is_open()){
            string content;
            string fileContents;
            while(getline(afile, content)){
                if(content.empty()){
					continue;
				}
                fileContents += content;
                fileContents.push_back('\n');
            }
            files.push_back(fileContents);
        }
        afile.close();
        afile.clear();
	}
	//generate inverted index
	for(int i = 0; i < files.size(); i++){
		stringstream strStream(files[i]);
		char letter;
		string word;
		while(strStream.get(letter)){
			if(!isalpha(letter)){
				if(word.size() > 0){
					invertedIndex[word].insert(i);
					word.clear();
				}
				continue;
			}
			word += letter;
		}
	}
	//print map
	string result;
    for(std::map<string, set<int>>::iterator iter = invertedIndex.begin(); iter != invertedIndex.end(); iter++) {
        cout << iter->first << ": " << intToString(iter->second) << endl;
        result += iter->first + ": " + intToString(iter->second) + "\n";
    }

	return result;
}


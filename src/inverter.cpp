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

//separate those words in each file
void generateInvertedIndex(string str, int index, map<string, set<int>> &map){
	stringstream strStream(str);
	char letter;
	string word;
	while(strStream.get(letter)){
		if(!isalpha(letter)){
			if(word.size() > 0){
				map[word].insert(index);
				word.clear();
			}
			continue;
		}
		word += letter;
	}
}

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

string printMap(map<string, set<int>> &map){
	string str;
    for(std::map<string, set<int>>::iterator iter = map.begin(); iter != map.end(); iter++) {
        cout << iter->first << ": " << intToString(iter->second) << endl;
        str += iter->first + ": " + intToString(iter->second) + "\n";
    }
    return str;
}

string build_inverted_index(string filename){
	ifstream afile;
	afile.open(filename);

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

	for(int i = 0; i < files.size(); i++){
		generateInvertedIndex(files[i], i, invertedIndex);
	}

	return printMap(invertedIndex);
}


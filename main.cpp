#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

extern std::string SOURCE_CODE;
extern std::vector<string> KEYWORDS;

int main(){
  vector<string> words = {};
  int current_index = 0;
  string word = "";
  for(char c : SOURCE_CODE){
      word += c;
      if(c == ";"){
        words.push_back(word);
        words.push_back(";");
        word = "";
      }
      if(isspace(c)){
      words.push_back(word);
      word = "";
    }
  }
  for(auto word : words){
    cout << endl << "Word: " << word <<endl;
  }
}
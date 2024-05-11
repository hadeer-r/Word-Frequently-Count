#include <iostream>
#include <vector>
#include "D:\DS_project\test\Word-Frequently-Count\src\manageWords\checker.h"
#include "D:\DS_project\test\Word-Frequently-Count\src\manageWords\checker.cpp"
#include "D:\DS_project\test\Word-Frequently-Count\src\manageWords\trie.h"
#include "D:\DS_project\test\Word-Frequently-Count\src\manageWords\trie.cpp"
using namespace std;


int main(){

    Checker ch;
    
    vector<string> words_auto=ch.autoComplete("Virtua");
    vector<string> correct_word=ch.autoCorrect("algorihtm");// should return algorithm

    for(auto w:words_auto){
        cout<<w<<" ";
    }
    cout<<"\n\n";
    for(auto w:correct_word){
        cout<<w<<" ";
    }

    return 0;
}
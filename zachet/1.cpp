#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Word{
    string nW;
    string oW;
};

bool operator<(Word w1, Word w2) {

  return w1.nW < w2.nW;

}


string sortWord(string word){
    vector<char> wordChar;
    for (int i = 0; i < word.length(); i++){
        wordChar.push_back(word[i]);
    }

    sort(wordChar.begin(), wordChar.end());

    string newWord = "";
    for (int i = 0; i < wordChar.size(); i++){
        newWord += char(wordChar[i]);
    }
    return newWord;
}

bool word1More2(string word1, string word2){
    for (int i = 0; i < min(word1.length(), word2.length()); i++){
        if (word1[i] == word2[i]){
            continue;
        }
        if (word1[i] > word2[i]){
            return true;
        }
        else{
            return false;
        }
    }

    if (word1.length() > word2.length()){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    vector<Word> dict;
    int n;
    cin >>n;
    dict.resize(n);

    for (int i = 0; i < n; i++){
        string word;
        cin >>word;
        dict[i].oW = word;
        dict[i].nW = sortWord(word);
    }

    for (int i = 0; i < n; i++){

        sort(dict.begin(), dict.end());
    }

    string nowWord = "";
    int beginOutput = 0;
    int counter = 1;

    for (int i = 0; i < dict.size(); i++){
        if (dict[i].nW != nowWord){
            //cout <<"NEWWORD!" <<endl;
            if (counter > 1){
                for (int j = beginOutput; j < beginOutput + counter; j++){
                    cout <<dict[j].oW <<" ";
                }
                cout <<endl;
            }
            beginOutput = i;
            nowWord = dict[i].nW;
            counter = 1;
        }
        else{
            counter++;
        }
    }

    if (counter > 1){
        for (int j = beginOutput; j < beginOutput + counter; j++){
            cout <<dict[j].oW <<" ";
        }
        cout <<endl;
    }

    /*for (int i = 0; i < dictNew.size(); i++){
        cout <<dictNew[i] <<endl;
    }*/

}

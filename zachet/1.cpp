#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sortWord(string word){
    vector<char> wordChar;
    for (int i = 0; i < word.length(); i++){
        wordChar.push_back(word[i]);
    }

    for (int i = 0; i < wordChar.size(); i++){
        for (int j = 0; j < i; j++){
            if (wordChar[i] < wordChar[j]){
                swap(wordChar[i], wordChar[j]);
            }
        }
    }
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
    vector<string> dictOrig, dictNew;
    int n;
    cin >>n;

    for (int i = 0; i < n; i++){
        string word;
        cin >>word;
        dictOrig.push_back(word);
        dictNew.push_back(sortWord(word));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (word1More2(dictNew[i], dictNew[j])){
                //cout <<dictOrig[i] <<" " <<dictOrig[j] <<endl;
                //cout <<dictOrig[j] <<" " <<dictOrig[i] <<endl;

                swap(dictNew[i], dictNew[j]);
                swap(dictOrig[i], dictOrig[j]);
            }
        }
    }

    string nowWord = "";
    int beginOutput = 0;
    int counter = 1;

    for (int i = 0; i < dictNew.size(); i++){
        if (dictNew[i] != nowWord){
            //cout <<"NEWWORD!" <<endl;
            if (counter > 1){
                for (int j = beginOutput; j < beginOutput + counter; j++){
                    cout <<dictOrig[j] <<" ";
                }
                cout <<endl;
            }
            beginOutput = i;
            nowWord = dictNew[i];
            counter = 1;
        }
        else{
            counter++;
        }
    }

    if (counter > 1){
        for (int j = beginOutput; j < beginOutput + counter; j++){
            cout <<dictOrig[j] <<" ";
        }
        cout <<endl;
    }

    /*for (int i = 0; i < dictNew.size(); i++){
        cout <<dictNew[i] <<endl;
    }*/

}

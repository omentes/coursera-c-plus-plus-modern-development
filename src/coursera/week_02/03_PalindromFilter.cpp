//
// Created by omentes on 11.10.20.
//

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result = {};
    for (auto word : words) {
        if (IsPalindrom(word) && word.length() >= minLength) {
            result.push_back(word);
        }
    }

    return result;
}
//
// Created by omentes on 11.10.20.
//

bool IsPalindrom(string str) {
    return str == string(str.rbegin(),str.rend());
}
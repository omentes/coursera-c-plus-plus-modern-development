
vector<int> Reversed(const vector<int>& v) {
    int len = v.size() - 1;
    vector<int> v2 = {};
    if (len > -1) {
        while ( len > -1)
        {
            v2.push_back(v[len--]);
        }
    }
    return v2;
}


void Reverse(vector<int>& v) {
    int tmp;
    int len = v.size() - 1;
    if (len > 0) {
        for (int i = 0; i <= len/2; i++)
        {
            tmp = v[i];
            v[i] = v[len - i];
            v[len - i] = tmp;
        }
    }
}

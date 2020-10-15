
set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;
    for (const auto& [it, item] : m) {
        result.insert(item);
    }
    return result;
}

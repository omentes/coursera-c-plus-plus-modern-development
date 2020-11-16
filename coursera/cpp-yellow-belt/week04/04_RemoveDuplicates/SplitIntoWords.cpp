
#include <set>
#include <vector>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
  set<T> uniq(elements.begin(), elements.end());
  elements.clear();
  for (const auto item : uniq) {
    elements.push_back(item);
  }
}


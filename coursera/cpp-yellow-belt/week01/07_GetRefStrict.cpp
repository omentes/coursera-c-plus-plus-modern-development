#include <iostream>
#include <exception>
#include <stdexcept>
#include <map>

template <typename Value, typename Key>
Value& GetRefStrict(map<Key, Value>& items, const Key key) {
  if (items.count(key)) {
    return items[key];
  }
  throw runtime_error("");
}
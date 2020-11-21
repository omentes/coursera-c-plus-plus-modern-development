template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  int len = range_end - range_begin;
  if (len < 3) {
    return;
  }
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  int half = len / 3;
  MergeSort(elements.begin(), elements.begin() + half);
  MergeSort(elements.begin() + half, elements.begin() + half * 2);
  MergeSort(elements.begin() + half * 2, elements.begin() + len);
  vector<typename RandomIt::value_type> tmp;
  merge(
      elements.begin(), elements.begin() + half,
      elements.begin() + half, elements.begin() + half * 2,
      back_inserter(tmp)
  );
  merge(
      tmp.begin(), tmp.end(),
      elements.begin() + half * 2, elements.begin() + len,
      range_begin
  );
}

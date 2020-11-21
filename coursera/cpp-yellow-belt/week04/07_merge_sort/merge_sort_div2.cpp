template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  int len = range_end - range_begin;
  if (len < 2) {
    return;
  }
  vector<typename RandomIt::value_type> elements(range_begin, range_end);

  MergeSort(elements.begin(), elements.begin() + len / 2);
  MergeSort(elements.begin() + len / 2, elements.end());
  merge(
      elements.begin(),
      elements.begin() + len / 2,
      elements.begin() + len / 2,
      elements.end(),
      range_begin
  );
}
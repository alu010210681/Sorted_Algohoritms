#ifndef SelectionSort_H
#define SelectionSort_H

template<typename Key>
void selectionSort(std::vector<Key>& seq, unsigned size) {
  for (unsigned int i = 0; i < size - 1; i++) {
    int min_index = i;
    for (unsigned int j = i + 1; j < size; j++) {
      if (seq[j] < seq[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      std::swap(seq[i], seq[min_index]);
    }
  }
}
#endif
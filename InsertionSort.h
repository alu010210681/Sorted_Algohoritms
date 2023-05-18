#ifndef InsertionSort_H
#define InsertionSort_H

template<typename Key>
void insertionSort (std::vector<Key>& seq, unsigned size) {
  std::cout << "InsertionSort\n";
  // Sequence sorted
  std::cout << "Iteration 0: " << seq;
  //Sort Algohorithm
  for (unsigned int i = 1; i < size; i++) {
    Key key = seq[i];
    int j = i - 1;
    while (j >= 0 && seq[j] > key) {
      seq[j+1] = seq[j];
      j--;
    }
    seq[j+1] = key;
    // Sequence sorted
    std::cout << "Iteration " << i << ": " << seq;
  }
}

#endif
#ifndef ShakeSort_H
#define ShakeSort_H
template<typename Key>
void shakeSort(std::vector<Key>& seq, unsigned size) {
  int start = 0;
  int end = size - 1;
  int cambio = size;
  while (start < end) {
    // Sacudida hacia la izquierda
    for (int j = end; j > start; j--) {
      if (seq[j] < seq[j-1]) {
        std::swap(seq[j], seq[j-1]);
        cambio = j;
      }
    }
    start = cambio;
    // Sacudida hacia la derecha
    for (int j = start; j < end; j++) {
      if (seq[j] > seq[j+1]) {
        std::swap(seq[j], seq[j+1]);
        cambio = j;
      }
    }
    end = cambio;
  }
}

#endif

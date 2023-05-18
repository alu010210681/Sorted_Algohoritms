#ifndef RadixSort_H
#define RadixSort_H

template<typename Key>
void radixSortMethod(std::vector<Key>& seq, int size, int exp) {
  std::vector<Key> result(size);
  int i, digits_0_9[10] = {0};
  //Almacena la cuenta de cada digito 0 -> 0, 1 -> 4 , 2 -> 2 , 3 -> 1 , 4 -> 0
  for (i = 0; i < size; i++) {
    digits_0_9[(seq[i] / exp) % 10]++;
  }
  // Almacena la suma acumulada de los digitos 0 -> 0, 1 -> 4 , 2 -> 6 , 3 -> 7 , 4 -> 7
  for (i = 1; i < 10; i++) {
    digits_0_9[i] += digits_0_9[i - 1];
  }
  // Construye la secuencia resultante
  for (i = size - 1; i >= 0; i--) {
    // (seq[i] / exp) % 10 obtiene el digito de la posicion que se está 10 100 ...
    // digits_0_9[(seq[i] / exp) % 10] - 1 get the position of the digit in the result sequence, can produce colission and we need stored in the previus postion 
    result[digits_0_9[(seq[i] / exp) % 10] - 1] = seq[i];
    // Decrease the count of the digit in the position
    digits_0_9[(seq[i] / exp) % 10]--;
  }
  // Copy the result value to the sequence
  for (i = 0; i < size; i++) {
    seq[i] = result[i];
  }
}
// Radix sort algorithms using the class SortMethod put some code explain it
template<typename Key>
void radixSort(std::vector<Key>& seq, unsigned size) {
  std::cout << "RadixSort\n";
  // Get the max value of the sequence
  int max_element = seq[0];
  for (unsigned int i = 1; i < seq.size(); i++) {
    if (seq[i] > max_element) {
      max_element = seq[i];
    }
  }
  // Loop to sort the sequence by the size of the number using digit 10 100 1000 ...
  for (int exp = 1; max_element / exp > 0; exp *= 10) {
    radixSortMethod(seq, seq.size(), exp);
    // Sequence sorted
    if (manual_values) std::cout << seq;
  }
  std::cout << "Sorted vector: " << seq << std::endl;
}


#endif

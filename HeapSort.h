template<typename Key>
void down(std::vector<Key>& seq, int size, int i) {
  int h1, h2, h;
  while (2*i + 1 < size) {
    h1 = 2*i + 1; 
    h2 = h1 + 1;
    // Seleccionamos el hijo mayor
    if (h2 < size && seq[h1] < seq[h2]) h = h2;
    else h = h1;
    // Si el padre es mayor que el hijo, la propiedad es satisfecha
    if (seq[h] <= seq[i]) break;
    // Si no se cumple, se cambia el hijo por el padre, para ordenar el heap
    else {
      std::swap(seq[i], seq[h]);
      i = h;
    }
  }
}

template<typename Key>
void heapSort(std::vector<Key>& seq, unsigned size) {
  std::cout << "Phase I: Insertions\n";
  for (int i = size / 2 - 1; i >= 0; i--) {
    down(seq, size, i);
  }
  std::cout << "Phase II: Extractions\n";
  for (int i = size - 1; i >= 0; i--) {
    // Mover la raiz al final
    std::swap(seq[0], seq[i]);
    // Comprobar si el heap está ordenado (parent > children)
    down(seq, i, 0);
  }
}
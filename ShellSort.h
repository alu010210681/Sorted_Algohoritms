#ifndef ShellSort_H
#define ShellSort_H

template<typename Key>
void shellSort(std::vector<Key>& seq, unsigned size) {
  int offset = seq.size() / 2;
  while (offset > 0) {
  	// Realiza todas las compraciones con las subsecuencias dado un desplazamiento
  	for (long unsigned int i = offset; i < seq.size(); i++) {
  	  int j = i;
  	  int temp = seq[i];
  	  // Se utiliza el algoritmo de inserción para ir ordenando la subsecuencia 
  	  // Utilizando el desplazamiento 
  	  while (j >= offset && seq[j - offset] > temp) {
  	    seq[j] = seq[j - offset];
  	    j = j - offset;
  	  }
  	  seq[j] = temp;
  	}
  	if (offset == 2) {
  	  offset = 1;
  	} else {
  	  offset = offset / 2;
  	}
  }
}

#endif
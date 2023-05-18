#ifndef BubbleSort_H
#define BubbleSort_H
    
template<typename Key>
void bubbleSort (std::vector<Key>& seq, unsigned size) {
  for (int i = 1; i < size; i++){
   	for (int j = size-1; j >= i; j--) 
      if (seq[j] < seq[j-1]){
        std::swap(seq[j-1],seq[j]);
      }
	} 
}

#endif
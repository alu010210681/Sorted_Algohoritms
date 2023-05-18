#ifndef UTILITY_H
#define UTILITY_H

template<typename Key>
std::ostream& operator<<(std::ostream& os, const std::vector<Key>& v) {
  os << "[ ";
  for (long unsigned int i = 0; i < v.size(); ++i) {
    os << v[i] << " ";
  }
  return os << "]" << std::endl;
} 

#endif
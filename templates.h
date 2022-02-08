#include <bits/stdc++.h>

#ifndef SIZE_TYPE
#define SIZE_TYPE int
#endif

//--------------- Printing a std::vector | tags - printing, vector, print----------------//

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec){
	os << "[";
	for (SIZE_TYPE i = 0; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << vec[i] << ",";
	return os << vec.back() << "]";
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vec){
	os << "[ " << vec[0] << ",\n";
	for (SIZE_TYPE i = 1; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << "  " << vec[i] << ",\n";
	return os << "  " << vec.back() << " ]";
}

//----------------------------------------------------------------------------------------//

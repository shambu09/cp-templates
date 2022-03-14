#include <bits/stdc++.h>
#ifndef SIZE_TYPE
#define SIZE_TYPE int
#endif

#ifndef STORAGE_TYPE
#define STORAGE_TYPE int
#endif
//--------------- Printing a std::vector and std::array | tags - printing, vector, print----------------//

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	if(vec.size() == 0) return os << "[]";
	os << "[";
	for(SIZE_TYPE i = 0; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << vec[i] << ", ";
	return os << vec.back() << "]";
}

template <class T>
std::ostream& operator<<(std::ostream& os,
						 const std::vector<std::vector<T>>& vec) {
	if(vec.size() == 0) return os << "[]";
	os << "[ " << vec[0] << ",\n";
	for(SIZE_TYPE i = 1; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << "  " << vec[i] << ",\n";
	return os << "  " << vec.back() << " ]";
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& vec) {
	if(vec.size() == 0) return os << "[]";
	os << "[";
	for(auto i = vec.begin(); next(i) != vec.end(); i++)
		os << *i << ", ";
	return os << vec.back() << "]";
}

template <class T>
std::ostream& operator<<(std::ostream& os,
						 const std::list<std::list<T>>& vec) {
	if(vec.size() == 0) return os << "[]";
	os << "[ " << vec[0] << ",\n";
	for(SIZE_TYPE i = 1; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << "  " << vec[i] << ",\n";
	return os << "  " << vec.back() << " ]";
}

template <class T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& vec) {
	os << "[";
	for(SIZE_TYPE i = 0; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << vec[i] << ", ";
	return os << vec.back() << "]";
}

template <class T, std::size_t N, std::size_t M>
std::ostream& operator<<(std::ostream& os,
						 const std::array<std::array<T, N>, M>& vec) {
	os << "[ " << vec[0] << ",\n";
	for(SIZE_TYPE i = 1; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << "  " << vec[i] << ",\n";
	return os << "  " << vec.back() << " ]";
}

template <class T, class N>
std::ostream& operator<<(std::ostream& os, const std::pair<T, N> p) {
	return os << "<" << p.first << ", " << p.second << ">";
}

template <class T, class N>
std::ostream& operator<<(std::ostream& os, const std::map<T, N> m) {
	if(m.size() == 0) return os << "{}";
	auto i = m.begin();
	os << "{\n  " << *i << ", \n";
	i++;
	for(; next(i) != m.end(); i++)
		os << "  " << *i << ",\n";
	return os << "  " << *m.rbegin() << "\n}";
}

//----------------------------------------------------------------------------------------//

//----------------------shortcut for vector.begin() and vector.end()----------------------//
#ifndef all
#define all(s) s.begin(), s.end()
#endif

#ifndef rall
#define rall(s) s.rbegin(), s.rend()
#endif
//----------------------------------------------------------------------------------------//

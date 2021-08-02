#include<iostream>
#include<vector>

using namespace std;

//--------------- Printing a std::vector | tags - printing, vector, print----------------//

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec){
    os << "{ ";
    for(auto i: vec){
        os << i << " ";
    }
    return os << "}";
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& vec){
    os << "{ " << endl;
    for(auto i: vec){
        os << i << endl;
    }
    return os << "}";
}

//----------------------------------------------------------------------------------------//
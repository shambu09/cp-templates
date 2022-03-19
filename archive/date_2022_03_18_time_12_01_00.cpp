#include <vector>
#include <iostream>
#include <sstream>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec){
    for(int i: vec){
        os << i << " ";
    }

    return os;
}

int main(){
    std::vector<int> vec;

    int i;
    while(std::cin >> i){
        vec.push_back(i);
        if(std::cin.peek() == ',') std::cin.ignore();
    }

    std::cout << vec << std::endl;
}
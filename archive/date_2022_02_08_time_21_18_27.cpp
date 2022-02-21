#include<iostream>
#include<stdbool.h>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

void Result(int Maths, int Bio, int Eng, int Hindi, int Social){
    float sum = Maths + Bio + Eng + Hindi + Social;
    sum /= 5.0;
    int last = ((int) (sum * 10));
    int first = last / 10;
    last = last % 10;
    cout << first << "." << last << endl;

    if(min({Maths, Bio, Eng, Hindi, Social}) < 30)
        cout << "Fail";

    else if (first > 80 and Maths >= 90 and Bio >= 70){
        cout << "JEE";
        if(Bio >= 90 and first >= 60){
            cout << ",Medical";
        }
    }
    else if(Bio >= 90 and first >= 60){
        cout << ",Medical";
    }


}

int main(){
    int Maths, Bio, Eng, Hindi, Social;
    cin >> Maths >> Bio >> Eng >> Hindi >> Social;
    Result(Maths, Bio, Eng, Hindi, Social);
    return 0;
}
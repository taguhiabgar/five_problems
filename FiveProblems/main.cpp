//
//  main.cpp
//  FiveProblems
//
//  Created by Taguhi Abgar on 9/1/17.
//  Copyright © 2017 Taguhi Abgar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime> 

using namespace std;

// problem 1
void problem1();
int sumWithForLoop(vector<int>);
int sumWithWhileLoop(vector<int>);
int sumWithRecursion(vector<int>);

// problem 2
void problem2();
vector<char> combine(vector<char>, vector<char>);

int main(int argc, const char * argv[]) {
//    problem1();
    problem2();
    return 0;
}

// problem 2

void problem2() {
    // Write a function that combines two lists by alternatingly taking elements. For example: given the two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c, 3].
    
    vector<char> first = {'a', 'b', 'c'};
    vector<char> second = {'1', '2', '3'};
    vector<char> combined = combine(first, second);
    for (int i = 0; i < combined.size(); i++) {
        cout << combined[i] << ' ';
    }
    cout << endl;
}

vector<char> combine(vector<char> first, vector<char> second) {
    vector<char> result;
    int flag1 = 0, flag2 = 0;
    while(result.size() < first.size() + second.size()) {
        if (flag1 < first.size()) {
            result.push_back(first[flag1]);
            flag1++;
        }
        if (flag2 < second.size()) {
            result.push_back(second[flag2]);
            flag2++;
        }
    }
    return result;
}

// problem 1

void problem1() {
    // Write three functions that compute the sum of the numbers in a given list using a for-loop, a while-loop, and recursion.
    int count = 10;
    vector<int> numbers = vector<int>(count);
    for(int i = 0; i < count; i++) {
        numbers[i] = rand() % 1000000;
        cout << numbers[i] << endl;
    }
    cout << "for loop: sum = " << sumWithForLoop(numbers) << endl;
    cout << "while loop: sum = " << sumWithWhileLoop(numbers) << endl;
    cout << "recursion: sum = " << sumWithRecursion(numbers) << endl;
}

int sumWithForLoop(vector<int> vec) {
    int result = 0;
    unsigned long size = vec.size();
    for(int i = 0; i < size; i++) {
        result += vec[i];
    }
    return result;
}

int sumWithWhileLoop(vector<int> vec){
    int result = 0, index = 0;
    unsigned long size = vec.size();
    while(index < size) {
        result += vec[index];
        index++;
    }
    return result;
}

int sumWithRecursion(vector<int> vec) {
    if (vec.size() == 1) {
        return vec[0];
    }
    return vec[0] + sumWithRecursion(vector<int>(vec.begin() + 1, vec.end()));
}



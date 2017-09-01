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
#include <string>
#include <algorithm>

using namespace std;

// problem 1
void problem1();
int sumWithForLoop(vector<int>);
int sumWithWhileLoop(vector<int>);
int sumWithRecursion(vector<int>);

// problem 2
void problem2();
vector<char> combine(vector<char>, vector<char>);

// problem 3
void problem3();
vector<string> fibonacciNumbers(int);
string add(string, string);

// problem 4
void problem4();
bool notUsualCompareForMinimum(int first, int second);

int main(int argc, const char * argv[]) {
//    problem1();
//    problem2();
//    problem3();
    problem4();
    return 0;
}

// problem 4

void problem4() {
    // Write a function that given a list of non negative integers, arranges them such that they form the largest possible number. For example, given [50, 2, 1, 9], the largest formed number is 95021.
    vector<int> numbers = {50, 2, 1, 9};
    sort(numbers.begin(), numbers.end(), notUsualCompareForMinimum);
    reverse(numbers.begin(), numbers.end());
    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
    }
    cout << endl;
}

bool notUsualCompareForMinimum(int first, int second) {
    string f = to_string(first);
    string s = to_string(second);
    return f < s;
}

// problem 3

void problem3() {
    // Write a function that computes the list of the first 100 Fibonacci numbers. By definition, the first two numbers in the Fibonacci sequence are 0 and 1, and each subsequent number is the sum of the previous two. As an example, here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
    
    vector<string> numbers = fibonacciNumbers(100);
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

vector<string> fibonacciNumbers(int count) {
    vector<string> numbers = {"0", "1"};
    
    for (unsigned long i = numbers.size(); i <= count; i++) {
        numbers.push_back(add(numbers[i - 1], numbers[i - 2]));
    }
    return numbers;
}

string add(string num1, string num2) {
    string result = "";
    if (num1.size() != num2.size()) {
        if (num1.size() < num2.size()) {
            for(unsigned long i = num1.size(); i < num2.size(); i++) {
                num1 = "0" + num1;
            }
        } else {
            for(unsigned long i = num2.size(); i < num1.size(); i++) {
                num2 = "0" + num2;
            }
        }
    } else {
        num1 = "0" + num1;
        num2 = "0" + num2;
    }
    
    int toAdd = 0;
    for(long i = num1.size() - 1; i >= 0; i--) {
        char c = '0' + toAdd + (num1[i] - '0') + (num2[i] - '0');
        if (c > '9') {
            c -= 10;
            toAdd = 1;
        } else {
            toAdd = 0;
        }
        result = c + result;
    }
    
    // clean zeroes
    string cleanResult = "";
    bool start = false;
    for(int i = 0; i < result.size(); i++) {
        if (!(!start && result[i] == '0')) {
            start = true;
            cleanResult += result[i];
        }
    }
    
    return cleanResult;
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



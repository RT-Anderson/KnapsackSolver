// Created by RTAnderson on 4/4/17.

#ifndef KNAPSACK_KNAPSACK_H
#define KNAPSACK_KNAPSACK_H


#include <iostream>
#include <algorithm>
#include <fstream>
#include <stack>
#include "SolutionState.h"

class Knapsack{

public:

    Knapsack(std::string inputFile);
    ~Knapsack();
    void solve();


private:
    int maxWeight;
    int itemCnt;
    int bestScore{0};
    bool isOptimal{1};

    std::vector<std::pair<int,bool>> bestSelection{};
    std::vector<bool> selectionVector;
    std::vector<KnapsackItem*> itemVector;

    void printItems();
};



#endif //KNAPSACK_KNAPSACK_H

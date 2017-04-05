// Created by RTAnderson on 4/4/17.

#ifndef KNAPSACK_SOLUTIONSTATE_H
#define KNAPSACK_SOLUTIONSTATE_H


#include <vector>
#include <cmath>
#include "KnapsackItem.h"

class SolutionState
{

public:
    bool assignItem(int& bestScore, std::vector<std::pair<int,bool>>& bestSolution,bool isSelected);

    SolutionState(const std::vector<KnapsackItem*>& items, int weight);
    SolutionState(const SolutionState* orig, const std::vector<KnapsackItem*> &itemVector);

    double getOptimalVal(){return optValue;}
    std::vector<std::pair<int,bool>> getSolution(){return solution;};

private:
    int maxWeight;
    int itemCnt;
    int currWeight{0};
    int currValue{0};
    std::vector<std::pair<int,bool>> solution{};
    double optValue;
    const std::vector<KnapsackItem *> &itemVector;

    double setOptimalVal();
};


#endif //KNAPSACK_SOLUTIONSTATE_H

// Created by RTAnderson on 4/4/17.

#include "SolutionState.h"

SolutionState::SolutionState(const std::vector<KnapsackItem*>& items, int weight):maxWeight{weight},itemVector(items),itemCnt(items.size()){};

SolutionState::SolutionState(const SolutionState* orig, const std::vector<KnapsackItem*> &itemVector) : itemVector(itemVector) {
    maxWeight=orig->maxWeight;
    itemCnt=orig->itemCnt;
    currValue=orig->currValue;
    currWeight=orig->currWeight;
    solution=orig->solution;
};

bool SolutionState::assignItem(int& bestScore, std::vector<std::pair<int,bool>>& bestSolution,bool isSelected)
{
    int itemIndex=solution.size();
    if (isSelected)
    {
        currWeight+=itemVector.at(itemIndex)->getWeight();
        if (currWeight>maxWeight) return false; //Knapsack Weight exceeded; Mark this solution for deletion;

        currValue+=itemVector.at(itemIndex)->getValue();
        solution.push_back(std::make_pair(itemVector.at(itemIndex)->getID(),true));
    }
    else
    {
        solution.push_back(std::make_pair(itemVector.at(itemIndex)->getID(),false));
    }

    //if all items have been assessed; update global solution if this is better & mark this solution for deletion
    if(solution.size()==itemVector.size())
    {
        if (currValue > bestScore) {
            bestScore = currValue;
            bestSolution = std::move(solution);
        }
        return false;
    }

    optValue=setOptimalVal();

    //if there already exists a solution better than the optimal; mark this solution for deletion;
    return (optValue > bestScore) ? true: false;
}


double SolutionState::setOptimalVal()
{
    double tmpVal= static_cast<double>(currValue);

    auto index= solution.size();
    auto remainingWeight=maxWeight - currWeight;
    for (auto idx=index;idx<itemCnt;++idx)
    {
        const auto item=itemVector.at(idx);
        if (item->getWeight()<remainingWeight)
        {
            tmpVal+=item->getValue();
            remainingWeight-=item->getWeight();
        }
        else
        {
            double partialValue = item->getValue() * remainingWeight / static_cast<double>(item->getWeight());
            tmpVal += partialValue;
            break;
        }
    }
    return std::ceil(tmpVal);
}


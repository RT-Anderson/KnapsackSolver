// Created by RTAnderson on 4/4/17.

#include "Knapsack.h"

void Knapsack::printItems(){
    std::cout << bestScore <<" "<< (int)isOptimal<<std::endl;
    std::sort(bestSelection.begin(),bestSelection.end());

    for (const auto& item:bestSelection) std::cout<< (int)item.second<< " ";
    std::cout<<std::endl;
}


Knapsack::Knapsack(std::string inputFile)
{
    try
    {
        std::ifstream ss(inputFile);
        ss >> itemCnt >> maxWeight;

        if(itemCnt==0) throw std::runtime_error("Input file size states no items exist\n");
        itemVector.reserve(static_cast<ulong>(itemCnt));

        int id{0};
        int itemValue,itemWeight;
        while(ss>>itemValue>>itemWeight) itemVector.push_back(new KnapsackItem(itemValue,itemWeight,id++));

        std::sort(itemVector.begin(),itemVector.end(),[](const KnapsackItem* lhs,const KnapsackItem* rhs){return lhs->getDensity() > rhs->getDensity();});

        selectionVector.reserve(static_cast<ulong>(itemCnt));
        for(int i=0;i<itemCnt;++i) selectionVector.push_back(false);
    }

    catch (std::ifstream::failure){std::cerr <<"file: "<<inputFile<<" could not be opened\n"; }
    catch(const std::runtime_error& e){std::cerr<<e.what();}
    catch(...){std::cerr<<"unspecified error occurred\n";}

};


Knapsack::~Knapsack(){
    for(auto* item:itemVector) delete(item);
    itemVector.clear();
}


void Knapsack::solve(){

    //generateGreedySolution();
    std::stack<SolutionState*> sols{};

    auto* rootA = new SolutionState(itemVector,maxWeight);
    auto* rootB = new SolutionState(itemVector,maxWeight);

    //Seed logic
    //if assignItem returns false; solution is invalid, suboptimal, or marked for deletion;
    rootA->assignItem(bestScore,bestSelection,true);
    rootB->assignItem(bestScore,bestSelection,false);

    sols.push(rootB);
    sols.push(rootA);

    while (!sols.empty())
    {
        auto* tmpNode = sols.top();
        auto* nodeA = new SolutionState (tmpNode,itemVector);
        auto* nodeB = new SolutionState(tmpNode,itemVector);
        sols.pop();
        delete tmpNode;

        //if assignItem returns false; solution is invalid, suboptimal, or marked for deletion;
        (nodeB->assignItem(bestScore,bestSelection,false)) ? sols.push(nodeB) : delete(nodeB);
        (nodeA->assignItem(bestScore,bestSelection,true)) ? sols.push(nodeA) : delete(nodeA);

    }

    //Print out solution
    printItems();
}
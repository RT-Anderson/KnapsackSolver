// Created by RTAnderson on 4/4/17.

#ifndef KNAPSACK_KNAPSACKITEM_H
#define KNAPSACK_KNAPSACKITEM_H

class KnapsackItem
{

public:
    int getID() const {return id;}
    int getValue() const {return val;}
    int getWeight() const {return weight;}
    double getDensity() const {return density;}

    KnapsackItem(int v,int w,int inputID):val{v},
                                          weight{w},
                                          id{inputID},
                                          density{static_cast<double>(v)/ static_cast<double>(w)}{};

private:
    const int val,weight,id;
    const double density;

};




#endif //KNAPSACK_KNAPSACKITEM_H

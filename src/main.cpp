// Created by RTAnderson on 4/4/17.

#include "Knapsack.h"


int main() {


    auto test1 = Knapsack("../data/ks_50_0");
    test1.solve();

    auto test2 = Knapsack("../data/ks_4_0");
    test2.solve();

    auto test3 = Knapsack("../data/ks_1000_0");
    test3.solve();

    auto test4 = Knapsack("../data/ks_10000_0");
    test4.solve();

    return 0;
}
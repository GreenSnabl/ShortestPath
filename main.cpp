/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snbl
 *
 * Created on June 22, 2018, 9:58 AM
 */

#include <cstdlib>
#include "Dijkstra.h"

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Graph<string, int> graph;
    Edgelist<string> staedte;
    Nodelist<string, int> min_distance;
    
    graph["Frankfurt"].insert(std::pair<string, int> ("Affe", 1000));
    graph["Affe"].insert(std::pair<string, int> ("Frankfurt", 1000));
    graph["Frankfurt"].insert(std::pair<string, int> ("Bernd", 23));
    graph["Bernd"].insert(std::pair<string, int> ("Frankfurt", 23));
    graph["Bernd"].insert(std::pair<string, int> ("Affe", 500));
    graph["Affe"].insert(std::pair<string, int> ("Bernd", 500));
    
    
    string a = "Frankfurt";
    string b = "Affe";
    
    Dijkstra(graph, min_distance, staedte, a, b);
    
    for (auto it : min_distance)
    {
        std::cout << it.first << "\t" << it.second << std::endl;    
    }
    
    
    return 0;
}


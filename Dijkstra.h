/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dijkstra.h
 * Author: snbl
 *
 * Created on June 22, 2018, 9:59 AM
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <map>
#include <limits>
#include <set>
#include <ios>

template <typename Node, typename Weight>
using Nodelist = std::map<Node, Weight>;

template <typename Node>
using Edgelist = std::map<Node, Node>;

template <typename Node, typename Weight>
using Graph = std::map<Node, Nodelist<Node, Weight> >;

template <typename Weight, typename Node>
using Queue = std::set<std::pair<Weight, Node> >;


template <typename Node, typename Weight>
void Dijkstra (Graph<Node, Weight>& graph, Nodelist<Node, Weight>& min_distance, Edgelist<Node>& previous, Node source, Node destination)
{
    const Weight INF = std::numeric_limits<Weight>::max();    
    min_distance.clear();
    previous.clear();
    
    for (auto it : graph) {
        min_distance[it.first] = INF;
    }
    min_distance[source] = 0;
    Queue<Weight, Node> queue;
    queue.insert(std::make_pair(min_distance[source], source));
    
    while (!queue.empty()) {
        Node u = queue.begin()->second;
        Weight dist = queue.begin()->first;
        queue.erase(queue.begin());       
        for (auto it : graph[u])
        {
            Node v = it.first;
            Weight dist_through_u = dist + it.second;
            
            if (dist_through_u < min_distance[v])
            {
                queue.erase(std::make_pair(min_distance[v], v));
                previous[v] = u;
                min_distance[v] = dist_through_u;
                queue.insert(std::make_pair(min_distance[v], v));
            }
        }    
    }
}





#endif /* DIJKSTRA_H */


#ifndef IDASTAR_CPP
#define IDASTAR_CPP
#include "IDAStar.hpp"

std::list<moves> IDAStar::solve(const Puzzle& initial_state, 
                                const Puzzle& goal_state,
                                Heuristics* heuristic)
{

    this->heuristics = heuristic;
    this->initial_state = initial_state;
    this->goal_state = goal_state;

    std::list<moves> path = driverProcedure();
    return path;
}

IDAStar::IDAStar(){}
IDAStar::~IDAStar(){}


std::list<moves> IDAStar::driverProcedure(){
    
}

std::list<moves> IDAStar::idaStar(){

}

std::set<SearchNode> IDAStar::generateSuccessors(const SearchNode& node){

    std::set<SearchNode> successors;
    std::set<moves> available_moves = node.state.availableMoves();

    double g = node.g + 1;  //unit cost abreviation for w(parent, node)
    for (auto i: available_moves){        
        Puzzle temp = node.state;
        temp.makeMove(i);
        double h = heuristics->evaluate(temp); 

        successors.insert(SearchNode(const_cast<SearchNode*>(&node), i, temp, h + g, g, h)).second;
    }
    
    return successors;
}

std::list<moves> IDAStar::makeMovesList(const SearchNode& goal_state){

    std::list<moves> path;
    
    SearchNode aux_node = goal_state;
    while(aux_node.parent != nullptr){
        path.push_back(aux_node.generated_by);
        aux_node = *aux_node.parent; 
    }

    path.reverse();
    return path;
}

#endif
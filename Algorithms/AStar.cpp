#ifndef A_STAR_CPP
#define A_STAR_CPP
#include "AStar.hpp"

std::list<moves> AStar::solve(const Puzzle& initial_state, 
                              const Puzzle& goal_state,
                              Heuristics* heuristic = nullptr)
{

    heuristics = heuristic;
    this->initial_state = initial_state;
    this->goal_state = goal_state;

    //making sure open and closed are empty
    while (!open.empty())
        open.pop();
    closed.clear();

    std::list<moves> path = driverProcedure();

    return path;
}

std::list<moves> AStar::driverProcedure(){

    //starting the open set with the initial state
    //closed set starts empty (guaranteed by solve())
    double initial_state_heuristics = heuristics->evaluate(initial_state); //initialize estimate
    open.push(SearchNode(nullptr, initial_state, initial_state_heuristics, 0.0, initial_state_heuristics));

    //as long as there are frontier nodes
    while(!open.empty()){

        SearchNode current = open.top(); open.pop();                  //select node for expansion
        closed.emplace(current);                                  //update list of expanded nodes

        if(current.state.isSolved()) {
            return makeMovesList(current);                      //goal found, return solution
        }else{
            
        }
    

    }




    return std::list<moves>();              //no solution exists
}

std::list<moves> AStar::makeMovesList(SearchNode& goal_state){
    return;
}

bool AStar::GreaterF::operator()(const SearchNode& s1, const SearchNode& s2) const{
    return s1.f > s2.f;
}

void AStar::improve(SearchNode& state){

}



#endif
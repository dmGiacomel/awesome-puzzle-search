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

    std::list<moves> path = driverProcedure();

    return driverProcedure();
}


std::list<moves> AStar::driverProcedure(){
    
    return;
}

bool AStar::GreaterF::operator()(const SearchNode& s1, const SearchNode& s2) const{
    return s1.f > s2.f;
}

void AStar::update(SearchNode& state){

}



#endif
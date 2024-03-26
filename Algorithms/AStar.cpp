#ifndef A_STAR_CPP
#define A_STAR_CPP
#include "AStar.hpp"
#include <vector>

//depois eu vejo isso
AStar::AStar(){}

AStar::~AStar(){}

std::list<moves> AStar::solve(const Puzzle& initial_state, 
                              const Puzzle& goal_state,
                              Heuristics* heuristic)
{
    std::cout << "Right after calling solve method\n";

    heuristics = heuristic;

    std::cout << "Heuristics setted\n";

    this->initial_state = initial_state;

    std::cout << "Initial state setted\n";

    this->goal_state = goal_state;

    std::cout << "Goal state setted\n";


    std::cout << "Before clearing open set\n";

    //making sure open and closed are empty
    while (!open.empty())
        open.pop();

    std::cout << "Before clearing closed set\n";

    closed.clear();

    std::cout << "Before calling driver procedure\n";

    std::list<moves> path = driverProcedure();

    return path;
}

//may good help us all if the heuristic is non-consistent
std::list<moves> AStar::driverProcedure(){

    //starting the open set with the initial state
    //closed set starts empty (guaranteed by solve())
    double initial_state_heuristics = heuristics->evaluate(initial_state); //initialize estimate
    open.push(SearchNode(nullptr, moves(none), initial_state, initial_state_heuristics, 0.0, initial_state_heuristics));
    //as long as there are frontier nodes
    while(!open.empty()){
        
        //done this way so we can retrieve the path easily after the execution
        //avoid dangling pointers - closed will take care of memory
        SearchNode *node = new SearchNode(open.top());
        open.pop();                  
        const SearchNode& current = *closed.emplace(std::move(*node)).first;  

        if(current.state.isSolved()) {
            return makeMovesList(current);                      //goal found, return solution
        }else{
            std::set<SearchNode> successors = generateSuccessors(current);
            for (auto& i : successors){
                improve(i);
            }
        }
    }

    return std::list<moves>();              //no solution exists
}

//no duplicate detection 
//may good help us all if the heuristic is non-consistent
void AStar::improve(const SearchNode& state){
    auto state_in_closed = closed.find(state);
    if(state_in_closed != closed.end()){
        if(state.g < state_in_closed->g){
            open.emplace(*state_in_closed);
            closed.extract(state_in_closed);
        }
    }else{ //with consistent heuristics it always falls here
        open.emplace(state);
    }
}

std::set<SearchNode> AStar::generateSuccessors(const SearchNode& node){
    
    std::set<SearchNode> successors;
    std::set<moves> available_moves = node.state.availableMoves();

    double g = node.g + 1;  //unit cost abreviation for w(parent, node)
    for (auto i: available_moves){        
        Puzzle temp = node.state;
        temp.makeMove(i);
        double h = heuristics->evaluate(temp); 
        successors.insert(SearchNode(const_cast<SearchNode*>(&node), i, temp, h + g, g, h));
    }

    return successors;
}

std::list<moves> AStar::makeMovesList(const SearchNode& goal_state){

    std::list<moves> path;
    
    SearchNode aux_node = goal_state;
    while(aux_node.parent != nullptr){
        path.push_back(aux_node.generated_by);
        aux_node = *aux_node.parent; 
    }

    return std::move(path);
}

bool AStar::GreaterF::operator()(const SearchNode& s1, const SearchNode& s2) const{
    return s1.f > s2.f;
}

//ARRUMAR DEPOISSSSSSSSSSSSSSSSS
size_t AStar::HashSearchNode::operator()(const SearchNode& s) const{

    std::vector<unsigned char> state = s.state.getPuzzleAsString();

    std::hash<unsigned char> hasher;
    size_t hash = 0;

    for (unsigned char i : state) {
        hash ^= hasher(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
    }

    return hash;
}

bool AStar::EqualsSearchNode::operator()(const SearchNode& s1, const SearchNode& s2) const{
    return s1.state == s2.state;
}



#endif
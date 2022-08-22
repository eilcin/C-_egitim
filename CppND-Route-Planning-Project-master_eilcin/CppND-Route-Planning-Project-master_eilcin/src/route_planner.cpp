#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;        //this *= is operator of multiply =, its not a pointer 
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    start_node = &m_Model.FindClosestNode(start_x,start_y);     //so here pointer to start_node is done in the header, we need to reference the address
     end_node = &m_Model.FindClosestNode(end_x,end_y);          //and give it back to the already assigned pointer, dont need to ref or point since they are in the 
                                                                //the csope of this class
}



float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
    return node->distance(*end_node);
}


void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
    current_node->FindNeighbors();

    for(RouteModel::Node *NewlistNode : current_node->neighbors) {
        NewlistNode->parent=current_node;
        NewlistNode->h_value=CalculateHValue(NewlistNode);
        NewlistNode->g_value=current_node->g_value + current_node->distance(*NewlistNode);    //260422g value is g value + distance to the next one, use the distance method again.  Had to dereference current_node
        open_list.push_back(NewlistNode); //add neighbours to open_list, open list is a vector array and I need to push each node on to the back of it, i think 
        NewlistNode->visited = true;   //set visited to true   
    }
}

bool cmp(RouteModel::Node* node1,RouteModel::Node* node2){         //this is a normal function, not certain why node1 and node2 aren't identical i.e. the same node pointer?
return (node1->g_value + node1->h_value) > (node2->g_value + node2->h_value);}  //this gives us descending order

RouteModel::Node *RoutePlanner::NextNode() {    //return a rmodel node* from he function NextNode() this is a member function of routeplanner class
//need to add a compare helper to use with the sort(open_list(begin) : open_list (end))
sort(open_list.begin(),open_list.end(),cmp);
//now create a pointer to the lowest one, then pop it and return the pointer
 RouteModel::Node* least = open_list.back();
 open_list.pop_back();
 return least;
}


std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {  //returns a vector of nodes, has pointer to current node as argument
    // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;   //this is a new vector of type routemodel::node class


    while (current_node->parent){
        distance += current_node->distance(*current_node->parent);
        path_found.push_back(*current_node);
        current_node = current_node->parent;    //here is where we loop back thru
    }
    std::reverse (path_found.begin(), path_found.end());
    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;  //path found is a node vector

}



void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;
    //I think it calls astarsearch but doesn't setup the data properly so open_list is empty!  22/04/22
    //need to populate the open_list with something, start node I guess
    current_node = start_node;
    open_list.push_back(current_node);    //setup the list with 1st node (the start node)
    current_node->visited =true;          //record the node as visitedm since it is.
    while(!open_list.empty()){


}
    }

  // TODO: Implement your solution here.

}
from sys import maxsize
from itertools import permutations
# V = 4

def travel_salesman(graph, source, n):

    #storing vertices other than source to create random paths out of it
    # like if source = 1, vertex = [2,3,4] 
    # => random paths generated via permutation will be [3,4,2],[4,3,2],[4,2,3]..... etc
    vertex = []
    for i in range(n):
        if(i != source):
            vertex.append(i)

    min_costing_path = maxsize      # to store minimum costing path
    next_permutation = permutations(vertex)     # random paths generated via permutation.

    # for all generated paths
    for path in next_permutation:

        current_city = source      # start with source
        current_path_cost = 0    # initialised for this path

        # calculating cost of the path
        for nexxt in path:
            current_path_cost += graph[current_city][nexxt]
            current_city = nexxt

        # at last return back to source city => add that cost
        current_path_cost += graph[current_city][source]

        # update min path
        min_costing_path = min(min_costing_path, current_path_cost)

    return min_costing_path

graph = [[0,10,15,20], [5,0,25,10],[15,30,0,5],[15,10,20,0]]

min_cost = travel_salesman(graph,0,4)
print(min_cost)


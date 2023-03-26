#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "cGraph.h"
#include "GraphTheory.h"
#include "so758462167.h"

main()
{
    so758462167 spec;
    readfile(
        spec,
        "../dat/input.txt");

    auto vPaths = raven::graph::allPaths(
        spec.g,
        spec.g.find((spec.start)),
        spec.g.find((spec.dest)));

    for( auto& p : vPaths )
    {
        for( auto v : spec.g.userName( p ) )
            std::cout << v << " ";
        std::cout << "\n";
    }

    return 0;
}

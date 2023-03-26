#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "cGraph.h"

void readfile(
    raven::graph::cGraph &g,
    const std::string &fname);

main()
{

    raven::graph::cGraph g;
    readfile(g, "../dat/input.txt");

    return 0;
}

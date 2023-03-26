#include <fstream>
#include <sstream>
#include <iostream>
#include "cGraph.h"

static std::vector<std::string> tokenize(const std::string &line)
{
    std::vector<std::string> ret;
    std::stringstream sst(line);
    std::string a;
    while (getline(sst, a, ','))
        ret.push_back(a);
    return ret;
}

void readfile(
    raven::graph::cGraph &g,
    const std::string &fname)
{
    g.clear();
    std::ifstream ifs(fname);
    if (!ifs.is_open())
        throw std::runtime_error(
            "Cannot open input file");

    std::string vertexPropNames, edgePropNames;

    std::string linetype, list;
    while (ifs.good())
    {
        ifs >> linetype;
        if (linetype.find("VP") != -1)
        {
            ifs >> vertexPropNames;
            std::cout << vertexPropNames << "\n";
        }
        else if (linetype.find("EP") != -1)
        {
            ifs >> edgePropNames;
            std::cout << edgePropNames << "\n";
        }
        else if (linetype.find("V") != -1) {
            std::string name,propValues;
            ifs >> name >> propValues;
            int vi = g.add( name );
            g.wVertexAttr(vi,tokenize(propValues));
        }
        else if (linetype.find("E") != -1) {
            std::string name, src, dst, propValues;
            ifs >> name >> src >> dst >> propValues;
            int ie = g.add( src,dst );
            g.wEdgeAttr(ie,tokenize(propValues));
        }
    }
    std::cout << g.text();
}

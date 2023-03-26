#include <fstream>
#include <sstream>
#include <iostream>
#include "cGraph.h"
#include "so758462167.h"

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
    so758462167& spec,
    const std::string &fname)
{
    spec.g.clear();
    std::ifstream ifs(fname);
    if (!ifs.is_open())
        throw std::runtime_error(
            "Cannot open input file");



    std::string linetype, list;
    while (ifs.good())
    {
        ifs >> linetype;
        if (linetype.find("VP") != -1)
        {
            ifs >> spec.vertexPropNames;
        }
        else if (linetype.find("EP") != -1)
        {
            ifs >> spec.edgePropNames;
        }
        else if (linetype.find("V") != -1) {
            std::string name,propValues;
            ifs >> name >> propValues;
            int vi = spec.g.add( name );
            spec.g.wVertexAttr(vi,tokenize(propValues));
        }
        else if (linetype.find("E") != -1) {
            std::string name, src, dst, propValues;
            ifs >> name >> src >> dst >> propValues;
            int ie = spec.g.add( src,dst );
            spec.g.wEdgeAttr(ie,tokenize(propValues));
        }
        else if (linetype.find("S") != -1) {
            ifs >> spec.start;
        }
        else if (linetype.find("D") != -1) {
            ifs >> spec.dest;
        }

    }
    //std::cout << spec.g.text();
}

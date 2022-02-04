#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#define STRLEN 10

std::map <std::string, std::vector<std::string>> nodes;

int  main()
{
    std::string filename("./input_day12.txt");
    // std::ifstream input_file(filename);
    std::ifstream input_file;
    input_file.open(filename);
    std::string node;
    std::string neighbour;

    while (getline(input_file, node, '-'))
    {
        getline(input_file, neighbour, '\n');
        nodes[node].push_back(neighbour);
        nodes[neighbour].push_back(node);
    }
    input_file.close();

    // for (std::map<std::string, std::vector<std::string>>::iterator it = nodes.begin();
    // it != nodes.end(); ++it)
    for (auto i=nodes.begin(); i != nodes.end(); ++i) {
        std::cout << (*i).first << std::endl;
        for (auto j : i->second)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }


    // while (fgets(str, STRLEN, pFile) != NULL)
    // {
    //     pChar = strtok(str, "-");
    //     nodes[]
    //     printf("%s", pChar);
    //     pChar = strtok(NULL, "-");
    //     printf("%s", pChar);
    // };
    return 0;
}
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Header.h"
int main()
{
    std::ifstream myFile;
    std::ifstream myNewFile;
    std::string x;
    std::string y;
    std::string vertex;
    std::string edge;
    std::string point;
    bool oneThroughFour = true;
    char choice;
    std::string loadGraph;
    std::string G2;
    std::string loadEdge;
    std::string loadEdge2;
    std::vector<std::string> edgeSearch;
    std::vector<Point> g1;
    double newX;
    double newY;
    std::vector<Point> g2;
    std::string targetEdge;
    while (oneThroughFour)
    {
        std::cout << " What is it you would like?\n 1. Load Graph File (graph.txt)."
            "\n 2. Search For Edge. \n 3. Print Graph. \n 4. Load and Compare 2nd Graph Against 1st graph. \n 5. Exit\n\n";
        std::cin >> choice;

        if (choice == '1')
        {
            edgeSearch.clear();
            myFile.close();
            std::cout << "What is the name of the Graph you would like to Load? (reminder to use .txt in the file):";
            std::cin >> loadGraph;
            myFile.open(loadGraph);
            while (getline(myFile, point)) 
            {
                if (point.empty()) continue;
                std::stringstream ss(point);

                if (ss >> x >> y) {
                    edgeSearch.push_back(x);
                    edgeSearch.push_back(y); 
                    g1.push_back(stringToPoint(x));
                    g1.push_back(stringToPoint(y));
                }
            }
    
            std::cout << "Your Graph has been Loaded.\n\n";
            myFile.close();
        }

        else if (choice == '2')
        {
            std::cout << "What is the First Point of the Edge you would like to Find?:";
            std::cin >> loadEdge;
            std::cout << "What is the Second Point of the Edge you would like to Find?:";
            std::cin >> loadEdge2;
            bool found = false;
            for (int i = 0; i < (int)edgeSearch.size() - 1; i++)
            {
                if ((loadEdge == edgeSearch[i] && loadEdge2 == edgeSearch[i + 1]) ||
                    (loadEdge2 == edgeSearch[i] && loadEdge == edgeSearch[i + 1]))
                {
                    found = true;
                    break;
                }
            }
            if (found) 
            {
                std::cout << "Your Edge has been Found.\n\n";
            }
            else 
            {
                std::cout << "Your Edge doesn't seem to be in this Graph.\n\n";
            }
        }

        else if (choice == '3')
        {
            std::cout << " Vertices " << vertex << " Edges " << edge << "\n";
            for (int i = 0; i < (int)edgeSearch.size(); i += 2)
            {
                std::cout << "" << (i / 2) << ": (" << edgeSearch[i] << ") / (" << edgeSearch[i + 1] << ")\n";
            }
            std::cout << "\n\n";

        }

        else if (choice == '4')
        {
            std::cout << "What is the name of the Graph you would like to Compare? \n "
                "(reminder to use .txt in the file and the file you enter\n will be compared to the first one you loaded in previously):";
            std::cin >> G2;
            myNewFile.open(G2);
            while (getline(myNewFile, point))
            {
                if (point.empty() || point.find(',') == std::string::npos) continue;
                if (point.empty()) continue;
                std::stringstream ss(point);

                if (ss >> x >> y) 
                {
                    g2.push_back(stringToPoint(x));
                    g2.push_back(stringToPoint(y));
                }
            }
            myNewFile.close(); 
            bool foundIntersection = false; 

            for (int i = 0; i < (int)g1.size(); i += 2) {
                for (int j = 0; j < (int)g2.size(); j += 2) {
                    if (segmentsIntersect(g1[i], g1[i + 1], g2[j], g2[j + 1])) {
                        foundIntersection = true;
                        break; 
                    }
                }
                if (foundIntersection) break; 
            }

            if (foundIntersection) {
                std::cout << "Intersection Found.\n";
            }
            else {
                std::cout << "Your Graphs do not Touch.\n";
            }
            
        }

        else if (choice == '5')
        {
         std::cout << "You Have Exited";
         oneThroughFour = false;
        }
        else
        {
         std::cout << "Try with what is presented.\n\n";
        }

    }

}

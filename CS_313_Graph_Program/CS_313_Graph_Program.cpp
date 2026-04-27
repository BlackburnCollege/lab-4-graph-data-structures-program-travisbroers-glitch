#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Header.h"
int main()
{
    std::ifstream myFile;
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
    std::vector<std::string> secondSearch;
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
            getline(myFile, vertex, ' ');
            getline(myFile, edge, '\n');
            while (getline(myFile, point))
            {
                if (point.empty()) continue;
                std::stringstream ss(point);
                if (ss >> x >> y) 
                {
                    if (edgeSearch.empty()) 
                    {
                        edgeSearch.push_back(x);
                    }
                    edgeSearch.push_back(y);
                }

            }
            std::cout << "Your Graph has been Loaded.\n\n";
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
            std::cout << "Number of Vertices: " << vertex << " \nNumber of Edges: " << edge << "\n";
            std::cout << "Vertices: ";
            for (int i = 0; i < edgeSearch.size(); i++)
            {
                std::cout << "(" << edgeSearch[i] << ")" << (i == edgeSearch.size() - 1 ? "" : ", ");
            }
            std::cout << "\n";

            for (int i = 0; i < (int)edgeSearch.size() - 1; i++)
            {
                std::cout << "Edge " << i + 1 << ": (" << edgeSearch[i] << ") / (" << edgeSearch[i + 1] << ")\n";
            }
            std::cout << "\n\n";

        }

        else if (choice == '4')
        {
            std::cout << "What is the name of the Graph you would like to Compare? \n "
                "(reminder to use .txt in the file and the file you enter\n will be compared to the first one you loaded in previously):";
            std::cin >> G2;
            myFile.open(G2);
            getline(myFile, vertex, ' ');
            getline(myFile, edge, '\n');
            while (getline(myFile, point))
            {
                if (point.empty()) continue;
                std::stringstream ss(point);
                if (ss >> x >> y)
                {
                    if (secondSearch.empty())
                    {
                        secondSearch.push_back(x);
                    }
                    secondSearch.push_back(y);
                }
            }
            bool doIntersect = false;
            for (int i = 0; i < (int)edgeSearch.size() - 1; i++) {

                // ...against every line segment in the second vector
                for (int j = 0; j < (int)edgeSearch.size() - 1; j++) {

                    Point p1 = edgeSearch[i];     // Start of line 1
                    Point q1 = edgeSearch[i + 1];   // End of line 1

                    Point p2 = edgeSearch[j];     // Start of line 2
                    Point q2 = edgeSearch[j + 1];   // End of line 2

                    if (doIntersect(p1, q1, p2, q2)) {
                        std::cout << "Intersection detected!\n";
                    }
                }
            }
            if (intersect)
            {
                std::cout << "Your Graghs appear to Intersect.\n\n";
            }
            else
            {
                std::cout << "Your Graghs seem to Not Touch.\n\n";
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

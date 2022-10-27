
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "fhandling.h"

using namespace std;




int rf(string fn, vector<vector<double>>& p1, vector<vector<double>>& p2) {
    
    ifstream fin("input.txt");
    double x1, y1, z1, x2, y2, z2;
    if (!fin.is_open()) {
        cout << "File could not be opened " << endl;


    }

    while (!fin.eof()) {
        int i;
        p1.resize(p1.size() + 1);
        p2.resize(p2.size() + 1);
        i = p2.size() - 1;

        p1.at(i).resize(3);
        p2.at(i).resize(3);

        fin >> p1.at(i).at(0) >> p1.at(i).at(1) >> p1.at(i).at(2);
        fin >> p2.at(i).at(0) >> p2.at(i).at(1) >> p2.at(i).at(2);

    }
    fin.close();




    return 0;
}


void gD(vector<vector<double>> p1, vector<vector<double>> p2, vector<double>& d){

    d.resize(p1.size());

    for (int i = 0; i < d.size();i++) {
        d.at(i) = calcDistance(p1.at(i).at(0), p1.at(i).at(1), p1.at(i).at(2), p2.at(i).at(0), p2.at(i).at(1), p2.at(i).at(2));
    }
}

int wf(string fn, vector<double>& d) {
    ofstream fout(fn);
    int arrLen = d.size(); 
    fout.open("fn");
    for (int i = 0; i < arrLen; i++) {
        
        fout << d.at(i);
    }
    fout.close();
    return 1;
}



double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2) {

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}


void sort_vector(vector<double>& d)   
{
    double temp;
    for (int i = 0; i < d.size() - 1; i++)
    {
        for (int j = 0; j < d.size() - i - 1; j++)
        {
            if (d[j] > d[j + 1]) 
            {
                temp = d[j + 1];          
                d[j + 1] = d[j];
                d[j] = temp;
            }
        }
    }
}



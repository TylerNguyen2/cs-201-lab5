
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "fhandling.h"

using namespace std;


int main()
{   
    
    ofstream fout("output.txt");

    vector<vector<double>> p1, p2;
    vector<double> d;

    if (rf("input.txt", p1, p2) == 1) {

        return 1;
    }
    
    gD(p1, p2, d);

    if (wf("output.txt", d) == 1) {
        ofstream fout("output.txt");               
        for (int i = 0; i < d.size(); i++)   
        {
            fout << d[i] << endl;
        }
        return 1;
    }
  
    ofstream fout1("output_sorted.txt");
    sort_vector(d);                      
    for (int i = 0; i < d.size(); i++)    
    {
        fout1 << d[i] << endl;
    }
   
    

}
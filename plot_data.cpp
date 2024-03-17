#include<iostream>
#include<fstream>
#include<simplecpp>
#include<vector>
#include<string>

using namespace std;

int main(){
    ifstream inputFile("../text_files/dataPoints.txt");
    vector<vector<float>> data;

    initCanvas("output", 1920, 1080);

    float prev[2] = { 0, 0};
    float next[2] = { 0, 0};

    string line;
    while(getline(inputFile, line)){
        int splitter = line.find(",");
        prev[0] = next[0] ; prev[1] = next[1] ;
        next[0] = stof(line.substr(0,splitter)); next[1] = stof(line.substr(splitter+1));
        if ( prev[0] == 0 && prev[1] == 0) {prev[0] = next[0] ; prev[1] = next[1] ;}
        Line l(prev[0], prev[1], next[0], next[1]);
        l.imprint();
    }

    getClick();
}
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <time.h>
#include <numeric>
#include <algorithm>
#include <assert.h>



using namespace std;

int l = 3;
int valx;
int valy;
int evalx;
int evaly;
int evaltotal;
double evalxtotal = 0;
double evalytotal = 0;
double sumx = 0;
double sumy = 0;


class agent
{
public:
    vector<double> archivex;
    vector<double> archivey;
    vector<double> evaluationx;
    vector<double> evaluationy;
    vector<double> noveltyofx;
    vector<double> noveltyofy;
    vector<double> noveltyvector;
    double novelty;

    void initialize();
    void evaluate();
    void print();

};

vector<agent>agents(3);

void agent::initialize()
{
    archivex.clear();
    archivey.clear();
    for (int j = 0; j < l; j++)
    {
        valx = (rand() % 10 + 1);
        archivex.push_back(valx);

        valy = (rand() % 10 + 1);
        archivey.push_back(valy);
    }
    cout << "X and Y vectors created:" << endl;
}

void agent::print()
{
//    archivex;
//    archivey;
//    evaluationx;
//    evaluationy;
//    noveltyofx;
//    noveltyofy;
//    noveltyvector;
//    novelty;

    for (vector<double>::const_iterator i = archivex.begin(); i != archivex.end(); i++) {
        cout << *i << endl;
    }


}




void agent::evaluate()
{

    for (int i = 1; i < l; i++)
    {

      for(int j = 0; j < i; j++)
        {
        for(unsigned int m = 0; m < agents.size(); m++)
            {
                evalx = abs(archivex.at(i)- agents[m].archivex.at(j));
                evalxtotal = evalxtotal + evalx;

                evaly = abs(archivey.at(i) - agents[m].archivey.at(j));
                evalytotal = evalytotal + evaly;

            }

        }

        noveltyofx.push_back(evalxtotal);
        noveltyofy.push_back(evalytotal);

    }

        sumx = accumulate(noveltyofx.begin(), noveltyofx.end(), 0.0);
        sumy = accumulate(noveltyofy.begin(), noveltyofy.end(), 0.0);
        novelty = sumx+sumy;

        noveltyvector.push_back(novelty);


    cout << "Novelty Vector: " << endl;
        for (vector<double>::const_iterator i = noveltyvector.begin(); i != noveltyvector.end(); ++i)
        {
            std::cout << *i << ' ';
        }


    cout << " " << endl;
    cout << "Novelty: "<< novelty << endl;

}

void agentcreation()
{

for (unsigned int m = 0; m < agents.size(); m++)
{
   for (unsigned int i = 0; i < agents.size(); i++)
    {
    agents[m].initialize();
    }
}
    //for (vector<agent>::const_iterator i = agents.begin(); i != agents.end(); i++) {
    //    (*i)->evaluate();
    //}

   for (unsigned int i = 0; i < agents.size(); i++)
    {
        evalx = 0;
        evaly =0;
        evaltotal = 0;
        evalxtotal = 0;
        evalytotal = 0;

      agents[i].evaluate();
      agents[i].print();

    cout << agents[0].novelty << " ?? " << agents[1].novelty << endl;

    cout << " End of Run: " << i << endl;
    cout << " " << endl;
    }

}

int main()
{
    srand(time(NULL));

    cout << "Program Initialization:" << endl;
    cout << " " << endl;

    agentcreation();

    cout << " " << endl;
    cout << "Done"<< endl;

    return 0;
}


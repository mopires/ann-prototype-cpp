#include <vector>
#include <exception>
#include <time.h>
#include "Neuron.hpp"

typedef vector<vector<Neuron>> matrix;
typedef vector<Neuron> Array_Of_Neuron;
typedef vector<float> Array_Of_Float; 

class Network
{
    private:
        int NumberOfHiddenLayers;
        int NumberOfNeurons;
        matrix network;

        void SetNeuronsInLayers();
        void InitWeight();

        //method's for checking data
        int CheckIndex(int &Index, Array_Of_Neuron Layer);
        void See();

    public:
        Network(int NumberOfHiddenLayers);
        void InputData(Array_Of_Float Data);

};

Network::Network(int NumberOfHiddenLayers = 2)
{
    this->NumberOfHiddenLayers = NumberOfHiddenLayers;
    SetNeuronsInLayers();
    InitWeight();
    See();
}

void Network::SetNeuronsInLayers()
{
    try
    {
        matrix network(this->NumberOfHiddenLayers);

        for (int i = 0; i < this->NumberOfHiddenLayers; i++)
        {
            std::cout << " Layer [" << i << "]: ";
            cin >> NumberOfNeurons;
            //NumberOfNeurons++; pq?

            for (int j = 0; j < NumberOfNeurons; j++)
            {
                network[i].push_back(Neuron(j));
            }
        }
        this->network = network;
    }
    catch(exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
}

void Network::InputData(Array_Of_Float Data)
{
    for (int i = 0; i < Data.size(); i++)
    {
        for (int j = 0; j < this->network.size(); j++)
        {
            this->network[i][j].Input(Data.at(i));
            
            if(i == Data.size() && j == this->network.size())
            {
                this->network[i][j].Input(1);//BIAS
            }
        }
    }

    
    
}

void Network::InitWeight()
{
    try
    {
        for (int i = 0; i < this->network.size(); i++)
        {
            for (int j = 0; j < this->network[i].size(); j++)
            {
                if (i+1 >= this->network.size()){
                    break;
                }
                else
                {
                    const int size = this->network[i+1].size();
                    float weight[size];
                    for (int k = 0; k < this->network[i+1].size(); k++)
                    {
                        weight[i] = 0;
                    }
                    this->network[i][j].SetWeight(weight);
                    
                }
                
            }
            
        }
           
    }
    catch(exception ex)
    {
        cout << "Exception when setting the weights -> " << ex.what() << endl;
    }
}



void Network::See()
{
    for (int i = 0; i < this->network.size(); i++)
    {
        cout << "\t ====== Layer [" << i << "] ======" << endl;
        for (int j = 0; j < this->network[i].size(); j++)
        {
            cout << " Neuron -> " << this->network[i][j].getId() << endl;
            cout << " Weights -> ";
            for (int k = 0; k < sizeof(this->network[i][j].getW()); k++)
            {
                cout << this->network[i][j].getW()[k] << " - ";
            }
            cout << endl;
        }
        
    }
    
}






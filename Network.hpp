#include <vector>
#include <exception>
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

    public:
        Network(int NumberOfHiddenLayers);
        void InputData(Array_Of_Float Data);

        void See(matrix Network);
};

Network::Network(int NumberOfHiddenLayers = 2)
{
    this->NumberOfHiddenLayers = NumberOfHiddenLayers;
    SetNeuronsInLayers();
    InitWeight();
    See(network);
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
            NumberOfNeurons++;

            for (int j = 0; j < NumberOfNeurons; j++)
            {
                network[i].push_back(Neuron());
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
    try{

        Array_Of_Float weight;
        /*

            CRIAÇÃO DE PONTEIRO
        */
        float *ponteiro = weight.get_allocator().allocate(this->NumberOfNeurons);

        for (int i = 0; i < this->NumberOfHiddenLayers; i++)
        {   
            for (int j = 0; j < this->network[i].size(); j++)
            {
                if(i == this->NumberOfHiddenLayers)
                {
                    break;
                }
                else
                {
                    //weight.resize(network[i+1].size());
                    for (int k = 0; k < weight.size(); k++)
                    {
                        weight.get_allocator().construct(&ponteiro[k], rand()/100.0f);
                    }
                    network[i][j].SetWeight(weight);
                    
                    //
                    //
                    //how to free the vector in the memory here?
                    //
                    //Erro durante execução:
                    //double free or corruption (fasttop)
                    //Abortado


                    for (int k = 0; k < weight.size(); k++)
                    {
                        weight.get_allocator().destroy(&ponteiro[k]);
                    }
                    
                    weight.get_allocator().deallocate(ponteiro, this->NumberOfNeurons);
                }
            }
            

        }
    }
    catch(exception ex)
    {
        cout << ex.what() << endl;
    }
}



void Network::See(matrix Network)
{

    for (int i = 0; i < this->NumberOfHiddenLayers; i++)
    {
        for (int j = 0; j < this->NumberOfNeurons; j++)
        {
            std::cout << "Layer [" << i << "] ";
            Network[i][j].getId();
        }
        std::cout << std::endl;
    }
    

}






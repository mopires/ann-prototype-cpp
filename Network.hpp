#include <vector>
#include "Neuron.hpp"

typedef vector<vector<Neuron>> matrix;

class Network
{
    private:
        int NumberOfHiddenLayers;
        int NumberOfNeurons;

        void SetNeuronsInLayers();
        //input functions

    public:
        Network(int NumberOfHiddenLayers);
        
        void See(matrix Network);

    
};

Network::Network(int NumberOfHiddenLayers = 2)
{
    this->NumberOfHiddenLayers = NumberOfHiddenLayers;
    SetNeuronsInLayers();
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
            //vector<Neuron> neurons;

            for (int j = 0; j < NumberOfNeurons; j++)
            {
                network[i].push_back(Neuron(j));
            }
            
            
            
        }

    }
    catch(std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
}

void Network::See(matrix Network)
{

    for (int i = 0; i < this->NumberOfHiddenLayers; i++)
    {
        for (int j = 0; j < this->NumberOfNeurons; j++)
        {
            std::cout << "Layer [" << i << "] " << "Neuron: " << Network[i][j].getId() << " | ";
        }
        std::cout << std::endl;
    }
    

}
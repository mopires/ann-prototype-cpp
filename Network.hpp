#include <vector>
#include "Neuron.hpp"

typedef vector<vector<Neuron>> matrix;
typedef vector<float> Array_Of_Float; 

class Network
{
    private:
        int NumberOfHiddenLayers;
        int NumberOfNeurons;
        matrix network;

        void SetNeuronsInLayers();
        

    public:
        Network(int NumberOfHiddenLayers);
        //void See(matrix Network);

        void InputData(Array_Of_Float Data, float Output, bool Training);
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
                network[i].push_back(Neuron());
            }
        }
        this->network = network;
    }
    catch(std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
}

void Network::InputData(Array_Of_Float Data, float Output = NULL, bool Training)
{
    for (int i = 0; i < Data.size(); i++)
    {
        for (size_t j = 0; j < this->network.size(); j++)
        {
            this->network[i][j].Input(Data.at(i));
        }
        
    }
    if (!Training)
    {
        
    }
    else
    {
        
    }
    
    
    
}











// void Network::See(matrix Network)
// {

//     for (int i = 0; i < this->NumberOfHiddenLayers; i++)
//     {
//         for (int j = 0; j < this->NumberOfNeurons; j++)
//         {
//             std::cout << "Layer [" << i << "] " << "Neuron: " << Network[i][j].getId() << " | ";
//         }
//         std::cout << std::endl;
//     }
    

// }






#include <iostream>
#include <string>
#include <exception>
//#include "Network.hpp"

using namespace std;

typedef vector<float> Array_Of_Float;

class Neuron
{
    private:
        int id;
        float Value;
        Array_Of_Float Weight;

    public:
        Neuron();

        virtual void Input(float Input);
        virtual void Activation();
        void SetWeight(Array_Of_Float Weight);
        
        void getId();
};

Neuron::Neuron()
{
    
}

void Neuron::Input(float Input)
{
    this->Value = Input;
}

void Neuron::Activation()
{
    
}

void Neuron::SetWeight(Array_Of_Float Weight)
{
    this->Weight = Weight;
}



void Neuron::getId()
{
    cout << this->id << " W's -> ";
    for (int i = 0; i < this->Weight.size(); i++)
    {
        cout << Weight.at(i) << " ";
    }
    
}
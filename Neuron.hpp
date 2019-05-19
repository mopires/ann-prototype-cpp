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
        float *Weight;

    public:
        Neuron(int id);

        virtual void Input(float Input);
        virtual void Activation();
        void SetWeight(float Weight[]);
        
        int getId();
        float* getWeight();
};

Neuron::Neuron(int id)
{
    this->id = id;
}

void Neuron::Input(float Input)
{
    this->Value = Input;
}

void Neuron::Activation(){}

void Neuron::SetWeight(float Weight[])
{
    this->Weight = Weight;
}



int Neuron::getId()
{
    return id;
}

float* Neuron::getWeight(){

    return this->Weight;
}
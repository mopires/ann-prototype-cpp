#include <iostream>
#include <string>
#include "math.h"
#include <exception>

using namespace std;

class Neuron
{
    private:
        float Value;
        vector<float> Weight;

    public:
        Neuron();
        //int getId();//tirar isso

        virtual void Input(float Input);
        virtual void Activation();

};

Neuron::Neuron()
{
    
}

void Neuron::Input(float Input){
    this->Value = Input;
}

void Neuron::Activation(){
    
}

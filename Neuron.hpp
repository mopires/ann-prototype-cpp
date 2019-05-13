#include <iostream>
#include <string>
#include "math.h"
#include <exception>

using namespace std;

class Neuron
{
    private:
        int id;
        

    public:
        Neuron(int id);
        int getId();//tirar isso

        virtual void Input(/*tipo de imput*/);
        virtual void Activation();

};

Neuron::Neuron(int id)
{
    this->id = id;
    
}

void Neuron::Input(){

}

void Neuron::Activation(){
    
}

int Neuron::getId(){
    return this->id;
}
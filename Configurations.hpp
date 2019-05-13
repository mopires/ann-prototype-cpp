#include <iostream>
#include <string.h>
#include <exception>

using namespace std;

class Configuration
{

    private:
        int Epochs = 500;
        float LearnTax;

        //string SaveLearning();

    public:
        Configuration(int Epochs, float LearnTax);

        void SetEpochs(int Epochs);
        void SetLearnTax(float LearnTax);

};

Configuration::Configuration(int Epochs = 500, float LearnTax = 0.03f)
{
    try
    {
        SetEpochs(Epochs);
        SetLearnTax(LearnTax);
        cout << " :: Configurations set :: " << endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }


}

void Configuration::SetEpochs(int Epochs)
{
    this->Epochs = Epochs;
}

void Configuration::SetLearnTax(float LearnTax)
{
    this->LearnTax = LearnTax;
}





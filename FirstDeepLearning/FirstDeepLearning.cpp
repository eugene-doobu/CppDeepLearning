#include <iostream>

#define MAX2(a, b) (a) > (b) ? (a) : (b)

class Neuron
{
public:
    Neuron() : w_(2.0), b_(1.0) {}
    Neuron(const double& w_input, const double& b_input) : w_(w_input), b_(b_input) {}

public:
    double w_; // weight of one input
    double b_; // bias

    double getAct(const double& x)
    {
	    // for linear or identity activation functions
        return x;

        // for ReLU activation functions
        // return MAX2(0.0, x);
    }

    double feedForward(const double& input)
    {
	    // output y = f(\sigma)
        // \simga = w_ * input x + b
        // for multiple inputs,
        // \sigma = w0_ * x0_ + w1_ * x1_ + ... + b

        const double sigma = w_ * input + b_;

        return getAct(sigma);
    }
};

int main()
{
    Neuron my_neuron(2.0, 1.0);

    std::cout << "Input = 0.0 " << my_neuron.feedForward(0.0) << std::endl;
    std::cout << "Input = 1.0 " << my_neuron.feedForward(1.0) << std::endl;
    std::cout << "Input = 2.0 " << my_neuron.feedForward(2.0) << std::endl;
    std::cout << "Input = 3.0 " << my_neuron.feedForward(3.0) << std::endl;
}
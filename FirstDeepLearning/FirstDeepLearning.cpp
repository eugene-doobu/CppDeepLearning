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

    double input_, output_; // saved for back-prop

    double getAct(const double& x)
    {
	    // for linear or identity activation functions
        return x;

        // for ReLU activation functions
        // return MAX2(0.0, x);
    }

    double getActGrad(const double& x)
    {
        // for linear or identity activation functions
        return 1.0;

        // ReLU if(x > 0.0) return 1.0; else 0.0;
    }

    double feedForward(const double& input)
    {
        input_ = input;

	    // output y = f(\sigma)
        // \simga = w_ * input x + b
        // for multiple inputs,
        // \sigma = w0_ * x0_ + w1_ * x1_ + ... + b

        const double sigma = w_ * input + b_;
        output_ = getAct(sigma);

        return output_;
    }

    void propBackward(const double& target)
    {
        const double alpha = 0.1; // learning rate

        const double grad = (output_ - target) * getActGrad(output_);

        w_ -= alpha * grad * input_; // last input_ came from d(wx+b)/dw = x
        b_ -= alpha * grad * 1.0; // last 1.0 came from d(wx+b)/db = 1
    }
};

int main()
{
    Neuron my_neuron(2.0, 1.0);

    std::cout << "example 1" << std::endl;
    std::cout << "Input = 0.0 " << my_neuron.feedForward(0.0) << std::endl;
    std::cout << "Input = 1.0 " << my_neuron.feedForward(1.0) << std::endl;
    std::cout << "Input = 2.0 " << my_neuron.feedForward(2.0) << std::endl;
    std::cout << "Input = 3.0 " << my_neuron.feedForward(3.0) << std::endl;
    std::cout << std::endl;;

    std::cout << "example 2" << std::endl;
    for (int r = 0; r < 10; ++r)
    {
        std::cout << "Training " << r << std::endl;

        std::cout << "Input = 1.0 " << my_neuron.feedForward(1.0) << std::endl;
        my_neuron.propBackward(4.0);

        std::cout << "w = " << my_neuron.w_ << " b = " << my_neuron.b_ << std::endl;
    }
}
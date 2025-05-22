#pragma once

class MyFunction // linear hypothesis
{
public:
	double a_, b_;

	MyFunction() : a_(0.0), b_(0.0) {}

	float getValue(const double& x)
	{
		return a_ * x + b_;
	}
};
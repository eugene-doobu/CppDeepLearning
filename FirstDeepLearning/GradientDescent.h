#pragma once
#include <iostream>

#include "MyFunction.h"

class GradientDescent
{
public:
	void operator()()
	{
		MyFunction mf;

		const int num_const = 3;

		// Mean Squared Error
		const double y_t[num_const] = { 1.0f, 1.5f, 2.0f };
		const double x[num_const] = { 0.0f, 0.5f, 1.0f };

		const double alpha = 0.01;

		for (int i=0; i< 200; ++i)
		{
			double sqr_error_sum = 0.0;
			double Ea_sum = 0.0;
			double Eb_sum = 0.0;

			// Stochastic Gradient Descent Method
			/*
			 * int c = rand & num_const;
			 * use random index, does not foreach all elements.
			 */

			for (int c=0; c< num_const; ++c)
			{
				const double error = y_t[c] - mf.getValue(x[c]);
				const double Ea = error * -x[c];
				const double Eb = error * -1;

				sqr_error_sum += error * error;
				Ea_sum += Ea;
				Eb_sum += Eb;
			}

			if (i % 10 == 0)
				std::cout << "Squared Error = " << 0.5 * sqr_error_sum << std::endl;

			mf.a_ -= alpha * Ea_sum / static_cast<double>(num_const);
			mf.b_ -= alpha * Eb_sum / static_cast<double>(num_const);
		}
	}
};


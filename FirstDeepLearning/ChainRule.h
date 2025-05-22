#pragma once
#include <iostream>

#include "MyFunction.h"

class ChainRule
{
public:
	void operator()()
	{
		MyFunction mf, mg;

		mf.a_ = static_cast<double>(rand()) / RAND_MAX;
		mf.b_ = static_cast<double>(rand()) / RAND_MAX;
		mg.a_ = static_cast<double>(rand()) / RAND_MAX;
		mg.a_ = static_cast<double>(rand()) / RAND_MAX;

		const double y_t0 = 1.0;
		const double x_0 = 0.0;

		const double alpha = 0.01;

		std::cout << "Before training y = " << mf.getValue(mg.getValue(x_0)) << std::endl;

		for (int i=0; i<1000; ++i)
		{
			const double error = y_t0 - mf.getValue(mg.getValue(x_0));
			const double sqr_error = 0.5 * error * error;

			if (i % 100 == 0)
				std::cout << "Squared Error = " << sqr_error << std::endl;

			if (sqr_error < 1e-5) break;

			const double Eaf = -error * mg.getValue(x_0);
			const double Ebf = -error * 1.0;

			const double Eag = -error * mf.a_ * x_0;
			const double Ebg = -error * mf.a_ * 1.0;

			mf.a_ -= alpha * Eaf;
			mf.b_ -= alpha * Ebf;

			mg.a_ -= alpha * Eag;
			mg.b_ -= alpha * Ebg;
		}

		std::cout << "After training y = " << mf.getValue(mg.getValue(x_0)) << std::endl;
	}
};

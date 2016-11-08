// RNG_sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <vector>
//#include <thread>

const int min = 0.0;
const int max = 1.0;
const int num_samples = 100000;
const int num_threads = 2;
const int seed = 1234;


int main()
{
	std::vector<double> rns;
	rns.reserve(num_samples);

	std::random_device rd;
	std::mt19937 main_gen(rd());

	std::uniform_real_distribution<> distr(min, max);

	for (int i = 0; i != num_samples; ++i)
	{
		rns.push_back(distr(main_gen));
	}

	for (int i = 0; i != 10; i++)
	{
		std::cout << rns.at(i) << "\n";
	}

    return 0;
}
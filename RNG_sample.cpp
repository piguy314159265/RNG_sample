// RNG_sample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <vector>
#include <thread>

const unsigned int initial_seed = 1234;

const int min = 0.0;
const int max = 1.0;
const int num_samples = 10;
const int num_threads = 2;

void print_rns(unsigned int seed, unsigned int n)
{
	std::mt19937_64 thread_gen(seed);
	std::uniform_real_distribution<> thread_dist(min, max);

	for (int i = 0; i != n; ++i)
	{
		std::cout << thread_dist(thread_gen) << "\n";
	}
}

int main()
{
	//std::random_device rd; could use this to seed main_gen if non-deterministic is desired
	std::mt19937_64 main_gen(initial_seed);
	
	std::uniform_int_distribution<> seed_dist(0, 2147483647);

	// generate seeds
	int seeds[num_threads];
	for (int i = 0; i != num_threads; ++i)
	{
		seeds[i] = seed_dist(main_gen);
	}

	// run threads
	std::thread threads[num_threads];
	for (int i = 0; i != num_threads; ++i)
	{
		threads[i] = std::thread(print_rns, seeds[i], num_samples/num_threads);
	}

	// join threads
	for (int i = 0; i != num_threads; ++i)
	{
		threads[i].join();
	}

    return 0;
}
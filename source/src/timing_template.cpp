/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include "searching.h"

int main( void )
{

    std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";
    //================================================================================

    unsigned int size = 10000;
    unsigned int maximum = 10000000;
    std::ofstream tim( "tempos-recursivo-B.txt" );
    
    int quantityRepetitions = 30; // number of tests of each array size in each function to find the average
    double sum = 0; // sum of the number of times of each size, repetition values

    while (size < maximum){ // The loop continues until reaching the maximum value.
        std::vector<int>vetor(size);
        std::fill(vetor.begin(), vetor.end(), 0); // Fills the vector with the value 0

        sum = 0;

        for(int i = 0; i < quantityRepetitions; i++){

            auto start = std::chrono::steady_clock::now();
            sa::brsearch( vetor.data(), &vetor.back(), -1 ); // data: A pointer to the first element in the array used internally by the vector.
            // back: A pointer to the last element in the array used internally by the vector.

            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

            //Store the time difference between start and end
            // auto diff = end - start;
            std::chrono::duration<double, std::milli> diff = end - start;
            sum+= (diff).count();

        }
        
        tim << size << "\t" << sum/quantityRepetitions << std::endl;
        size += 20000;

    }
    
    //================================================================================
    // auto end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";

    // //Store the time difference between start and end
    // // auto diff = end - start;
    // std::chrono::duration<double> diff = end - start;

    // // Milliseconds (10^-3)
    // std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
    //     << " ms" << std::endl;

    // // Nanoseconds (10^-9)
    // std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
    //     << " ns" << std::endl;

    // // Seconds
    // auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    // std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;

    return EXIT_SUCCESS;
}

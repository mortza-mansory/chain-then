#include "chain.h"

int main() {
    chain::start()
        .then([]() {
            std::cout << "First function is completed.\n";
            return 0; 
        })
        .then([]() {
            std::cout << "Second is completed. \n";
            return 0; 
        })
        .then([]() {
            std::cout << "Third is having error...\n";
            return -1; 
        })
        .then([]() {
            std::cout << "Furth is completed.\n";
            return 0;
        })
        .execute(); 

    return 0;
}

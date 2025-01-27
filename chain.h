#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <vector>
#include <functional>

namespace chain {

    class Executor {
    private:
        std::vector<std::function<int()>> tasks; 

    public:
        Executor& then(std::function<int()> func) {
            tasks.push_back(func);
            return *this;
        }

        void execute() {
            for (auto& task : tasks) {
                int result = task(); 
                if (result != 0) {   
                    std::cerr << "Error from chain: " << result << std::endl;
                    return; 
                }
            }
          //  std::cout << "The task completes." << std::endl;
        }
    };
//A function for STARTING the chains.
    inline Executor start() {
        return Executor();
    }

} // namespace chain

#endif // CHAIN_H

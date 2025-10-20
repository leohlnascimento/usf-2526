#include <iostream>
#include <vector>
#include <algorithm>

// Utility to print a vector
void print_vector(const std::vector<int>& vec){
    for(int n : vec) std::cout << n << " ";
    std::cout << "\n";
}

// Using lambda with transform
void demo_lambda_transform(std::vector<int>& nums, int multiplier){
    std::cout << "\n--- Lambda + Transform Walkthrough ---\n";
    std::cout << "Original numbers: ";
    print_vector(nums);

    std::transform(nums.begin(), nums.end(), nums.begin(), // iterate from begin to end, putting new values in begin again
        [multiplier](int n) -> int {
            std::cout << "Multiplying " << n << " by " << multiplier << "\n";
            return(n * multiplier);
        }); // square braces form a CLOSURE -> we are grabbing the value of multiplier, not passing it.
//We're grabbing it from the outer scope of the demo_lambda_transform function

    std::cout << "After multiplying by " << multiplier << ": ";
    print_vector(nums);
}

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int multiplier = 3;
    demo_lambda_transform(nums, multiplier);
    return(0);
}
// include the necessary header files
#include <bitset>
#include <cstdint>
#include <iostream>

// define the ALU class
class ALU
{
    public:
        enum Operation
        {
            AND,
            OR,
            XOR,
            ADD,
            SUBSTRACT
        };

        static std::bitset<8> execute(Operation op, std::bitset<8> a, std::bitset<8> b)
        {
            switch (op)
            {
                case AND:
                    return a & b;
                case OR:
                    return a | b;
                case XOR:
                    return a ^ b;
                case ADD:
                    return a + b;
                case SUBSTRACT:
                    return a - b;
                default:
                    return std::bitset<8>();
            }
        }
};

// main function
int main()
{
    std::bitset<8> a(12);   // 1100
    std::bitset<8> b(5);    // 0101

    std::bitset<8> result = ALU::execute(ALU::AND, a, b);
    std::cout << result << std::endl;   // 0100

    result = ALU::execute(ALU::OR, a, b);
    std::cout << result << std::endl;   // 1101

    result = ALU::execute(ALU::XOR, a, b);
    std::cout << result << std::endl;   // 1001

    result = ALU::execute(ALU::ADD, a, b);
    std::cout << result << std::endl;   // 0001

    result = ALU::execute(ALU::SUBSTRACT, a, b);
    std::cout << result << std::endl;   // 1011

    return 0;
}
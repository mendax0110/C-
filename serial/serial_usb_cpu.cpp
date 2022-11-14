// include the libraries
#include "cpu.hpp"
#include "util.hpp"
#include "example/turing_machine.hpp"

// main function
int main()
{
    // create cpu, turing machine and serial
    using result = CPU < turing_machine > :: run;
    using printer = printer < result :: reg, result :: mem >;

    if constexpr(result::is_breakpoint)
    {
        std::cout << "Stopped at breakpoint (pc =" << result::pc << ")" << std::endl;
    }

    // print the registers and memory
    std::cout << "Executed " << result::instr_count << "instructions\n" << std::endl;
    std::cout << "Registers:\n" << printer::reg() << std::endl;
    printer::reg();

    // print the memory
    std::cout << "Memory:\n" << printer::mem() << std::endl;
    printer::mem();

    return 0;
}
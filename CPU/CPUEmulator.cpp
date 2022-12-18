// include the libraries we need
#include <iostream>
#include <cstring>

// define the number of registers
const int NUM_REGISTERS = 8;

// define the instructions
std::string instructions[] = {
    "MOV R0, #10",
    "MOV R1, #20",
    "ADD R2, R0, R1",
    "SUB R3, R1, R0",
    "MUL R4, R0, R1",
    "DIV R5, R1, R0",
    "AND R6, R0, R1",
    "OR R7, R0, R1",
    "HALT"
};

// define the registers
int registers[NUM_REGISTERS];

// define the memory
void execute_instruction(std::string instruction) {
    std::string delimiter = " ";
    size_t pos = instruction.find(delimiter);
    std::string operation = instruction.substr(0, pos);

   
    if (operation == "MOV") 
    {
        // MOV R0, #10
        int value, destination;
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string destination_str = instruction.substr(0, pos);
        sscanf(destination_str.c_str(), "R%d", &destination);
        instruction.erase(0, pos + delimiter.length());
        sscanf(instruction.c_str(), "#%d", &value);
        registers[destination] = value;
    } 
    else if (operation == "ADD") 
    {
        // ADD R2, R0, R1
        int source1, source2, destination;
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string destination_str = instruction.substr(0, pos);
        sscanf(destination_str.c_str(), "R%d", &destination);
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string source1_str = instruction.substr(0, pos);
        sscanf(source1_str.c_str(), "R%d", &source1);
        instruction.erase(0, pos + delimiter.length());
        sscanf(instruction.c_str(), "R%d", &source2);
        registers[destination] = registers[source1] + registers[source2];
    } 
    else if (operation == "SUB") 
    {
        // SUB R3, R1, R0
        int source1, source2, destination;
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string destination_str = instruction.substr(0, pos);
        sscanf(destination_str.c_str(), "R%d", &destination);
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string source1_str = instruction.substr(0, pos);
        sscanf(source1_str.c_str(), "R%d", &source1);
        instruction.erase(0, pos + delimiter.length());
        sscanf(instruction.c_str(), "R%d", &source2);
        registers[destination] = registers[source1] - registers[source2];
    } 
    else if (operation == "MUL")
    {
        // MUL R4, R0, R1
        int source1, source2, destination;
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string destination_str = instruction.substr(0, pos);
        sscanf(destination_str.c_str(), "R%d", &destination);
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string source1_str = instruction.substr(0, pos);
        sscanf(source1_str.c_str(), "R%d", &source1);
        instruction.erase(0, pos + delimiter.length());
        sscanf(instruction.c_str(), "R%d", &source2);
        registers[destination] = registers[source1] * registers[source2];
    } 
    else if (operation == "DIV") 
    {
        // DIV R5, R1, R0
        int source1, source2, destination;
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string destination_str = instruction.substr(0, pos);
        sscanf(destination_str.c_str(), "R%d", &destination);
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string source1_str = instruction.substr(0, pos);
        sscanf(source1_str.c_str(), "R%d", &source1);
        instruction.erase(0, pos + delimiter.length());
        sscanf(instruction.c_str(), "R%d", &source2);
        registers[destination] = registers[source1] / registers[source2];
    } 
    else if (operation == "AND") 
    {   
        // AND R6, R0, R1
        int source1, source2, destination;
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string destination_str = instruction.substr(0, pos);
        sscanf(destination_str.c_str(), "R%d", &destination);
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string source1_str = instruction.substr(0, pos);
        sscanf(source1_str.c_str(), "R%d", &source1);
        instruction.erase(0, pos + delimiter.length());
        sscanf(instruction.c_str(), "R%d", &source2);
        registers[destination] = registers[source1] & registers[source2];
    } 
    else if (operation == "OR") 
    {
        // OR R7, R0, R1
        int source1, source2, destination;
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string destination_str = instruction.substr(0, pos);
        sscanf(destination_str.c_str(), "R%d", &destination);
        instruction.erase(0, pos + delimiter.length());
        pos = instruction.find(delimiter);
        std::string source1_str = instruction.substr(0, pos);
        sscanf(source1_str.c_str(), "R%d", &source1);
        instruction.erase(0, pos + delimiter.length());
        sscanf(instruction.c_str(), "R%d", &source2);
        registers[destination] = registers[source1] | registers[source2];
    } 
    else if (operation == "HALT") 
    {
        // print registers
        for (int i = 0; i < 32; i++) 
        {
            std::cout << "R" << i << ": " << registers[i] << std::endl;
        }
        exit(0);
    }
}
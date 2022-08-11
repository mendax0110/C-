/*include the library*/
#include <stdio.h>

typedef unsigned char BYTE;     /*Define 8-bit unsigned number*/
typedef unsigned char NIBBLE;   /*Define 4-bit unsigned number*/

/*define the OPCODE structure*/
#define OPCODE_NOP  0x00
#define OPCODE_LDI  0x01
#define OPCODE_LDD  0x02
#define OPCODE_ST   0x03
#define OPCODE_ADD  0x04
#define OPCODE_SUB  0x05
#define OPCODE_CMP  0x06
#define OPCODE_JMP  0x07
#define OPCODE_JZ   0x08
#define OPCODE_JN   0x09
#define OPCODE_JC   0x0A
#define OPCODE_JSR  0x0B
#define OPCODE_RET  0x0C
#define OPCODE_IN   0x0D
#define OPCODE_OUT  0x0E
#define OPCODE_RTI  0x0F

/*define the flags structure*/
#define Z_FLAG  0x08
#define N_FLAG  0x04
#define C_FLAG  0x02

/*define the registers structure*/
NIBBLE Accumulator;                 /*4-bit Register*/
NIBBLE Status;
BYTE   ProgramCounter;              /*8-bit Register*/ 
BYTE   StackPointer;                

/*define the memory structure*/
NIBBLE Memory[256]
{
    OPCODE_NOP,
    OPCODE_LDI,
    OPCODE_LDD,
    OPCODE_ST,
};

/*ports*/
NIBBLE InputPort    [16];
NIBBLE OutputPort   [16];

/*define the functions*/
void clear_carry_flag()
{
    Status = Status & ~C_FLAG;
}

/*make the carry flag bit(position) on the Status 0,
 *without affecting other bits on the status
 */
void set_carry_flag(NIBBLE data)
{
    if((data & 0x10) == 0x10)
    {
        Status = Status | C_FLAG;
    }
    else
    {
        Status = Status & ~C_FLAG;
    }
}

/*sets the negative bit*/
void set_negative_flag()
{
    if((Accumulator & 0x08) == 0x08)
    {
        Status = Status | N_FLAG;
    }
    else
    {
        Status = Status & ~N_FLAG;
    }
}

/*sets the zero flag if accumulator value is zero,
 *otherwise, set the zero flag bit 0 without affecting other bits on the status
 */
void set_zero_flag()
{
    if(Accumulator == 0)
    {
        Status = Status | Z_FLAG;
    }
    else
    {
        Status = Status & ~Z_FLAG;
    }
}

/*verify if the carry flag is cleared after clear_carry_flag() is executed*/
char test_clear_carry_flag()
{
    Status = 0x02;
    /*print the status register before clear the carry flag*/
    printf("Before clearing carry flag, Status is: %04X", Status);
    printf("\n");
    clear_carry_flag();
    /*print the status register after clear the carry flag*/
    printf("After clearing carry flag, Status is: %04X", Status);

    return 0;
}

/*add function banner here*/
char fetch()
{
    NIBBLE instruction_nibble;

    instruction_nibble = Memory[ProgramCounter];
    ProgramCounter++;

    return instruction_nibble;
}

/*put function banner here*/
void execute(NIBBLE opcode)
{
    NIBBLE high_nibble;
    NIBBLE low_nibble;
    BYTE   address;

    /*decode using a switch statement*/
    switch(opcode)
    {
        case OPCODE_NOP:
            printf("OPCODE_NOP has been executed.\n");
            break;

        case OPCODE_LDI:
            Accumulator = fetch();
            clear_carry_flag();
            set_negative_flag();
            set_zero_flag();
            printf("OPCODE_LDI has been executed.\n");
            break;

        case OPCODE_LDD:
            high_nibble = fetch();
            low_nibble  = fetch();
            address     = (high_nibble << 4) + low_nibble;
            Accumulator = Memory[address];
            clear_carry_flag();
            set_negative_flag();
            set_zero_flag();
            break;

        case OPCODE_ST:
            high_nibble = fetch();
            low_nibble  = fetch();
            address     = (high_nibble << 4) + low_nibble;
            Memory[address] = Accumulator;
            break;

        default:
            printf("OPCODE_%02X has been executed.\n", opcode);
            break;
    }
}

/*main function*/
int main()
{
    int sanity;
    NIBBLE opcode;

    printf("CSA 4-bit CPU emulator\n");

    /*initialize the registers*/
    Accumulator     = 0;
    Status          = 0;
    ProgramCounter  = 0;
    StackPointer    = 0xFB;

    /*main fetch/decode/execute loop*/
    sanity = 0;

    while(sanity < 3)
    {
        opcode = fetch();
        execute(opcode);
        sanity++;
    }

    printf("%1X ", Accumulator);
    if((Status & Z_FLAG) == Z_FLAG) printf("1 "); else printf("0 "); /*print the zero flag bit*/
    if((Status & N_FLAG) == N_FLAG) printf("1 "); else printf("0 "); /*print the negative flag bit*/
    if((Status & C_FLAG) == C_FLAG) printf("1 "); else printf("0 "); /*print the carry flag bit*/

    printf("%02X ", ProgramCounter);    /*print the program counter*/
    printf("%02X ", StackPointer);      /*print the stack pointer*/
    printf("\n");
}
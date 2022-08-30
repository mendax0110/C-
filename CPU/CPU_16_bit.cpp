/*include the header file*/
#include <iostream>
#include <unistd.h>

const int millisecondsPerInstruction = 50;

/*two functions setting and reading flags*/
uint16_t getbit(uint16_t num, int bitpos)
{
    uint16_t mask = 1 << bitpos;
    return(num & mask);
}

/*set the bit*/
void setbit(uint16_t & num, int bitpos, bool set)
{
    uint16_t mask = 1 << bitpos;

    if(set)
    {
        num |= mask;
    }
    else
    {
        num &= ~mask;
    }
}

/*function for interperting the nibbles of the uint_16_t*/
uint16_t getNibble1(uint16_t num)
{
    return(num >> 12);
}

uint16_t getNibble2(uint16_t num)
{
    return(num >> 8) & 0x000F;
}

uint16_t getNibble3(uint16_t num)
{
    return(num >> 4) & 0x000F;
}

uint16_t getNibble4(uint16_t num)
{
    return(num & 0x000F);
}

/*the ROM where the programs code will be in*/
uint16_t ROM[0xFFFF];

/*the RAM where the program can read and write*/
uint16_t RAM[0xFFFF];

/*the registers*/
uint16_t reg[5] = {0};

bool halt = false;

void runInstruction(uint16_t instruction, uint16_t address)
{
    uint16_t n1, n2, n3, n4;

    /*opcode*/
    n1 = getNibble1(instruction);
    n2 = getNibble2(instruction);
    n3 = getNibble3(instruction);
    n4 = getNibble4(instruction);

    /*program counter increment*/
    reg[0] += 2;

    switch(n1)
    {
        /*add*/
        case 0x0:
            reg[n4] = reg[n2] + reg[n3];
            break;

        /*cmp*/
        case 0x5:
            setbit(reg[1], 0, 0);
            setbit(reg[1], 1, 0);
            setbit(reg[1], 2, 0);

            if(reg[n2] > reg[n3])
            {
                setbit(reg[1], 0, 1);
            }
            else if(reg[n2] == reg[n3])
            {
                setbit(reg[1], 1, 1);
            }
            else if(reg[n2] < reg[n3])
            {
                setbit(reg[1], 2, 1);
            }
            break;

        /*cpy*/
        case 0x6:
            reg[n3] = reg[n2];
            break;

        /*out*/
        case 0x7:
            std::cout << reg[n2] << std::endl;
            break;

        /*ldv*/
        case 0xA:
            reg[n2] = address;
            break;

        /*j*/
        case 0xE:

            if(!n2)
            {
                if(!getbit(reg[1], n3)) reg[0] = address;
            }
            else if(n2 == 1)
            {
                if(getbit(reg[1], n3)) reg[0] = address;
            }
            else
            {
                reg[0] = address;
            }
            break;

            /*undefined instruction are hlt*/
        default:
            halt = true;
            break;
    }
}

/*main function*/
int main()
{
    /*initialize the ROM*/
    for(int i = 0; i < 0xFFFF; i++)
    {
        ROM[i] = 0xFFFF;
    }

    /*assembly code to generate the sequences*/
    ROM[0] = 0xA200;
    ROM[1] = 0x0000;
    ROM[2] = 0xA300;
    ROM[3] = 0x0001;
    ROM[4] = 0x0234;
    ROM[5] = 0x0000;
    ROM[6] = 0x7400;
    ROM[7] = 0x0000;
    ROM[8] = 0x6320;
    ROM[9] = 0x0000;
    ROM[10] = 0x6430;
    ROM[11] = 0x0000;
    ROM[12] = 0x0234;
    ROM[13] = 0x0000;
    ROM[14] = 0x5430;
    ROM[15] = 0x0000;
    ROM[16] = 0xE100;
    ROM[17] = 0x0006;

    while(!halt)
    {
        runInstruction(ROM[reg[0]], ROM[reg[0] + 1]);
        usleep(millisecondsPerInstruction * 1000);
    }

    return 0;
}
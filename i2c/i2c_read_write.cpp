// include the header file
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

// class for the i2c bus
class i2cReadWrite
{
    public:
    int file_i2c;
    unsigned char buffer[60];
    int length = 2;

    void setup(char * id)
    {
        char *filename = id;
        if ((file_i2c = open(filename, O_RDWR)) < 0)
        {
            // print error for failed i2c bus
            printf("Failed to open i2c bus");
            return;
        }

        int addr = 0x5a;
        if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
        {
            // print error for false slave communication
            printf("Failed to acquire bus access and/or talk to slave.\n");
            return;
        }
    }

    string readi2cData()
    {
        if (read(file_i2c, buffer, length) != length)
        {
            // print error for failed read
            printf("Failed to read from the i2c bus.\n");
        }
        else
        {
            // print the data read
            printf("Data read: %s\n", buffer);
        }
        return res;
    }

    void writeBytes()
    {
        buffer[0] = 0x01;
        buffer[1] = 0x02;
        if (write(file_i2c, bufferm length) != length)
        {
            // print error for failed write
            printf("Failed to write to the i2c bus.\n");
        }
    }
};

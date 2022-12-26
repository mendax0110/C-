#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

// Function to list the available COM ports
std::vector<std::string> listCOMPorts() 
{
  std::vector<std::string> comPorts;

  DIR* dir = opendir("/dev");
  if (dir) 
  {
    struct dirent* ent;
    
    while ((ent = readdir(dir)) != NULL) 
    {
      if (ent->d_name[0] == 'c' && ent->d_name[1] == 'o' && ent->d_name[2] == 'm') 
      {
        comPorts.push_back(std::string("/dev/") + ent->d_name);
      }
    }
    closedir(dir);
  }

  return comPorts;
}

// Function to configure the serial port
void configureSerialPort(int fd) 
{
  struct termios tty;
  memset(&tty, 0, sizeof tty);

  // Set the baud rate
  cfsetospeed(&tty, B9600);
  cfsetispeed(&tty, B9600);

  // Set the configuration options
  tty.c_cflag &= ~PARENB; // No parity
  tty.c_cflag &= ~CSTOPB; // 1 stop bit
  tty.c_cflag |= CS8; // 8 data bits
  tty.c_cflag &= ~CRTSCTS; // No hardware flow control
  tty.c_cflag |= CREAD | CLOCAL; // Enable receiver and set local mode
  tty.c_lflag &= ~ICANON; // Disable canonical mode
  tty.c_lflag &= ~ECHO; // Disable echoing of typed characters
  tty.c_lflag &= ~ECHOE; // Disable echoing of erasing characters
  tty.c_lflag &= ~ECHONL; // Disable newline echoing
  tty.c_lflag &= ~ISIG; // Disable generation of signals
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Disable software flow control
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable special handling of CR, NL, and BREAK
  tty.c_oflag &= ~OPOST; // Disable all output processing

  // Set the timeout options
  tty.c_cc[VMIN] = 0;
  tty.c_cc[VTIME] = 10;

  // Save the configuration
  tcsetattr(fd, TCSANOW, &tty);
}

int main() 
{
    // List the available COM ports
    std::vector<std::string> comPorts = listCOMPorts();

    // Check if any COM ports were found
    if (comPorts.empty()) #
    {
        std::cerr << "No COM ports found" << std::endl;
        return 1;
    }
     
    // Print the available COM ports
    std::cout << "Available COM ports:" << std::endl;
    for (std::vector<std::string>::iterator it = comPorts.begin(); it != comPorts.end(); ++it) 
    {
        std::cout << *it << std::endl;
    }

    // Open the serial port
    int fd = open(comPorts[0].c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) 
    {
        std::cerr << "Error opening " << comPorts[0] << std::endl;
        return 1;
    }

    // Configure the serial port
    configureSerialPort(fd);

    // Close the serial port
    close(fd);

    return 0;
}

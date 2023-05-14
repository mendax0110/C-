#include <iostream>
#include <cstdlib>
#include <stdexcept>

class OhmsLaw
{
public:
  // Get the instance of the OhmsLaw class
  static OhmsLaw& getInstance()
  {
    static OhmsLaw instance;
    return instance;
  }

  // Calculate voltage based on current and resistance
  double calculateVoltage(double current, double resistance)
  {
    if (resistance == 0)
    {
      throw std::invalid_argument("Resistance cannot be zero");
    }
    return current * resistance;
  }

  // Calculate current based on voltage and resistance
  double calculateCurrent(double voltage, double resistance)
  {
    if (resistance == 0)
    {
      throw std::invalid_argument("Resistance cannot be zero");
    }
    return voltage / resistance;
  }

  // Calculate resistance based on voltage and current
  double calculateResistance(double voltage, double current)
  {
    if (current == 0)
    {
      throw std::invalid_argument("Current cannot be zero");
    }
    return voltage / current;
  }

private:
  // Private constructor to prevent instantiation of the class
  OhmsLaw() {}
};

int main(int argc, char* argv[])
{
  // Check that the user has provided the correct number of arguments
  if (argc != 4)
  {
    std::cerr << "Usage: " << argv[0] << " current resistance voltage" << std::endl;
    return EXIT_FAILURE;
  }

  // Parse the input values from the command line arguments
  double current = 0.0;
  double resistance = 0.0;
  double voltage = 0.0;
  try
  {
    current = std::stod(argv[1]);
    resistance = std::stod(argv[2]);
    voltage = std::stod(argv[3]);
  }
  catch (const std::invalid_argument& ex)
  {
    std::cerr << "Invalid input value: " << ex.what() << std::endl;
    return EXIT_FAILURE;
  }

  // Get the instance of the OhmsLaw class
  OhmsLaw& ohmsLaw = OhmsLaw::getInstance();

  // Calculate voltage given current and resistance
  if (current != 0 && resistance != 0)
  {
    try
    {
      voltage = ohmsLaw.calculateVoltage(current, resistance);
      std::cout << "Voltage: " << voltage << " V" << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
      std::cerr << "Error: " << ex.what() << std::endl;
      return EXIT_FAILURE;
    }
  }

  // Calculate current given voltage and resistance
  if (voltage != 0 && resistance != 0)
  {
    try
    {
      current = ohmsLaw.calculateCurrent(voltage, resistance);
      std::cout << "Current: " << current << " A" << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
      std::cerr << "Error: " << ex.what() << std::endl;
      return EXIT_FAILURE;
    }
  }

  // Calculate resistance given voltage and current
  if (voltage != 0 && current != 0)
  {
    try
    {
      resistance = ohmsLaw.calculateResistance(voltage, current);
      std::cout << "Resistance: " << resistance << " Ohms" << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
      std::cerr << "Error: " << ex.what() << std::endl;
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}
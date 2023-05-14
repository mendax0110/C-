#include <iostream>
#include <memory>
#include <stdexcept>

// Define the interface for the OhmsLawCalculator class
class IOhmsLawCalculator
{
public:
  virtual double calculate(double voltage, double current, double resistance) = 0;
};

// Implement the OhmsLawCalculator class
class VoltageCalculator : public IOhmsLawCalculator
{
public:
  double calculate(double voltage, double current, double resistance) override
  {
    return voltage;
  }
};

class CurrentCalculator : public IOhmsLawCalculator
{
public:
  double calculate(double voltage, double current, double resistance) override
  {
    return current;
  }
};

class ResistanceCalculator : public IOhmsLawCalculator
{
public:
  double calculate(double voltage, double current, double resistance) override
  {
    return resistance;
  }
};

// Define the interface for the ElectricalDevice class
class IElectricalDevice
{
public:
  virtual double getValue(IOhmsLawCalculator& calculator) = 0;
};

// Implement the ElectricalDevice class
class ElectricalDevice : public IElectricalDevice
{
public:
  ElectricalDevice(double voltage, double current) : voltage_(voltage), current_(current) {}

  double getValue(IOhmsLawCalculator& calculator) override
  {
    return calculator.calculate(voltage_, current_, voltage_ / current_);
  }

private:
  double voltage_;
  double current_;
};

int main(int argc, char* argv[])
{
  // Check that the correct number of arguments have been provided
  if (argc != 3)
  {
    std::cerr << "Usage: " << argv[0] << " <voltage> <current>" << std::endl;
    return 1;
  }

  // Parse the input values
  double voltage, current;
  try
  {
    voltage = std::stod(argv[1]);
    current = std::stod(argv[2]);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Invalid input argument: " << e.what() << std::endl;
    return 1;
  }

  // Create an instance of the ElectricalDevice class with the provided voltage and current
  std::unique_ptr<IElectricalDevice> device = std::make_unique<ElectricalDevice>(voltage, current);

  // Create instances of the VoltageCalculator, CurrentCalculator, and ResistanceCalculator classes
  VoltageCalculator voltageCalculator;
  CurrentCalculator currentCalculator;
  ResistanceCalculator resistanceCalculator;

  // Prompt the user to select a calculation to perform
  std::cout << "Select a calculation to perform:" << std::endl;
  std::cout << "1. Calculate voltage" << std::endl;
  std::cout << "2. Calculate current" << std::endl;
  std::cout << "3. Calculate resistance" << std::endl;
  int selection;
  std::cin >> selection;

  // Perform the selected calculation using the device's value and the appropriate calculator object
  double result;
  switch (selection)
  {
    case 1:
      result = device->getValue(voltageCalculator);
      std::cout << "Voltage: " << result << " V" << std::endl;
      break;
    case 2:
      result = device->getValue(currentCalculator);
      std::cout << "Current: " << result << " A" << std::endl;
      break;
    case 3:
      result = device->getValue(resistanceCalculator);
      std::cout << "Resistance: " << result << " Ohms" << std::endl;
      break;
    default:
      std::cerr << "Invalid selection" << std::endl;
      return 1;
  }

  return 0;
}
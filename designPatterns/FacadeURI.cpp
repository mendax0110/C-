#include <iostream>
#include <memory>
#include <stdexcept>

// Define the interface for the OhmsLawCalculator class
class IOhmsLawCalculator
{
public:
  virtual double calculateVoltage(double current, double resistance) = 0;
  virtual double calculateCurrent(double voltage, double resistance) = 0;
  virtual double calculateResistance(double voltage, double current) = 0;
};

// Implement the OhmsLawCalculator class
class OhmsLawCalculator : public IOhmsLawCalculator
{
public:
  double calculateVoltage(double current, double resistance) override
  {
    return current * resistance;
  }

  double calculateCurrent(double voltage, double resistance) override
  {
    return voltage / resistance;
  }

  double calculateResistance(double voltage, double current) override
  {
    return voltage / current;
  }
};

// Define the interface for the ElectricalDevice class
class IElectricalDevice
{
public:
  virtual double getVoltage() = 0;
  virtual double getCurrent() = 0;
  virtual double getResistance() = 0;
};

// Implement the ElectricalDevice class
class ElectricalDevice : public IElectricalDevice
{
public:
  ElectricalDevice(double voltage, double current) : voltage_(voltage), current_(current) {}

  double getVoltage() override
  {
    return voltage_;
  }

  double getCurrent() override
  {
    return current_;
  }

  double getResistance() override
  {
    return voltage_ / current_;
  }

private:
  double voltage_;
  double current_;
};

// Define the interface for the OhmsLawFacade class
class IOhmsLawFacade
{
public:
  virtual double calculateResistance(double voltage, double current) = 0;
  virtual double calculateVoltage(double current, double resistance) = 0;
  virtual double calculateCurrent(double voltage, double resistance) = 0;
};

// Implement the OhmsLawFacade class
class OhmsLawFacade : public IOhmsLawFacade
{
public:
  OhmsLawFacade(std::shared_ptr<IElectricalDevice> device, std::unique_ptr<IOhmsLawCalculator> calculator)
    : device_(device), calculator_(std::move(calculator)) {}

  double calculateResistance(double voltage, double current) override
  {
    return calculator_->calculateResistance(voltage, current);
  }

  double calculateVoltage(double current, double resistance) override
  {
    return calculator_->calculateVoltage(current, resistance);
  }

  double calculateCurrent(double voltage, double resistance) override
  {
    return calculator_->calculateCurrent(voltage, resistance);
  }

private:
  std::shared_ptr<IElectricalDevice> device_;
  std::unique_ptr<IOhmsLawCalculator> calculator_;
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
  std::shared_ptr<IElectricalDevice> device = std::make_shared<ElectricalDevice>(voltage, current);

  // Create an instance of the OhmsLawCalculator class
  std::unique_ptr<IOhmsLawCalculator> calculator = std::make_unique<OhmsLawCalculator>();

  // Create an instance of the OhmsLawFacade class that uses the ElectricalDevice and OhmsLawCalculator objects
  OhmsLawFacade facade(device, std::move(calculator));

  // Use the facade to calculate the resistance of the device and print the result to the console
  double resistance = facade.calculateResistance(voltage, current);
  std::cout << "Resistance: " << resistance << " Ohms" << std::endl;

  // Prompt the user to enter values for current and resistance, use the facade to calculate the voltage of the device, and print the result to the console
  double inputCurrent, inputResistance;
  std::cout << "Enter current: ";
  std::cin >> inputCurrent;
  std::cout << "Enter resistance: ";
  std::cin >> inputResistance;
  double voltageFromInput = facade.calculateVoltage(inputCurrent, inputResistance);
  std::cout << "Voltage: " << voltageFromInput << " V" << std::endl;

  // Prompt the user to enter a value for voltage, use the facade to calculate the current of the device, and print the result to the console
  double inputVoltage;
  std::cout << "Enter voltage: ";
  std::cin >> inputVoltage;
  double currentFromInput = facade.calculateCurrent(inputVoltage, resistance);
  std::cout << "Current: " << currentFromInput << " A" << std::endl;

  return 0;
}
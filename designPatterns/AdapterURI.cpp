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

// Define the adapter class that adapts the ElectricalDevice to the IOhmsLawCalculator interface
class ElectricalDeviceAdapter : public IOhmsLawCalculator
{
public:
  ElectricalDeviceAdapter(std::shared_ptr<IElectricalDevice> device) : device_(device) {}

  double calculateVoltage(double current, double resistance) override
  {
    return device_->getCurrent() * device_->getResistance();
  }

  double calculateCurrent(double voltage, double resistance) override
  {
    return device_->getVoltage() / device_->getResistance();
  }

  double calculateResistance(double voltage, double current) override
  {
    return device_->getVoltage() / device_->getCurrent();
  }

private:
  std::shared_ptr<IElectricalDevice> device_;
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

  // Create an ElectricalDevice with the provided voltage and current
  std::shared_ptr<IElectricalDevice> device = std::make_shared<ElectricalDevice>(voltage, current);

  // Create an adapter that adapts the ElectricalDevice to the IOhmsLawCalculator interface
  std::unique_ptr<IOhmsLawCalculator> adapter = std::make_unique<ElectricalDeviceAdapter>(device);

  // Use the adapter to calculate the resistance of the device
  double resistance = adapter->calculateResistance(device->getVoltage(), device->getCurrent());
  std::cout << "Resistance: " << resistance << " Ohms" << std::endl;

  // Use the adapter to calculate the voltage of the device given a current and resistance
  double inputCurrent, inputResistance;
  std::cout << "Enter current: ";
  std::cin >> inputCurrent;
  std::cout << "Enter resistance: ";
  std::cin >> inputResistance;
  double voltageFromInput = adapter->calculateVoltage(inputCurrent, inputResistance);
  std::cout << "Voltage: " << voltageFromInput << " V" << std::endl;

  // Use the adapter to calculate the current of the device given a voltage and resistance
  double inputVoltage;
  std::cout << "Enter voltage: ";
  std::cin >> inputVoltage;
  double currentFromInput = adapter->calculateCurrent(inputVoltage, resistance);
  std::cout << "Current: " << currentFromInput << " A" << std::endl;

  return 0;
}
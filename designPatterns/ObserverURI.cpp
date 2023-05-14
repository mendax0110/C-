#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

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
  virtual double getVoltage() = 0;
  virtual double getCurrent() = 0;
  virtual double getResistance() = 0;
  virtual void addObserver(IOhmsLawCalculator& calculator) = 0;
  virtual void removeObserver(IOhmsLawCalculator& calculator) = 0;
  virtual void notifyObservers() = 0;
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

  void addObserver(IOhmsLawCalculator& calculator) override
  {
    observers_.push_back(&calculator);
  }

  void removeObserver(IOhmsLawCalculator& calculator) override
  {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), &calculator), observers_.end());
  }

  void notifyObservers() override
  {
    for (auto observer : observers_)
    {
      observer->calculate(voltage_, current_, voltage_ / current_);
    }
  }

private:
  double voltage_;
  double current_;
  std::vector<IOhmsLawCalculator*> observers_;
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

  // Add the calculator objects as observers of the device
  device->addObserver(voltageCalculator);
  device->addObserver(currentCalculator);
  device->addObserver(resistanceCalculator);

  // Update the observers with the initial state of the device
  device->notifyObservers();

  // Prompt the user to enter a new voltage for the device
  std::cout << "Enter new voltage: ";
  std::cin >> voltage;

  // Update the device's voltage and notify the observers
  device = std::make_unique<ElectricalDevice>(voltage, current);
  device->notifyObservers();

  return 0;
}
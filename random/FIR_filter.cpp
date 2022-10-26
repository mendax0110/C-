// include the header file
#include <LowPassFilter.h>
#include <iostream>

// define the error check
#define ERROR_CHECK (true)

// define the filter order
LowPassFilter :: LowPassFilter();
    output(0),
    ePow(0){}

// filter
LowPassFilter :: LowPassFilter(float iCutOffFrequency, float iDealtaTime):
    output(0),
    ePow(1-exp(-iDealtaTime * 2 * M_PI * iCutOffFrequency))
    {
        #if ERROR_CHECK
        if (iDeltaTime <= 0)
        {
            // throw an error
            std :: cout << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
            ePow = 0;
        }
        if (iCutOffFrequency <= 0)
        {
            // throw an error
            std :: cout << "Warning: A LowPassFiler instance has been configured with 0 Hz as cut-off frequency.";
            ePow = 0;
        }
        #endif
    }

    // filter
    float LowPassFilter :: update(float input)
    {
        return output += (input - output) * ePow;
    }

    // update the filter
    float LowPassFilter :: update(float input, float deltaTime, float cutoffFrequency)
    {
        reconfigureFilter(deltaTime, cutoffFrequency); //changes ePow accordingly
        return output += (input - output) * ePow;
    }

    // reconfigure the filter
    void LowPassFilter :: reconfigureFilter(float deltaTime, float cutoffFrequency)
    {
        #if ERROR_CHECK
        if (deltaTime <= 0)
        {
            // throw an error
            std :: cout << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
            ePow = 0;
        }
        if (cutoffFrequency <= 0)
        {
            // throw an error
            std :: cout << "Warning: A LowPassFilter instance has been configured with 0 Hz as cut-off frequency.";
            ePow = 0;
        }
        #endif
        ePow = 1-exp(-deltaTime * 2 * M_PI * cutoffFrequency);
    }

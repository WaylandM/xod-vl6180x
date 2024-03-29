// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_VL6180X"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

//Include C++ libraries
#include <Adafruit_VL6180X.h>
#include <Wire.h>


node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_VL6180X*;
    }

    // Create an object of the class VL6180X
    Adafruit_VL6180X sensor = Adafruit_VL6180X();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        emitValue<output_DEV>(ctx, &sensor);
    }
}


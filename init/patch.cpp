#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_INIT

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulsei
        if (!isInputDirty<input_INIT>(ctx))
            return;

        // Get a pointer to the `Adafruit_VL6180X` class instance
        auto sensor = getValue<input_DEV>(ctx);

        auto wire = getValue<input_I2C>(ctx);

        // Attempt to initialize VL6180X module; if attempt fails emit error
        if (!sensor->begin(wire)) {
            raiseError(ctx);
            return;
        }

        // Pulse that module initialized successfully
        emitValue<output_OK>(ctx, 1);
    }
}

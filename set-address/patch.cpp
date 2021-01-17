
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        // Get a pointer to the `VL6180X` class instance
        auto sensor = getValue<input_DEV>(ctx);
        sensor->setAddress(getValue<input_ADDR>(ctx));
        emitValue<output_DONE>(ctx,1);
    }
}

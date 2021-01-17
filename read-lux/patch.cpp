
node {
     void evaluate(Context ctx) {
         // The node responds only if there is an input pulse
         if (!isInputDirty<input_UPD>(ctx))
             return;
         // Get a pointer to the `VL6180X` class instance
         auto sensor = getValue<input_DEV>(ctx);
         float lux = sensor->readLux(getValue<input_GAIN>(ctx));
         emitValue<output_LUX>(ctx,lux);
         emitValue<output_DONE>(ctx,1);
    }
}

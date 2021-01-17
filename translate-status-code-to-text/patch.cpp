
node {
    char str[24];
    CStringView view = CStringView(str);
    
    void evaluate(Context ctx) {
        uint8_t status = getValue<input_CODE>(ctx);
        
        if (status == 0) {
            view="No error";
        }
        else if  ((status >= 1) && (status <= 5)) {
            view="System error";
        }
        else if (status == 6) {
            view="ECE failure";
        }
        else if (status == 7) {
            view="No convergence";
        }
        else if (status == 8) {
            view="Ignoring range";
        }
        else if (status == 11) {
            view="Signal/Noise error";
        }
        else if (status == 12) {
            view="Raw reading underflow";
        }
        else if (status == 13) {
            view="Raw reading overflow";
        }
        else if (status == 14) {
            view="Range reading underflow";
        }
        else if (status == 15) {
            view="Range reading overflow";
        }
        else {
            view="Unknown code";
        }
        emitValue<output_TXT>(ctx, XString(&view));
    }
}

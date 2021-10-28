#include <iostream>
#include "TextFile.h"

int main() {
    TextFile text("./STARLINK/chirp_20210126_125700_003_out.dat");
    TextFile text2("./STARLINK/chirp_20210203_203200_003_out.dat");
    text.addFile(text2);
    text.saveFile("CoolName.dat");
}

#include "include/swaston_generator.h"
#include <stdio.h>

int main() {
    // output is valid only for utf-8 enabled systems, check
    // https://github.com/swaston-generators/SwastonConsole
    // for cross platform CLI input/output example
    printf("%s", generate_swaston("te ї st").c_str());
}

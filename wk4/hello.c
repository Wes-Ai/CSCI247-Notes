#include <unistd.h>

char* message = "Hello World\n";

int main() {
    write(1, message, 12);
    return 0;
}
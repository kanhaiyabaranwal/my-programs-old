* Program A */
/**
 * This class defines a method `copy` that takes input from
 * the standard input and copies it to the system standard
 * output.
 */
class Cat {
    /**
     * The `copy` method reads std::cin one byte at a time and
     * outputs it to std::cout. The method is a static method,
     * and is public. Returns nothing.
     * Any exceptions are ignored. 
     * parameter args is ignored.
     */
public:
    static void main (std::vector<std::string> &args) {
        char buffer[4096];              // declare a character buffer
        int bytesRead;                  // keeps track of bytes read
        try {
            do {
               // read from standard input
                std::cin.read(buffer, sizeof(buffer));
                bytesRead = std::cin.gcount();
                if (bytesRead) {
                    // write to standard output
                    std::cout.write(buffer, bytesRead);
                }
            } while (std::cin);
        } catch (...) {
            ;
        }
    }
}

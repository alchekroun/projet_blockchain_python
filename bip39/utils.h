#include <string>
#include <sstream>
#include <random>
#include <vector>
#include <algorithm>


using random_bytes_engine = std::independent_bits_engine<
    std::default_random_engine, CHAR_BIT, unsigned char>;

std::string generate_random_bytes(int length) {
        random_bytes_engine rbe;
        rbe.seed(time(nullptr));
        std::vector<unsigned char> data(length);
        std::generate(begin(data), end(data), std::ref(rbe));
        std::string result{};
        std::for_each(begin(data), end(data),
                [&result](unsigned char c) {
                        std::stringstream stream;
                        stream << std::hex << int(c);
                        result.append(stream.str());
                });

        return result;
}

const char* hex_char_to_bin(char c) {
	switch(toupper(c)) {
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'A': return "1010";
		case 'B': return "1011";
		case 'C': return "1100";
		case 'D': return "1101";
		case 'E': return "1110";
		case 'F': return "1111";
		default: break;
	}
}

std::string hex_str_to_bin_str(const std::string& hex) {
	std::string bin;
	for(unsigned i = 0; i != hex.length(); ++i) {
		bin += hex_char_to_bin(hex[i]);
	}
	return bin;
}

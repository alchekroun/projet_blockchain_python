#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <random>
#include <climits>
#include <functional>
#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "bip39.h"

std::vector<int> POSSIBLE_WORD_COUNT = {12, 15, 18, 21, 24};


using random_bytes_engine = std::independent_bits_engine<
    std::default_random_engine, CHAR_BIT, unsigned char>;

#include <iostream>

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


const char* hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
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
    }
}

std::string hex_str_to_bin_str(const std::string& hex)
{
    // TODO use a loop from <algorithm> or smth
    std::string bin;
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += hex_char_to_bin(hex[i]);
    return bin;
}


std::string Bip39::generate(int word_count) {
	if (std::find(begin(POSSIBLE_WORD_COUNT), end(POSSIBLE_WORD_COUNT), word_count) == end(POSSIBLE_WORD_COUNT)) {
		throw std::invalid_argument("The number of words wanted must be in [12, 15, 18, 21, 24] interval");
	}
	this->word_count = word_count;
	this->checksum = (this->word_count * 11) % 32;
	this->entropy_length = (this->word_count * 11) - this->checksum;

	std::string output = std::to_string(this->word_count) + " -> " + std::to_string(this->checksum) + " -> " + std::to_string(this->entropy_length);
	std::string result = generate_random_bytes(this->entropy_length);
	return hex_str_to_bin_str(result);
}

PYBIND11_MODULE(bip39, comp) {
    py::class_<Bip39>(comp, "Bip39")
        .def(py::init<const std::string &>(), py::arg("langage") = "en")
	.def("get_langage", &Bip39::get_langage)
	.def("set_langage", &Bip39::set_langage)
        .def("generate", &Bip39::generate);
}


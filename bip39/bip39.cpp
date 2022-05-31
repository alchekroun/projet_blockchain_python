#include <stdexcept>
#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "bip39.h"
#include "utils.h"

std::vector<int> POSSIBLE_WORD_COUNT = {12, 15, 18, 21, 24};


std::string Bip39::generate_entropy() const {
	std::string random_bytes_hex = generate_random_bytes(this->entropy_length);

	return hex_str_to_bin_str(random_bytes_hex);
}


std::string Bip39::generate_checksum(std::string& p) const {
	std::string result;

	// generate sha526 string

	// take checksum bits of the sha526 string

	// append it to the initial entropy

	return result;
}


std::string Bip39::generate(int word_count) {
	if (std::find(begin(POSSIBLE_WORD_COUNT), end(POSSIBLE_WORD_COUNT), word_count) == end(POSSIBLE_WORD_COUNT)) {
		throw std::invalid_argument("The number of words wanted must be in [12, 15, 18, 21, 24] interval");
	}
	this->word_count = word_count;
	this->checksum = (this->word_count * 11) % 32;
	this->entropy_length = (this->word_count * 11) - this->checksum;

	std::string output = std::to_string(this->word_count) + " -> " + std::to_string(this->checksum) + " -> " + std::to_string(this->entropy_length);

	return this->generate_entropy();
}


PYBIND11_MODULE(bip39, comp) {
    py::class_<Bip39>(comp, "Bip39")
        .def(py::init<const std::string &>(), py::arg("langage") = "en")
	.def("get_langage", &Bip39::get_langage)
	.def("set_langage", &Bip39::set_langage)
        .def("generate", &Bip39::generate);
}


#include <string>
#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "bip39.h"

std::string Bip39::generate(){
	return "egs";
}


PYBIND11_MODULE(bip39, comp) {
    py::class_<Bip39>(comp, "Bip39")
        .def(py::init<>())
        .def("generate", &Bip39::generate);
}


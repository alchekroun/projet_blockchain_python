#include <string>

class Bip39 {

std::string seed;

public:
	Bip39() = default;
	~Bip39() = default;

	std::string generate();
};

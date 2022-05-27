#include <string>

class Bip39 {

std::string seed_;
std::string langage_;

public:
	Bip39(std::string langage = "en") : langage_(langage) {};
	~Bip39() = default;

	std::string generate();

	// Getters setters
	std::string get_langage() const { return this->langage_; };
	void set_langage(std::string langage) { this->langage_ = langage; };
};

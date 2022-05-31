#include <string>

class Bip39 {

	std::string seed_;
	std::string langage_;

	int checksum;
	int word_count;
	int entropy_length;

	/**
	 * @brief Generate the initial random entropy
	 * @return String of the entropy converted to a binary buffer.
	 */
	std::string generate_entropy() const;

	/**
         * @brief Generate the checksum string and append it to the initial entropy
         * @return String of the entropy with the checksum added.
         */
	std::string generate_checksum(std::string& p) const;
	
	/**
         * @brief Generate the mnemonic sentence
         * @return String of the mnemonic sentence.
         */	
	std::string generate_mnemonic() const;

public:
	Bip39(std::string langage = "en") : langage_(langage) {};
	~Bip39() = default;

	/**
         * @brief Main function for generate a mnemonic sentence
	 * @param word_count Number of words, must be in [12, 15, 18, 21, 24]
         * @return String of the mnemonic sentence in the langage selected, by default "en";
         */
	std::string generate(int word_count);

	// Getters setters
	std::string get_langage() const { return this->langage_; };
	void set_langage(std::string langage) { this->langage_ = langage; };
};

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

struct basePairings {
    char APairing = 'T';
    char TPairing = 'A';
    char CPairing = 'G';
    char GPairing = 'C';
};

int main(int argc, char *argv []){

    basePairings basePairings;
    std::string sequence;
    std::string reverseSequence;
    std::string reverseComplement;
    reverseComplement = "";
    std::ifstream seqFile;

    std::string filepath;
    filepath = argv[1];
    seqFile.open(filepath);

    if(seqFile.is_open())
    {
        while(std::getline(seqFile, sequence))
        {
            std::reverse(sequence.begin(), sequence.end());
            for(int i = 0; i < sequence.length(); i++){
                char base;
                base = sequence[i];
                switch (base)
                {
                case 'A':
                    reverseComplement += basePairings.APairing;
                    break;
                case 'T':
                    reverseComplement += basePairings.TPairing;
                    break;
                case 'C':
                    reverseComplement += basePairings.CPairing;
                    break;
                case 'G':
                    reverseComplement += basePairings.GPairing;
                    break;
                default:
                    break;
                }
            }
        }
        seqFile.close();
        std::cout << "Reverse Complement: " << "\n";
        std::cout << reverseComplement;
    }


    return 0;
}
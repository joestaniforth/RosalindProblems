#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {

    std::string sequence;
    std::string transcribedSequence;
    transcribedSequence = "";
    std::ifstream seqFile;

    std::string filepath;
    filepath = argv[1];

    seqFile.open(filepath);
    if(seqFile.is_open()){
        while(std::getline(seqFile, sequence))
        {
            for(int i = 0; i < sequence.length(); i++)
            {
                char base;
                base = sequence[i];
                switch (base)
                {
                case 'T':
                    transcribedSequence += 'U';
                    break;
                
                default:
                    transcribedSequence += base;
                    break;
                }
            }
        }
        seqFile.close();
        std::cout << "Transcribed sequence: " << "\n";
        std::cout << transcribedSequence;
    }




    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include "base.h"

int main(int argc, char *argv[]){
    std::string sequence;
    std::string filepath;
    baseTracker baseTracker;
    filepath = argv[1];

    std::ifstream seqFile;
    seqFile.open(filepath);

    if(seqFile.is_open())
    {
        while(std::getline(seqFile, sequence)){
            for(int i = 0; i<sequence.length(); i++){

                char base;
                base = sequence[i];
                switch (base)
                {
                case 'A':
                    baseTracker.incrementA();
                    break;
                case 'T':
                    baseTracker.incrementT();
                    break;
                case 'C':
                    baseTracker.incrementC();
                    break;
                case 'G':
                    baseTracker.incrementG();
                    break;
                default:
                    break;
                }
            }
        }
        seqFile.close();
        int GCcount;
        int sequenceLength;
        float GCpercentage;
        GCcount = baseTracker.getC() + baseTracker.getG();
        sequenceLength = baseTracker.sequenceLength();
        GCpercentage = baseTracker.GCContent();
        std::cout << "Sequence is " << sequenceLength << " bases." << "\n";
        std::cout << "A: " << baseTracker.getA() << "\n";
        std::cout << "T: " << baseTracker.getT() << "\n";
        std::cout << "C: " << baseTracker.getC() << "\n";
        std::cout << "G: " << baseTracker.getG() << "\n";
        std::cout << "GC content is " << GCpercentage << "%" << " (" << GCcount << " of " << sequenceLength << " bases)" << "\n";

    }
    
    else std::cout << "Unable to open file" << "\n";
    


    return 0;
}
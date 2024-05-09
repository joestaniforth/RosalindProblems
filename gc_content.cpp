#include <iostream>
#include <fstream>
#include <string>

struct baseCounter
{
    int A = 0;
    int T = 0;
    int G = 0;
    int C = 0;
};


int main(int argc, char *argv[]){
    std::string sequence;
    std::string filepath;
    baseCounter gcContent;
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
                    gcContent.A+= 1;
                    break;
                case 'T':
                    gcContent.T+= 1;
                    break;
                case 'C':
                    gcContent.C+= 1;
                    break;
                case 'G':
                    gcContent.G+= 1;
                    break;
                default:
                    break;
                }
            }
        }
        seqFile.close();
        long sequenceLength;
        long GCcount;
        float GCpercentage;
        GCcount = gcContent.C + gcContent.G;
        sequenceLength = gcContent.A + gcContent.T + gcContent.C + gcContent.G;
        GCpercentage = (GCcount * 100) / sequenceLength;
        std::cout << "Sequence is " << sequenceLength << " bases." << "\n";
        std::cout << "A: " << gcContent.A << "\n";
        std::cout << "T: " << gcContent.T << "\n";
        std::cout << "C: " << gcContent.C << "\n";
        std::cout << "G: " << gcContent.G << "\n";
        std::cout << "GC content is " << GCpercentage << "%" << " (" << GCcount << " of " << sequenceLength << " bases)" << "\n";

    }
    
    else std::cout << "Unable to open file" << "\n";
    


    return 0;
}
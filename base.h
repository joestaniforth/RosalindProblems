struct basePairings {
    char APairing = 'T';
    char TPairing = 'A';
    char CPairing = 'G';
    char GPairing = 'C';
};

class baseTracker
{
private:
    int A = 0;
    int T = 0;
    int G = 0;
    int C = 0;
public:
    void incrementA(){
        A++;
    };
    void incrementT(){
        T++;
    };
    void incrementC(){
        C++;
    };
    void incrementG(){
        G++;
    };
    int getA(){
        return A;
    };
    int getT(){
        return T;
    };
    int getC(){
        return C;
    };
    int getG(){
        return G;
    };
    int sequenceLength(){
        return A + T + C + G;
    }
    double GCContent(){
        
        float GC = getC() + getG();
        float totalBases = sequenceLength();
        float GCPercentage = GC / totalBases;
        return GCPercentage * 100;

    }
};

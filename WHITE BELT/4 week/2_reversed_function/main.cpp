#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};



class FunctionPart{
public:
    FunctionPart(char new_oper, double new_val){
        oper = new_oper;
        val = new_val;
    }
    double Apply(double value) const{
        if (oper=='+') {
            return value + val;
        } else {
            return value - val;
        }
    }
    void Invert() {
        if (oper == '+') {
            oper = '-';
        } else {
            oper = '+';
        }
    }
private:
    char oper;
    char val;
};

class Function {
public:
    double Apply(double val)  const{
        for (const FunctionPart& part: parts) {
            val = part.Apply(val);
        }
        return val;
    }
    void AddPart(char oper, double val) {
        parts.push_back(FunctionPart(oper,val));
    }
    void Invert(){
        for (FunctionPart& part: parts) {
            part.Invert();
        }
        reverse(begin(parts),end(parts));
    }
private:
    vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image){
    Function function;
    function.AddPart('-',image.freshness*params.a+params.b);
    function.AddPart('+',image.rating*params.c);
    return function;
}

double ComputeImageWeight(const Params& params,
                          const Image& image) {
    Function function = MakeWeightFunction(params,image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              int weight) {
    Function function = MakeWeightFunction(params,image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = {10,2,6};
    Params params = {4,2,6};
    cout << ComputeImageWeight(params,image) << endl;
    cout << ComputeQualityByWeight(params,image,46) << endl;
    return 0;
}

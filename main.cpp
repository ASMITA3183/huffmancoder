#include <emscripten.h>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "coder.cpp"
#include "decode.cpp"
#define endl '\n'

using namespace std;

// Function to encode data
extern "C" {
    EMSCRIPTEN_KEEPALIVE
    const char* encode(const char* input) {
        HuffmanCoder coder(input);
        return strdup(coder.solve().c_str());
    }

    EMSCRIPTEN_KEEPALIVE
    const char* decode(const char* encodedData) {
        Decoder decoder(encodedData);
        return strdup(decoder.perform().c_str());
    }
}


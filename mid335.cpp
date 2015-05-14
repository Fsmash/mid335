//CMPS 335
//mid335.cpp
//
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {
    C = 1,
    Cs,
    D,
    Ds,
    E,
    F,
    Fs,
    G,
    Gs,
    A,
    As,
    B,
    END = B,
    HALF_STEPS_PER_OCTAVE = B 
} note_t;

double freq(note_t note, int octave_delta);


int main(int argc, char *argv[])
{
    note_t note;
    note_t array[12] = {C, Cs, D, Ds, E, F, Fs, G, Gs ,A, As ,B};
    int octave_delta;
    int num = 0;
    float tolerance;
    bool unit_test;

    ifstream input;
    input.open("in");


    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA> <TOLERANCE>" << endl;
        return 0;
    }
    //
    //
    switch(toupper(argv[1][0])) {
        case 'A': note = A; 
                  break;
        case 'B': note = B; 
                  break;
        case 'C': note = C; 
                  break;
        case 'D': note = D; 
                  break;
        case 'E': note = E; 
                  break;
        case 'F': note = F; 
                  break;
        case 'G': note = G; 
                  break;
        case 'Z': unit_test = true; break;
    }
    float frq[500];                //string array that holds words on every line of cracklib-small file

    while (input >> frq[num])  //get number of lines while inserting each word into array
        ++num;

    //You may call your unit test here...
    octave_delta = atoi(argv[2]);
    tolerance = (float)atoi(argv[3]);

    if (unit_test && octave_delta == 0) {
        cout << "\ntolerance: " << tolerance << endl;    
        cout << "freq function unit-test" << endl;  
        cout << setw(10) << "note" << setw(10) << "octave" << setw(10) << "value" << setw(10) << "diff" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 12; j++) {
                if (abs(frq[i*12 + j] - freq(array[j], i)) > tolerance )
                    cout << setw(10) << array[j] << setw(10) << i << setw(10) << freq(array[j], i) << setw(20) << abs(frq[i*12 + j] - freq(array[j], i)) << setw(10) << "good " << endl;
                else 
                    cout << setw(10) << array[j] << setw(10) << i << setw(10) << freq(array[j], i) << setw(20) << abs(frq[i*12 + j] - freq(array[j], i)) << setw(10) << "bad" << endl;
            }
        }

    } else 	if (note > END) {
        cout << "Invalid note!" << endl;
        return 1;
    } else { 
        cout << HALF_STEPS_PER_OCTAVE << endl;
        cout << freq(note, octave_delta) << endl;
    }
    return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
    double freq;
    double factor;
    double a;
    int n;
    int octave = octave_delta - F0_octave;

    a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
    n = note - F0_note;
    freq = F0 * pow(a, (double)n);
    factor = pow(2.0, (double)octave);
    freq = freq * factor;
    return freq;
}


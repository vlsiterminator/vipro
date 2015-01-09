#ifndef REGFILE_H_
#define REGFILE_H_

#include "periphery.h"
#include "metalCap.h"
#include "userInput.h"
#include <sstream>
#include <iostream>//cout;
#include <string>
#include <fstream>
#include <cstdlib> //stdlib.h; for exit.
#include <cmath>

class RegFile {
    public:
        RegFile(userInput& uImp);
        RegFile();
        ~RegFile();
        void setInput(userInput& uImp);
        void charGateCap();
        void calculateTechRC();
        void constructTemplate();
        void rmPrevResults();
        void simulate(string tests);
        void extractOutput();
        void print();
        void calculateReadED(float& read_energy, float& read_delay);
        void calculateWriteED(float& write_energy, float& write_delay);
        void getSAED(float& SAenergy, float& SAdelay);
        void getRDED(float& RDenergy, float& RDdelay);
        void getBCED(float& BCenergy, float& BCdelay);
        void getTBED(float& TBenergy);
        void getDFFED(float& DFFenergy, float& DFFdelay);
        void getBMED(float& BMenergy, float& BMdelay);
        void runTASE(string tempPath);
        double calculateGateCap();

    private:
        // Change objects to pointers if needed
        userInput inp; // should be changed to separate SRAM components from Tests
        senseAmp SA;
        rowDecoder RD;
        colMux CM;
        bitCell BC;
        timingBlock TB;
        writeDriver WD;
        DFF ioDFF;
        bankMux BM;
        stringstream techTemplate;
        string test2run;
  ifstream capfile;
  ifstream minwfile;
  stringstream sst;

        double gateCap;
        double rbl;
        double cbl;
        double cwl;
  double minw;
  double tol;
  double cap[10];
  double delay_cap[10];
  double delay_fet[10];
  double delay_diff[10];
  double min_diff;
  double cap_value;
};


#endif /* REGFILE_H_ */

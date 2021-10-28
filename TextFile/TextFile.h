//
// Created by nikita on 28.10.2021.
//

#include <string>
#include <vector>
#include <iostream>

#ifndef TEXTFILE_TEXTFILE_H
#define TEXTFILE_TEXTFILE_H

using namespace std;

class TextFileElem{
    int N, NORAD, Freq;
    double Hours, Amp, KK, R, AntAz, AntEl;
    string Name, Time;
public:
    friend class TextFile;
    friend class vector<TextFileElem>;

    TextFileElem(int N, string Time, double Hours, int Freq, double Amp, double KK, double R, double AntAz, double AntEl, int NORAD, string Name);
    TextFileElem(const TextFileElem &elem);

    friend ostream &operator<<(ostream &os, const TextFileElem &elem);

    TextFileElem();

    int getN() const;

    int getNorad() const;

    int getFreq() const;

    double getHours() const;

    double getAmp() const;

    double getKk() const;

    double getR() const;

    double getAntAz() const;

    double getAntEl() const;

    const string &getName() const;

    const string &getTime() const;

    bool operator==(const TextFileElem &rhs) const;

    bool operator!=(const TextFileElem &rhs) const;

    TextFileElem operator=(const TextFileElem &rhs);
};

class TextFile {
    vector<TextFileElem> lines;
public:
    TextFile(string fileName);
    TextFile(TextFile const &textFile);

    virtual ~TextFile();

    friend ostream &operator<<(ostream &os, const TextFile &file);

    TextFile operator=(const TextFile &rhs);

    void saveFile(string fileName);

    int getSize();

    void addFile(TextFile &rhs);
};




#endif //TEXTFILE_TEXTFILE_H

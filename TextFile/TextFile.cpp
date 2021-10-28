//
// Created by nikita on 28.10.2021.
//

#include "TextFile.h"
#include <fstream>


int TextFileElem::getN() const {
    return N;
}

int TextFileElem::getNorad() const {
    return NORAD;
}

int TextFileElem::getFreq() const {
    return Freq;
}

double TextFileElem::getHours() const {
    return Hours;
}

double TextFileElem::getAmp() const {
    return Amp;
}

double TextFileElem::getKk() const {
    return KK;
}

double TextFileElem::getR() const {
    return R;
}

double TextFileElem::getAntAz() const {
    return AntAz;
}

double TextFileElem::getAntEl() const {
    return AntEl;
}

const string &TextFileElem::getName() const {
    return Name;
}

const string &TextFileElem::getTime() const {
    return Time;
}

bool TextFileElem::operator==(const TextFileElem &rhs) const {
    return N == rhs.N &&
           NORAD == rhs.NORAD &&
           Freq == rhs.Freq &&
           Hours == rhs.Hours &&
           Amp == rhs.Amp &&
           KK == rhs.KK &&
           R == rhs.R &&
           AntAz == rhs.AntAz &&
           AntEl == rhs.AntEl &&
           Name == rhs.Name &&
           Time == rhs.Time;
}

bool TextFileElem::operator!=(const TextFileElem &rhs) const {
    return !(rhs == *this);
}

TextFileElem::TextFileElem() {

}

ostream &operator<<(ostream &os, const TextFileElem &elem) {
    os << "N: " << elem.N << " NORAD: " << elem.NORAD << " Freq: " << elem.Freq << " Hours: " << elem.Hours << " Amp: "
       << elem.Amp << " KK: " << elem.KK << " R: " << elem.R << " AntAz: " << elem.AntAz << " AntEl: " << elem.AntEl
       << " Name: " << elem.Name << " Time: " << elem.Time <<endl;
    return os;
}

TextFileElem::TextFileElem(int N, string Time, double Hours, int Freq, double Amp, double KK, double R, double AntAz,
                           double AntEl, int NORAD, string Name) {

    this->N = N;
    this->Time = Time;
    this->Hours = Hours;
    this->Freq = Freq;
    this->Amp = Amp;
    this->KK = KK;
    this->R = R;
    this->AntAz = AntAz;
    this->AntEl = AntEl;
    this->NORAD = NORAD;
    this->Name = Name;

}

TextFileElem::TextFileElem(const TextFileElem &elem) {
    this->N = elem.N;
    this->Time = elem.Time;
    this->Hours = elem.Hours;
    this->Freq = elem.Freq;
    this->Amp = elem.Amp;
    this->KK = elem.KK;
    this->R = elem.R;
    this->AntAz = elem.AntAz;
    this->AntEl = elem.AntEl;
    this->NORAD = elem.NORAD;
    this->Name = elem.Name;
}

TextFileElem TextFileElem::operator=(const TextFileElem &rhs) {
    return TextFileElem(rhs);
}

TextFile::TextFile(string fileName) {
    ifstream fin(fileName);
    string str;
    for (int i = 0; i < 11; i++){
        fin >>str;
        //cout <<str;
    }
    int prevN = -1, N;
    while(!fin.eof()){
        TextFileElem elem;
        fin >> N;
        if (N == prevN){
            break;
        }
        else{
            elem.N = N;
            prevN = N;
        }
        fin >> elem.Time;
        fin >>elem.Hours;
        fin >>elem.Freq;
        fin >>elem.Amp;
        fin >>elem.KK;
        fin >>elem.R;
        fin >>elem.AntAz;
        fin >>elem.AntEl;
        fin >>elem.NORAD;
        fin >>elem.Name;
        lines.push_back(elem);
    }
    fin.close();
}

ostream &operator<<(ostream &os, const TextFile &file) {
    os <<"SIZE:     " <<file.lines.size() <<endl;
    for (int i = 0; i < file.lines.size(); i++){
        os <<file.lines[i] <<endl;
    }
    return os;
}

TextFile::~TextFile() {
    lines.clear();
}

TextFile::TextFile(const TextFile &textFile) {
    for (int i = 0; i < textFile.lines.size(); i++){
        TextFileElem elem = textFile.lines[i];
        lines.push_back(elem);
    }
}

TextFile TextFile::operator=(const TextFile &rhs) {
    return TextFile(rhs);
}

void TextFile::saveFile(string fileName) {
    ofstream fout(fileName);
    fout <<"N\tTime\tHours\tFreq(kHz)\tAmp\tKK\tR(km)\tAntAz(grad)\tAntEl(grad)\tNORAD\tName\n";
    for (int i = 0; i < lines.size(); i++){
        fout <<lines[i].N <<"\t";
        fout <<lines[i].Time <<"\t";
        fout <<lines[i].Hours <<"\t";
        fout <<lines[i].Freq <<"\t";
        fout <<lines[i].Amp <<"\t";
        fout <<lines[i].KK <<"\t";
        fout <<lines[i].R <<"\t";
        fout <<lines[i].AntAz <<"\t";
        fout <<lines[i].AntEl <<"\t";
        fout <<lines[i].NORAD <<"\t";
        fout <<lines[i].Name <<"\t";
        fout <<"\n";
    }
    fout.close();
}

int TextFile::getSize() {
    return lines.size();
}

void TextFile::addFile(TextFile &rhs) {
    for (int i = 0; i < rhs.lines.size(); i++){
        TextFileElem elem = rhs.lines[i];
        lines.push_back(elem);
    }
}



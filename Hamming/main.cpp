#include <iostream>
#include <fstream>

using namespace std;

struct EncodedChar{
    unsigned char c1, c2;
};

unsigned char hammerPrepare(unsigned char c){
    unsigned char c1 = 0;
    c1 = c1 | ((c&8) << 3);
    c1 = c1 | ((c&4) << 3);
    c1 = c1 | ((c&2) << 3);
    c1 = c1 | ((c&1) << 2);
    return c1;
}

unsigned char addCRC(unsigned char c){
    unsigned char crc1 = 0, crc2 = 0, crc3 = 0;
    crc1 = ((c&4)>>2) ^ ((c&16)>>4) ^ ((c&64)>>6);
    crc2 = ((c&4)>>2) ^ ((c&32)>>5) ^ ((c&64)>>6);
    crc3 = ((c&16)>>4) ^ ((c&32)>>5) ^ ((c&64)>>6);
    crc2 = crc2 << 1;
    crc3 = crc3 << 3;
    c = crc1 | crc2 | crc3 | c;
    return c;
}

EncodedChar encode(unsigned char c){
    unsigned char c1 = hammerPrepare(c);
    unsigned char c2 = hammerPrepare(c >> 4);
    c1 = addCRC(c1);
    c2 = addCRC(c2);
    EncodedChar info;
    info.c1 = c1;
    info.c2 = c2;
    return info;
}

unsigned char checkCRC(unsigned char c){
    unsigned char crc1 = 0, crc2 = 0, crc3 = 0;
    crc1 = ((c&1)) ^ ((c&4)>>2) ^ ((c&16)>>4) ^ ((c&64)>>6);
    crc2 = ((c&2)>>1) ^ ((c&4)>>2) ^ ((c&32)>>5) ^ ((c&64)>>6);
    crc3 = ((c&8)>>3) ^ ((c&16)>>4) ^ ((c&32)>>5) ^ ((c&64)>>6);
    int pos = crc1 * 1 + crc2 * 2 + crc3 * 3;
    if (pos > 0){
        if (c >> (pos-1) == 0){
            c = c | (1<<(pos-1));
        }
        else{
            unsigned char c1 = 254;
            for (int i = pos - 1; i > 0; i--){
                c1 << 1;
                c1 = c1 | 1;
            }
            c = c&c1;
        }
    }
    return c;
}

unsigned char cleanFromCRC(unsigned char c){
    unsigned char c1 = 0;
    c1 = c1 | ((c&64) >> 3);
    c1 = c1 | ((c&32) >> 3);
    c1 = c1 | ((c&16) >> 3);
    c1 = c1 | ((c&4) >> 2);
    return c1;
}

unsigned char decode(EncodedChar info){
    unsigned char c1, c2, c = 0;
    c1 = checkCRC(info.c1);
    c2 = checkCRC(info.c2);
    c1 = cleanFromCRC(c1);
    c2 = cleanFromCRC(c2);
    c = (c2<<4) | c1;
    return c;
}

string toHex(int n) {
   string a[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
   return a[n/16] + a[n%16];
}

int hexToNum(string hexNum){
    int ans = 0;
    if (hexNum[0] >= '0' && hexNum[0] <= '9'){
        ans += hexNum[0] - '0';
    }
    else if (hexNum[0] >= 'A' && hexNum[0] <= 'F'){
        ans += hexNum[0] - 'A' + 10;
    }
    if (hexNum[1] >= '0' && hexNum[1] <= '9'){
        ans += (hexNum[1] - '0')*16;
    }
    else if (hexNum[1] >= 'A' && hexNum[1] <= 'F'){
        ans += (hexNum[1] - 'A' + 10)*16;
    }
    return ans;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    cout <<"1 - encode \n2 - decode\n";
    int choose;
    fin >>choose;
    if (choose == 1){
        string s;
        fin >> s;
        for (int i = 0; i < s.length(); i++){
            EncodedChar info = encode(s[i]);
            fout <<toHex(info.c2) <<toHex(info.c1);
        }
    }
    else if (choose == 2){
        string s;
        fin >> s;
        if (s.length() % 4 != 0){
            fout <<"Wrong length!";
            return 0;
        }
        for (int i = 0; i < s.length(); i+=4){
            EncodedChar info;
            string s1(1, s[i]);
            string s2(1, s[i + 1]);
            string s3(1, s[i + 2]);
            string s4(1, s[i + 3]);

            info.c2 = hexToNum(s2 + s1);
            info.c1 = hexToNum(s4 + s3);
            fout <<decode(info);
        }
    }
}

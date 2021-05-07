#include <iostream>

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

int main(){
    cout <<"1 - encode \n2 - decode\n";
    int choose;
    cin >>choose;
    if (choose == 1){
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++){
            EncodedChar info = encode(s[i]);
            cout <<info.c2 <<info.c1;
        }
    }
    else if (choose == 2){
        string s;
        cin >> s;
        if (s.length() % 2 != 0){
            cout <<"Wrong length!";
            return 0;
        }
        for (int i = 0; i < s.length(); i+=2){
            EncodedChar info;
            info.c2 = s[i];
            info.c1 = s[i + 1];
            cout <<decode(info);
        }
    }
}

//    Copyright (c) 2018 Norbert Rühl
//
//    This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
//
//      Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
//
//      1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
//
//      2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
//
//      3. This notice may not be removed or altered from any source distribution.

#include <libkopiernudel/archive.hh>
#include <iostream>

/**
 * Simple Programm to print out all Pastas
 */
int main(int argc, char** argv){
    using namespace libkopiernudel;
    using namespace std;
    for(const kopiernudel &k: archive::kopiernudeln()){
        cout << k.getTitle() << endl;
        cout << k.getPasta() << endl;
        cout << endl;
    }

}

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

#ifndef LIBKOPIERNUDEL_KOPIERNUDEL_H
#define LIBKOPIERNUDEL_KOPIERNUDEL_H

#include <string>

namespace  libkopiernudel{
    /**
     * kopiernudel Class
     * This Class serves as a Wrapper for one Kopiernudeln
     */
    class kopiernudel {
    public:
        /**
         * The Default Constructor requires
         * @param title : the title of the pasta e.g. "Du Lügner"
         * @param pasta : the content of the pasta e.g. "[...]"you get the concept
         */
        kopiernudel(const std::string &title, const std::string &pasta) : title(title), pasta(pasta) {}
        /**
         * @return the Pasta Title
         */
        const std::string &getTitle() const { return title;}
        /**
         * @return the Pasta in all its glory
         */
        const std::string &getPasta() const { return pasta;}
    private:
        std::string title;
        std::string pasta;
    };
};

#endif //LIBKOPIERNUDEL_KOPIERNUDEL_H

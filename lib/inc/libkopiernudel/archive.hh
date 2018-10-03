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

#ifndef LIBKOPIERNUDEL_ARCHIVE_H
#define LIBKOPIERNUDEL_ARCHIVE_H

#include <array>
#include <vector>
#include <libkopiernudel/kopiernudel.h>

namespace  libkopiernudel{
    /**
     * Archive Class
     * This Class serves as a wrappter to find and return the Kopiernudeln
     * It Stores @PASTAS_SIZE@ Kopiernudeln + 1 for Code Generation Purpose which is an empty one
     */
    class archive{
    public:
        /**
         * Function to find a matching copy pasta
         * @param name : string in title
         * @return an vector of matching pastas
         */
        static std::vector<kopiernudel> findByName(std::string name);
        /**
         * Function to find a matching copy pasta
         * @param text : string in pasta
         * @return an vector of matching pastas
         */
        static std::vector<kopiernudel> findByText(std::string text);
        /**
         * Function to find a matching copy pasta
         * @param any : string in title or pasta
         * @return an vector of matching pastas
         */
        static std::vector<kopiernudel> findByAny(std::string any);
        /**
         * Function to get the copy pastas
         * @return an empty kopiernudel and the others
         */
        static const std::array<kopiernudel,@PASTAS_SIZE@ +1> kopiernudeln();

    };
};

#endif
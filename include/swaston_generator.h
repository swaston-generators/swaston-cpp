#ifndef SWASTON_GENERATOR_H
#define SWASTON_GENERATOR_H

#include <string>

#include "utf8.h"
#include "utf8_tools.h"

std::string generate_swaston(const std::string &s) {
    if (utf8::distance(s.begin(), s.end()) < 2) { // can't use distance smaller than 2 because size_t underflow
        return s;
    }
    std::string
            l_spaced_word = utf8_join(s, " "),
            r_spaced_word = utf8_reverse(l_spaced_word),
            l_word = utf8_reverse(s),
            r_word = s,
            center = l_spaced_word + utf8_substr(r_spaced_word, 1) + '\n',
            tab_pre = std::string(utf8::distance(r_spaced_word.begin(), r_spaced_word.end()) - 2, ' '),
            tab_post = tab_pre + " ", // extended tab
            upper,
            lower;

    std::vector<std::string>
            r_vec = utf8_to_vector(r_word),
            l_vec = utf8_to_vector(l_word); // convert utf-8 string to vector of strings

    size_t length = l_vec.size();

    for (size_t c = 0; c != length - 1; c++) { // upper side

        if (c == 0) { // case first row
            upper += l_vec[c];
            upper += tab_pre;
            upper += l_spaced_word;
            upper += '\n';
        } else {
            upper += l_vec[c];
            upper += tab_pre;
            upper += r_vec[c];
            upper += tab_post;
            upper += '\n';

        }
    }

    for (size_t c = 1; c != length; c++) { // lower side
        if (c == length - 1) { // case last row
            lower += r_spaced_word;
            lower += tab_pre;
            lower += r_vec[c];
            lower += '\n';
        } else {
            lower += tab_post;
            lower += l_vec[c];
            lower += tab_pre;
            lower += r_vec[c];
            lower += '\n';
        }
    }

    return upper + center + lower;
}

#endif

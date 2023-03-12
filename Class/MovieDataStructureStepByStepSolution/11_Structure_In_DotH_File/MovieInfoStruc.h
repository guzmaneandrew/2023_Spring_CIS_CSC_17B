/* 
 * File:   MovieInfoStrUc.h
 * Author: mlehr
 *
 * Created on July 14, 2021, 4:48 PM
 */

#ifndef MOVIEINFOSTRUC_H
#define MOVIEINFOSTRUC_H

#include <string>
using namespace std;

struct MovieInfo{
    string movName;//Strings are good
    char *dirName;//You should know how to deal with dynamic character arrays
    unsigned short yrRlsd; //Don't need a larger data size and always > 0
    unsigned short runTime;//Don't need a larger data size and always > 0
};


#endif /* MOVIEINFOSTRUC_H */


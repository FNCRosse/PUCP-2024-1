/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de abril de 2024, 10:18
 */

#include <iostream>
using namespace std;
#include "FuncionesVoid.h"

int main(int argc, char** argv) {
    void * Tweets;
    
    LeerTweets(Tweets,"tweets.csv");
    MostrarTweets(Tweets,"ReporteInicialTweets.txt");
    LeerHashtags(Tweets,"hashtags.csv");
    MostrarTweets(Tweets,"ReporteFinalTweets.txt");
    return 0;
}


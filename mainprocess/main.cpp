/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:33 by achamdao          #+#    #+#             */
/*   Updated: 2026/01/22 21:29:02 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include "Webserv.hpp"

using namespace std;



std::string GenerateTestString(int Length)
{
    return std::string(Length, 'A');
}

long long getCurrentTime() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 * 1000) + (tv.tv_usec);
}
int main(void)
{
    std::string Str = "achraf : lalalalalalala\r\n      \t    ";
    size_t POS = 0;
    if ((POS = FindCRLF(Str, "\r\n")) != std::string::npos)
        cout << Str.substr(0, POS)<<",,"<< endl;
    else
        cout << "CRLF NOT found "<< endl;
        
    return 0;
}
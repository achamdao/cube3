/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:33 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/15 15:45:40 by achamdao         ###   ########.fr       */
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

// std::string	convert_hex(const std::string &Str, int Num)
// {
// 	int		i = 0;
// 	std::string	MaxHex;
// 	std::string	Result;

// 	if (Num == 0)
// 		return ("0");
// 	while (Num > 0)
// 	{
// 		MaxHex += Str[Num % 16];
// 		Num /= 16;
// 	}
//     i = MaxHex.size() - 1;
// 	while (i >= 0)
// 		Result += MaxHex[i--];
// 	return (Result);
// }

int main(void)
{
    time_t t = time(0); // get time now
     tm* gmtm = gmtime(&t);
    char Str[100];
    clsResponse Response;
    cout <<  Response.ChunkData("achraf hamdaoui skjsjshjsksjkskjsjsjkssss") <<"\n";
    // converting now to tm struct for UTC date/time
    return 0;
}
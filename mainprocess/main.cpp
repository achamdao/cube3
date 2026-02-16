/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:33 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/15 20:39:12 by achamdao         ###   ########.fr       */
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

int main(void)
{
    std::map<std::string, std::string> Types;
    std::map<std::string, std::string>::iterator TypesI;
    StoredType(Types,"response/file.type");
    if (Types.empty())
        cout << "is empty" << endl;
    for (TypesI = Types.begin(); TypesI != Types.end(); TypesI++)
        cout << "Key :" << TypesI->first <<"\n" << "Value : "<< TypesI->second << endl;
    // converting now to tm struct for UTC date/time
    return 0;
}
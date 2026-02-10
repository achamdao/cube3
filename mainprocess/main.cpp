/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:33 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/10 18:05:29 by achamdao         ###   ########.fr       */
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
    time_t t = time(0); // get time now
    std::string dt = ctime(&t); // convert in string form
    cout << "Local date and time is: " << DateTime() << "\n";
    // converting now to tm struct for UTC date/time
    return 0;
}
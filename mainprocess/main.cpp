/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:33 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/17 16:34:13 by achamdao         ###   ########.fr       */
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
    clsResponse Response;
    Response.SetFileFromDisk("response/file.txt");
    Response.SetStatus(200);
    Response.SetType("text/plain");
    Response.SetMod(GET);
    cout << Response.MakeResponse();
    cout << Response.GetBody();
    cout << Response.GetFileName();
    return 0;
}
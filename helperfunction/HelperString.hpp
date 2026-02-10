/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperString.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:34:41 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/10 18:28:36 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HEALPER_STRING_HPP
# define HEALPER_STRING_HPP
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

int ReadData(int FD, std::string &Data, size_t Size);
std::string GetNextLine(int FD, std::string &BigData, size_t Size);
std::string ConvertStringToLower(std::string &Str);
bool Ischar(const std::string &Sep, char C);
int SkeeSep(const std::string &Str, const std::string &Sep);
int SkeeSep(const std::string &Str, char Sep);
std::vector<std::string> Split(std::string Str, char Sep , int TimesSplit);
int ReadData(int FD, std::string &Data, size_t Size);
std::string GetNextLine(int FD, std::string &BigData, size_t Size);
std::string  TrimStr(std::string Str,const std::string &Sep);
bool IsStringDigit(const std::string &StringDigit);
bool Iswhaitspace(char C);bool CmpStr(const std::string &Str1, const std::string &Str2, bool Switch);
size_t FindCRLF(const std::string &Str, const std::string &CRLF);
std::string DateTime();

#endif
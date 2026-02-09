/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:28 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/09 20:23:08 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainprocess/Webserv.hpp"

clsResponse::clsResponse()
{
    _Mod = 0;
    _Status = 0;
    _BodySize = 0;
    _Fd = -1;
    _Body = "";
    _Type = "";
}

std::string clsResponse::MakeResponse()
{
    std::stringstream Headers;
    if (_Mod == ERROR)
    {
        _HeaderFeild.clear();
        _ErrorPage.SetType(_Type);
        return _ErrorPage.ResponseError(_Status);
    }
    for (std::string &Str: _HeaderFeild)
        Headers << Str;
    Headers << "\r\n";
    return Headers.str();
}

std::string clsResponse::InitialHeaders(std::string Type, size_t Size)
{
    
}

void clsResponse::Status()
{
    std::stringstream Headers;
    Headers << "HTTP/1.1 "<< _Status << " " <<  _ErrorPage.GetStatusMessage(_Status) <<"\r\n";
    _HeaderFeild.push_back(Headers.str());
}

void clsResponse::ContentLength()
{
    std::stringstream Headers;
    if (_Mod == CHUNK)
        return;
    Headers << "Content-Length: "<< _BodySize<<"\r\n";
    _HeaderFeild.push_back(Headers.str());
}
void clsResponse::ContentType()
{
    std::stringstream Headers;
    if (!_BodySize)
        return;
    Headers << "Content-Type: "<< _Type<<"\r\n";
    _HeaderFeild.push_back(Headers.str());
}

void clsResponse::Connection()
{
    std::stringstream Headers;
    if (_Mod == ERROR)
        Headers << "Connection: "<< "close"<<"\r\n";
    else
        Headers << "Connection: "<< "keep-alive"<<"\r\n";
    _HeaderFeild.push_back(Headers.str());
}




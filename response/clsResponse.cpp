/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:28 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/12 17:25:48 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainprocess/Webserv.hpp"

clsResponse::clsResponse()
{
    _Mod = 0;
    _Status = 0;
    _BodySize = 0;
    _FileName = "";
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
    for (int i = 0; i < _HeaderFeild.size() ;i++)
        Headers << _HeaderFeild[i];
    Headers << "\r\n";
    return Headers.str();
}

void clsResponse::InitialHeaders()
{
    Status();
    ContentLength();
    ContentType();
    Connection();
    Transfer_Encoding();
    Redirction();
    Date();
    CachControl();
    Server();
    Allow();
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

void clsResponse::Transfer_Encoding()
{
    std::stringstream Headers;
    if (_Mod != CHUNK)
        return;
    Headers << "Transfer-Encoding: chunked\r\n";
    _HeaderFeild.push_back(Headers.str());
}

void clsResponse::Redirction()
{
    std::stringstream Headers;
    if (_Mod != REDIRECTION)
        return;
    Headers << "Location: "<<"..."<<"\r\n";
    _HeaderFeild.push_back(Headers.str());
}
void clsResponse::Date()
{
    std::stringstream Headers;
    Headers << "Date: "<< DateTime() <<"\r\n";     
    _HeaderFeild.push_back(Headers.str());
}
void clsResponse::CachControl()
{
    std::stringstream Headers;
    Headers << "Cache-Control: no-cache\r\n";
    _HeaderFeild.push_back(Headers.str());
}

void clsResponse::Server()
{
    std::stringstream Headers;
    Headers << "Server: Name Server\r\n";
    _HeaderFeild.push_back(Headers.str());
}

void clsResponse::RetryAfter()
{
    std::stringstream Headers;
    if (_Status != 429 && _Status != 301 && _Status != 503)
        return;
    Headers << "Retry-After: "<< 120 << "\r\n";
    _HeaderFeild.push_back(Headers.str());
}

void clsResponse::Allow()
{
    std::stringstream Headers;
    if (_Status != 405)
        return;
    Headers << "Allow: "<< "GET , POST , DELETE" << "\r\n";
    _HeaderFeild.push_back(Headers.str());
}

void clsResponse::StoredInFileOrStr()
{
    std::string FileName = "file";
    std::string Data;
    int FD = open(FileName.c_str(), O_RDONLY, 644);
    if (FD < 0)
    {
        _Mod = ERROR;
        return ;
    }
    Data = ReadData(FD, Data, 100);
    while(Data.empty())
    {
        _BodySize += Data.size();
        if (_BodySize > 2000)
        {
            _Mod = CHUNK;
            _Body.clear();
            _Body = "";
            _FileName = FileName;
            close(FD);
            return ;
        }
        _Body += Data;
        Data = ReadData(FD, Data, 100);
    }
}

std::string clsResponse::ChunkData(const std::string &Str)
{
    std::string NewStr;

    if (Str == "")
        return ("0\r\n");
    NewStr += Convert_Hex("0123456789abcdef",Str.size());
    NewStr += "\r\n";
    NewStr += Str;
    NewStr += "\r\n";
    return (NewStr);
}

clsResponse::~clsResponse()
{
    
}
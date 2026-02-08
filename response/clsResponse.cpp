/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:28 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/08 18:05:05 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainprocess/Webserv.hpp"

std::string clsResponse::HeadersErrorResponse(std::string Type, size_t Size)
{
    std::stringstream Headers;
    Headers << "HTTP/1.1 "<< _Status << " " <<  GetStatusMessage() <<"\r\n";
    Headers << "Content-Type: " << Type << "\r\n";
    Headers << "Content-Length: " << Size << "\r\n";
    Headers << "Server: Webserv/1.0\r\n";
    Headers <<  "Connection: Close\r\n";
    Headers << "\r\n";
    Headers << "<h1>" << Size << "</h1>";
    return (Headers.str());
}

std::string clsResponse::InitialHeaders(std::string Type, size_t Size)
{
    std::stringstream Headers;
    Headers << "HTTP/1.1 "<<_Status << " " <<  GetStatusMessage() <<"\r\n";
    if (Type != "")
        Headers << "Content-Type: " << Type << "\r\n";
    if (Size >= 0 && _Mod != CHUNK)
        Headers << "Content-Length: " << Size << "\r\n";
    if (_Mod == DIRECTION)
        Headers << "Location: "<< Data.location <<"\r\n";
    if (_Mod == CHUNK)
        Headers << "Transfer-Encoding: chunked\r\n";
    Headers << "Server: Webserv/1.0\r\n";
    if (!Data.isClos)
        Headers <<  "Connection: keep-alive\r\n";
    else
        Headers <<  "Connection: Close\r\n";
    Headers << "\r\n";
    return (Headers.str());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsErrorPage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:48:27 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/09 20:07:01 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clsErrorPage.hpp"

 clsErrorPage::clsErrorPage()
{
    _Type = "";
    _Status = 0;
    StoredBodys();
    StoredMessage();
}

std::string clsErrorPage::GetStatusMessage(int Status) 
{
    if (_Message.count(Status))
        return  _Message[Status];
    return ("Unknown Status");
}
void clsErrorPage::SetType(std::string Type) 
{
    _Type = Type;
}
 std::string clsErrorPage::GetBody(int Status)
 {
     if (_Body.count(Status))
         return  _Body[Status];
     return ("Unknown Status");
 }
 std::string clsErrorPage::HeadersErrorResponse(std::string Type, size_t Size)
 {
     std::stringstream Headers;
     Headers << "HTTP/1.1 "<< _Status << " " <<  GetStatusMessage(_Status) <<"\r\n";
     Headers << "Content-Type: " << Type << "\r\n";
     Headers << "Content-Length: " << Size << "\r\n";
     Headers << "Server: Webserv/1.0\r\n";
     Headers <<  "Connection: Close\r\n";
     Headers << "\r\n";
     return (Headers.str());
 }
 void clsErrorPage::StoredBodys()
 {
     _Body[200] = "Body200";
     _Body[201] = "Body201";
     _Body[204] = "Body204";
     _Body[301] = "Body301";
     _Body[302] = "Body302";
     _Body[400] = "Body400";
     _Body[403] = "Body403";
     _Body[404] = "Body404";
     _Body[500] = "Body500";
     _Body[501] = "Body501";
 }
 
 void clsErrorPage::StoredMessage()
 {
     _Message[200] = "OK";
     _Message[201] = "Created";
     _Message[204] = "No Content";
     _Message[301] = "Moved Permanently";
     _Message[302] = "found";
     _Message[400] = "Bad Request";
     _Message[403] = "Forbidden";
     _Message[404] = "Not Found";
     _Message[500] = "Internal Server Error";
     _Message[501] = "Not Implemented";
 }
 
 std::string clsErrorPage::ResponseError(int Status)
 {
    if (Status >= 0)
        _Status = Status;
    std::stringstream Response;
    std::string Body = GetBody(Status);
    std::string Headers = HeadersErrorResponse(_Type, Body.size());
    Response << Headers << Body;
    return (Response.str());
 }
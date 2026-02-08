/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsMainProcess.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:09 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/08 19:01:46 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainprocess/Webserv.hpp"

void clsMainProcess::PartRedirection()
{
    _Status = (IsMyhost)? 302 : 301;
    _Mod = DIRECTION
    Response.MakeResponse(Status, Data);
}

void clsMainProcess::PartPermission()
{
    _Status = 403 ;
    _Mod = ERROR
    Response.MakeResponse(Status, Data, );
}

void clsMainProcess::PartCGI()
{
    _Status = 200 ;
    int _FD = (RunCGI());
    if (_FD < 0)
    {
        _Mod = ERROR
        _Status = _FD * -1;
    }
    else
        ; //here set Mod and Status
}

void clsMainProcess::PartDeleteMethod()
{
    _Status = 200 ;
    _Mod = DELETE;
    if (access(Data.FilePath))
    {
        _Status = 404 ;
        _Mod = ERROR;
    }
    // delete file or folder any things
    Response.MakeResponse(Status, Data, ); 
}

void clsMainProcess::PartPOSMethod()
{
    _Status = 200 ;
    _Mod = UPLOAD
    // upload data in file uploding 
    Response.MakeResponse(Status, Data, ); 
}

void clsMainProcess::MakeOutoIndex(std::string NamesFiles)
{
    
}

void clsMainProcess::PartNormalResponse()
{
    if ((Data.AutoIndex))
    {
        _Status = 200 ;
       _Mod = AUTOINDEX
       Response.MakeResponse(Status, Data, );
    }
    else if (access(Data.FilePath))
    {
           _Status = 404 ;
           _Mod = ERROR
           Response.MakeResponse(Status, Data, );
    }
    else
    
       _Status = 200 ;
       _Mod = STATIC
       Response.MakeResponse(Status, Data, );  // normal response
    
}

void clsMainProcess::MainProcess()
{
    if (Data.location)
        PartRedirection();
    else if ((Data.permission | Data.Method )!= Data.Method)
        PartPermission();
    else if (Data.RunCGI)
        PartCGI();
    else if (Data.Method == DELETE)
        PartDeleteMethod();
    else if (Data.Method == POS)
        PartPOSMethod();
    else
        PartNormalResponse()
        
}
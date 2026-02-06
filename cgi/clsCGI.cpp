/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsCGI.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:40:02 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/06 16:21:24 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mainprocess/Webserv.hpp"

long long clsCGI::GetCurrentTime() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int clsCGI::RunCGI(std::string NameFile, clsData Data, int TimeOut)
{
    int status;
    int exit_code;
    int pip[2] = {-1,-1};
    if (pipe(pip) == -1)
        return -500;
    _StartTime = getCurrentTime();
    _PIDCHILD = fork();
    if (_PIDCHILD < 0)
        return (close(fd1), -500);
    if (_PIDCHILD == 0)
    {
        close(pip[0]);
        if (dup2(pip[1], 1) == -1)
            return (close(fd1), -1);
        close(pip[1]);
        if (chdir(Data.GetFolder()) < 0)
            return (-1);
        execve(Data.GetPath(),Data.GetArgs(), Data.GetEnv());
        return -1;
    }
    else
    {
        close(pip[1]);
        exit_code = waitpid(p, &status, WNOHANG);
        if (exit_code < 0)
            return (close(pip[0]), -500);
        else if (WEXITSTATUS(status) == 1)
            return (close(pip[0]), -500);
        else if (exit_code > 0)
            break;
    }
    return pip[0];
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsCGI.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:09 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/06 16:19:39 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_CGI_HPP
# define CLS_CGI_HPP

#include "../mainprocess/Webserv.hpp"
class clsCGI
{
        clsData Data;
        pid _PIDCHILD;
        bool _IsRunCGI;
        long long _StartTime;
        int _FD;
        
    public:
        long long GetCurrentTime();
        char **MakeEnv(class RequestHandler);
        int RunCGI(std::string NameFile, clsData Data, int TimeOut);
}

#endif
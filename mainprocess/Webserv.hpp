/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:22:46 by achamdao          #+#    #+#             */
/*   Updated: 2026/01/20 10:18:48 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEBSERV_HPP
# define WEBSERV_HPP
enum eMod{STATIC, ERROR, UPLOAD,AUTOINDEX, DIRECTION, DELETE, CHUNK, CGI}; 
#include "../response/clsErrorPage.hpp"
#include "../response/clsResponse.hpp"
#include "../cgi/clsParseOutCGI.hpp"
#include "clsMainProcess.hpp"
#include "../cgi/clsCGI.hpp"
#include "../helperfunction/HelperString.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <map>

#endif
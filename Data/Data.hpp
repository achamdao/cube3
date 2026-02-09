/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:23:20 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/09 17:29:47 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP
# define DATA_HPP

#include "../mainprocess/Webserv.hpp"

class LocationConfig 
{
    public:
    std::string                  path;
    std::string                  root;
    int                     allow_methods;
    bool                    autoindex;
    int                     return_status = 0;
    std::string                  return_url;
    std::string                  upload_store;
    std::map<std::string, std::string> cgi_extension;
    std::string                        extension;
    std::vector<std::string>     index;
};

class ServerConfig 
{
    public:
    std::vector<int>        listen;
    std::string                  host;
    int                     s_addr;
    std::vector<std::string>          server_name;
    std::string                  root;
    std::vector<std::string>     index;
    size_t                  client_max_body_size;
    std::map<int, std::string>   error_page;
    std::vector<LocationConfig> locations;
};
std::vector<ServerConfig> servers;

class Data
{
    public:
    LocationConfig OLocationConfig;
    ServerConfig ConfigFile;
};

#endif
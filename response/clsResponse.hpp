/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:25 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/08 18:20:48 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_RESPONSE_HPP
# define CLS_RESPONSE_HPP
#include "../mainprocess/Webserv.hpp"

class clsResponse
{
    private:
        short _Mod;
        int _Status;
        clsErrorPage ErrorPage;
        int _Fd;
    public:
        std::string MakeResponse(std::string Type, size_t Size, std::string Body);
        std::string HeadersErrorResponse(std::string Type, size_t Size);
        std::string InitialHeaders(std::string Type, size_t Size);
}
#endif
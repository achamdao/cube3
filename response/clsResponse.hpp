/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:25 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/08 18:44:46 by achamdao         ###   ########.fr       */
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
        std::map <std::string, std::string> HeaderFeild;
        int _Fd;
    public:
        std::string MakeResponse(std::string Type, size_t Size, std::string Body);
        std::string HeadersErrorResponse(std::string Type, size_t Size);
        std::string InitialHeaders(std::string Type, size_t Size);
        bool IsTransfer_Encoding();
        bool ContentLength();
        bool Status();
        bool Connection();
        bool ContentType();
        bool Redirction();
}
#endif
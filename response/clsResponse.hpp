/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:25 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/10 15:15:46 by achamdao         ###   ########.fr       */
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
        int _BodySize;
        std::string _Body;
        std::string _Type;
        clsErrorPage _ErrorPage;
        std::vector <std::string> _HeaderFeild;
        int _Fd;
    public:
        clsResponse();
        std::string MakeResponse();
        std::string InitialHeaders();
        void Status();
        void ContentLength();
        void ContentType();
        void Connection();
        void Redirction();
        void Transfer_Encoding();
        void StoredInFileOrStr();
        void Date();
        ~clsResponse();

};
#endif
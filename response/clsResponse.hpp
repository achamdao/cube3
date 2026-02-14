/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:25 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/14 18:51:29 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_RESPONSE_HPP
# define CLS_RESPONSE_HPP

#include "../mainprocess/librarys.hpp"
#include "../response/clsErrorPage.hpp"

class clsResponse
{
    private:
        std::map <short, short> _Mod;
        int _Status;
        int _BodySize;
        bool _Connection;
        std::string _Body;
        std::string _Type;
        clsErrorPage _ErrorPage;
        std::vector <std::string> _HeaderFeild;
        std::string  _FileName;
    public:
        clsResponse();
        std::string MakeResponse();
        void InitialHeaders();
        void Status();
        void ContentLength();
        void ContentType();
        void ConnectionKeepAlive();
        void ConnectionClose();
        void Redirction();
        void Transfer_Encoding();
        void StoredInFileOrStr();
        void Date();
        void CachControl();
        void Server();
        void RetryAfter();
        void Allow();
        std::string ErrorRespnseHandling();
        std::string ChunkData(const std::string &Str);
        ~clsResponse();

};
#endif
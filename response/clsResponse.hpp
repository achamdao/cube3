/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsResponse.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:39:25 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/12 16:39:56 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_RESPONSE_HPP
# define CLS_RESPONSE_HPP

#include "../mainprocess/librarys.hpp"
#include "../response/clsErrorPage.hpp"

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
        std::string  _FileName;
    public:
        clsResponse();
        std::string MakeResponse();
        void InitialHeaders();
        void Status();
        void ContentLength();
        void ContentType();
        void Connection();
        void Redirction();
        void Transfer_Encoding();
        void StoredInFileOrStr();
        void Date();
        void CachControl();
        void Server();
        void RetryAfter();
        void Allow();
        std::string ChunkData(const std::string &Str);
        ~clsResponse();

};
#endif
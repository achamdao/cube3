/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsErrorPage.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:33:05 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/16 21:56:14 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_ERROR_PAGE_HPP
# define CLS_ERROR_PAGE_HPP

#include "../mainprocess/librarys.hpp"

class clsErrorPage
{
    private:
        int _Status;
        std::string _Type;
        std::map<int, std::string> _Message;
        std::map<int, std::string> _Body;

        std::string HeadersErrorResponse(std::string Type, size_t Size);
        void StoredBodys();
        void StoredMessage();
        void Allow();
    public:
        void SetType(std::string Type);
        std::string GetType();
        std::string GetStatusMessage(int StatusCode);
        std::string GetBody(int StatusCode);
        clsErrorPage();
        std::string ResponseError(int Status);
};
#endif

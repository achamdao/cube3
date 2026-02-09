/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsErrorPage.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:33:05 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/09 20:06:12 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_ERROR_PAGE_HPP
# define CLS_ERROR_PAGE_HPP

#include <iostream>
#include <sstream>
#include <map>

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
    public:
        void SetType(std::string Type);
        std::string GetType();
        std::string GetStatusMessage(int StatusCode);
        std::string GetBody(int StatusCode);
        clsErrorPage();
        std::string ResponseError(int Status);
};
#endif

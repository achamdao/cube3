/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsType.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:27:51 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/15 11:32:16 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_TYPE_HPP
# define CLS_TYPE_HPP

#include "../mainprocess/librarys.hpp"
#include "../response/clsErrorPage.hpp"

class clsType
{
    private:
        short _Status;
        std::map <std::string, std::string> _Type;
        std::string  _FileName;
    public:
        clsType();
        std::string GetType(std::string Type)
        {
            if (_Type.count(Type))
                return (_Type[Type]);
            return "";
        }
        ~clsType();

};
#endif
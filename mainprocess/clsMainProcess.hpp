/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsMainProcess.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achamdao <achamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:40:27 by achamdao          #+#    #+#             */
/*   Updated: 2026/02/10 19:03:42 by achamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLS_MAIN_PROCESS_HPP
# define CLS_MAIN_PROCESS_HPP

class clsMainProcess
{
    clsResponse Response;
    clsParseOutCGI ParseOutCGI;
    clsCGI CGI;
    Data Data;
    int _Status;
    short _Mod;
    public:
        void PartRedirection();
        void PartPermission();
        void PartCGI();
        void PartDeleteMethod();
        void PartPOSMethod();
        void MakeOutoIndex(std::string NamesFiles);
        void PartNormalResponse();
        void MainProcess();
};
#endif


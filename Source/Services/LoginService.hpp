/*
    JellyfinNX
    Copyright (C) 2020 Nichole Mattera

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>

namespace JellyfinNX::Service {
    class LoginService {
        public:
            // Config
            static std::string getHost();
            static std::string setHost(std::string host);
            static std::string getUsername();
            static std::string setUsername(std::string username);

            // Validation
            static bool validateHost(std::string host);
            static std::string cleanHost(std::string host);
            static bool validateUsername(std::string username);
            static bool validatePassword(std::string password);

            // Web Calls
            static void * authenticateByName(std::string host, std::string username, std::string password);

        private:
            LoginService() {}
            ~LoginService() {}

    };
}

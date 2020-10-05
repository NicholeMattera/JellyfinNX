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

#include "./LoginService.hpp"

namespace JellyfinNX::Service {
    std::string LoginService::getHost() {
        // TODO: Read host from config file.
        return "";
    }

    std::string LoginService::setHost(std::string host) {
        // TODO: Write host to config file.
        return "";
    }

    std::string LoginService::getUsername() {
        // TODO: Read username from config file.
        return "";
    }

    std::string LoginService::setUsername(std::string username) {
        // TODO: Write username to config file.
        return "";
    }

    bool LoginService::validateHost(std::string host) {
        // TODO: Validate host is an IP Address or URL.
        return true;
    }

    std::string LoginService::cleanHost(std::string host) {
        // TODO: Standarize host names to always have 'http://' or 'https://' at the beginning.
        return "";
    }

    bool LoginService::validateUsername(std::string username) {
        // TODO: Check if there are any further validation concerns.
        return username.length() != 0;
    }

    bool LoginService::validatePassword(std::string password) {
        // TODO: Check if there are any further validation concerns.
        return password.length() != 0;
    }

    void * LoginService::authenticateByName(std::string host, std::string username, std::string password) {
        // TODO: Implement CURL call.
        return NULL;
    }
}

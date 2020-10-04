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

#include <borealis.hpp>
#include <string>

class SetupFrame : public brls::AppletFrame
{
    public:
        SetupFrame();
		~SetupFrame() {}

        void willAppear(bool resetState = false) override;

    private:
        void _serverURLItemClicked();
        void _usernameItemClicked();
        void _passwordItemClicked();
        void _loginButtonClicked();

        brls::BoxLayout * _mainLayout;
        brls::List * _setupList;
        brls::ListItem * _serverURLItem;
        brls::ListItem * _usernameItem;
        brls::ListItem * _passwordItem;
        brls::Rectangle * _dividerRectangle;
        brls::ListItem * _loginItem;

        std::string _serverURL;
        std::string _username;
        std::string _password;
};
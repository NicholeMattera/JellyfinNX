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

#include <switch.h>

#include "SetupFrame.hpp"

using namespace brls::i18n::literals;

SetupFrame::SetupFrame() : AppletFrame(true, true) {
    this->_serverURL = "https://";
    this->_username = "";
    this->_password = "";

    this->setTitle("main/name"_i18n);
    this->setIcon("romfs:/icon.png");

    this->_mainLayout = new brls::BoxLayout(brls::BoxLayoutOrientation::VERTICAL);
    this->_mainLayout->setMargins(0, 200, 0, 200);

    this->_setupList = new brls::List();
    this->_mainLayout->addView(_setupList, true);

    this->_serverURLItem = new brls::ListItem("main/login/server_url"_i18n);
    this->_serverURLItem->setValue(this->_serverURL);
    this->_serverURLItem->getClickEvent()->subscribe(std::bind(&SetupFrame::_serverURLItemClicked, this));
    this->_setupList->addView(this->_serverURLItem);

    this->_usernameItem = new brls::ListItem("main/login/username"_i18n);
    this->_usernameItem->setValue(this->_username);
    this->_usernameItem->getClickEvent()->subscribe(std::bind(&SetupFrame::_usernameItemClicked, this));
    this->_setupList->addView(this->_usernameItem);

    this->_passwordItem = new brls::ListItem("main/login/password"_i18n);
    this->_passwordItem->setValue(this->_password);
    this->_passwordItem->getClickEvent()->subscribe(std::bind(&SetupFrame::_passwordItemClicked, this));
    this->_setupList->addView(this->_passwordItem);

    this->_loginItem = new brls::ListItem("main/login/login"_i18n);
    this->_loginItem->getClickEvent()->subscribe(std::bind(&SetupFrame::_loginButtonClicked, this));
    this->_setupList->addView(this->_loginItem);

    this->setContentView(_mainLayout);
}

void SetupFrame::willAppear(bool resetState) {
    this->registerAction("brls/hints/exit"_i18n, brls::Key::B, [] { brls::Application::quit(); return true; });

    // Disable FPS and Exit.
    this->setActionAvailable(brls::Key::MINUS, false);
    this->setActionAvailable(brls::Key::PLUS, false);
}


void SetupFrame::_serverURLItemClicked() {
    SwkbdConfig config;

    swkbdCreate(&config, 0);

    swkbdConfigMakePresetDefault(&config);
    swkbdConfigSetInitialText(&config, this->_serverURL.c_str());
    swkbdConfigSetBlurBackground(&config, true);
    swkbdConfigSetType(&config, SwkbdType_QWERTY);
    swkbdConfigSetStringLenMax(&config, 2000);
    swkbdConfigSetStringLenMaxExt(&config, 1);

    char buffer[2000] = { 0 };

    if (R_SUCCEEDED(swkbdShow(&config, buffer, 2000)) && strlen(buffer) != 0) {
        this->_serverURL = std::string(buffer);
        this->_serverURLItem->setValue(this->_serverURL);
    }

    swkbdClose(&config);
}

void SetupFrame::_usernameItemClicked() {
    SwkbdConfig config;

    swkbdCreate(&config, 0);

    swkbdConfigMakePresetUserName(&config);
    swkbdConfigSetInitialText(&config, this->_username.c_str());
    swkbdConfigSetBlurBackground(&config, true);
    swkbdConfigSetType(&config, SwkbdType_QWERTY);
    swkbdConfigSetStringLenMax(&config, 1024);
    swkbdConfigSetStringLenMaxExt(&config, 1);

    char buffer[1024] = { 0 };

    if (R_SUCCEEDED(swkbdShow(&config, buffer, 1024)) && strlen(buffer) != 0) {
        this->_username = std::string(buffer);
        this->_usernameItem->setValue(this->_username);
    }

    swkbdClose(&config);
}

void SetupFrame::_passwordItemClicked() {
    SwkbdConfig config;

    swkbdCreate(&config, 0);

    swkbdConfigMakePresetPassword(&config);
    swkbdConfigSetInitialText(&config, this->_password.c_str());
    swkbdConfigSetBlurBackground(&config, true);
    swkbdConfigSetType(&config, SwkbdType_QWERTY);
    swkbdConfigSetStringLenMax(&config, 1024);
    swkbdConfigSetStringLenMaxExt(&config, 1);

    char buffer[1024] = { 0 };

    if (R_SUCCEEDED(swkbdShow(&config, buffer, 1024)) && strlen(buffer) != 0) {
        this->_password = std::string(buffer);
        this->_passwordItem->setValue(std::string(this->_password.length(), '*'));
    }

    swkbdClose(&config);
}

void SetupFrame::_loginButtonClicked() {

}
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

#include <borealis.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Frames/Login.hpp"

using namespace brls::i18n::literals;
using namespace JellyfinNX;

int main(int argc, char* argv[])
{
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    brls::i18n::loadTranslations();
    if (!brls::Application::init("main/name"_i18n))
    {
        brls::Logger::error("Unable to init Borealis application");
        return EXIT_FAILURE;
    }

    JellyfinNX::Frame::Login * setupFrame = new JellyfinNX::Frame::Login();
    brls::Application::pushView(setupFrame);
    
    while (brls::Application::mainLoop())
        ;

    return EXIT_SUCCESS;
}

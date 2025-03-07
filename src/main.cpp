// Otreblan website
// Copyright © 2025 Otreblan
//
// aru-web is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// aru-web is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with aru-web.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>

#include <drogon/HttpAppFramework.h>

int main()
{
	drogon::app()
		.addListener("0.0.0.0", 8080)
		.run();

	return 0;
}

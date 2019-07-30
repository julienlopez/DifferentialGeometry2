#pragma once

#include <string>
#include <vector>

namespace Stilla
{

namespace Utils
{

    namespace Strings
    {
        std::wstring trim(std::wstring str);

        std::string trim(std::string str);

        std::vector<std::wstring> split(std::wstring str, wchar_t delimiter);

        std::vector<std::string> split(std::string str, char delimiter);

        bool endsWith(const std::wstring& str, const std::wstring& token);

        bool endsWith(const std::string& str, const std::string& token);

        std::wstring convert(const std::string& str);

        std::string convert(const std::wstring& str);
    }

} // Utils

} // Stilla

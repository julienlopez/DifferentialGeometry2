#include "strings.hpp"

#include <cctype>

#include <boost/algorithm/string.hpp>

namespace
{
template <class STRING> auto split(STRING str, typename STRING::value_type delimiter)
{
    std::vector<STRING> res;
    boost::algorithm::split(res, str, boost::is_any_of(STRING(1, delimiter)));
    return res;
}

template <class STRING> bool endsWith(const STRING& str, const STRING& token)
{
    if(token.size() > str.size()) return false;
    return std::equal(token.rbegin(), token.rend(), str.rbegin());
}

template <class STRING> STRING trim(STRING str)
{
    while(!str.empty() && std::isspace(str.front()))
        str.erase(str.begin());
    while(!str.empty() && std::isspace(str.back()))
        str.erase(--str.end());
    return str;
}
}

namespace Stilla
{

namespace Utils
{

    std::wstring Strings::trim(std::wstring str)
    {
        return ::trim<std::wstring>(str);
    }

    std::string Strings::trim(std::string str)
    {
        return ::trim<std::string>(str);
    }

    std::vector<std::wstring> Strings::split(std::wstring str, wchar_t delimiter)
    {
        return ::split<std::wstring>(str, delimiter);
    }

    std::vector<std::string> Strings::split(std::string str, char delimiter)
    {
        return ::split<std::string>(str, delimiter);
    }

    bool Strings::endsWith(const std::wstring& str, const std::wstring& token)
    {
        return ::endsWith<std::wstring>(str, token);
    }

    bool Strings::endsWith(const std::string& str, const std::string& token)
    {
        return ::endsWith<std::string>(str, token);
    }

    std::wstring Strings::convert(const std::string& str)
    {
        return {str.begin(), str.end()};
    }

    std::string Strings::convert(const std::wstring& str)
    {
        return {str.begin(), str.end()};
    }

} // Utils

} // Stilla

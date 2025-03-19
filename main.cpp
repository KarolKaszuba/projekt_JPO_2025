#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
using namespace std;
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
int main()
{
    try
    {
        net::io_context ioc;
        tcp::resolver resolver(ioc);
        tcp::socket socket(ioc);
        auto const results = resolver.resolve("api.open-meteo.com", "80");
        net::connect(socket, results.begin(), results.end());
http::request<http::string_body> req(http::verb::get,
"/v1/forecast?latitude=52.400276&longitude=16.955308&current=temperature_2m,precipitation
,weather_code,surface_pressure,wind_speed_10m", 11);
req.set(http::field::host, "api.open-meteo.com");
req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
http::write(socket, req);
beast::flat_buffer buffer;
http::response<http::dynamic_body> res;
http::read(socket, buffer, res);
cout << res << endl;
beast::error_code ec;
socket.shutdown(tcp::socket::shutdown_both, ec);
    }
    catch (std::exception const &e)
    {
        cerr << "Wystąpił wyjątek: " << e.what() << endl;
    }
    return 0;
}